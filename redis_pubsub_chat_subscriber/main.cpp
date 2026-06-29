#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>
#include <thread>
#include <atomic>

// Global flag to stop the listener thread
std::atomic<bool> keep_running(true);

// TODO: Implement the message_handler function that takes 'const redisReply* reply' as input
    // TODO: Check if the reply is valid and of type REDIS_REPLY_ARRAY with 3 elements
    // TODO: Extract message data and display in the format "Received message from {user}: {text}"
    
    void message_handler(const redisReply* reply)
    {
        if (reply && reply -> type == REDIS_REPLY_ARRAY && reply -> elements == 3) 
        {
            std::string message_data(reply->element[2]->str); 
            size_t pos = message_data.find(":");
            std::string user = message_data.substr(0, pos);
            std::string text = message_data.substr(pos + 1);
            std::cout << "Received message from " << user << ": " << text << std::endl;
        }else 
        {
            std::cerr<<"unexpected message format or error in reply "<< std::endl;
        }
    }

// Pub/Sub listener function
void run_pubsub(redisContext* context) {
    while (keep_running) {
        redisReply* reply = nullptr;
        if (redisGetReply(context, (void**)&reply) == REDIS_OK) {
            if (reply) {
                // TODO: Call the message_handler function with 'reply' as argument
                message_handler(reply);
                freeReplyObject(reply);
            }
        } else {
            std::cerr << "Error receiving message: " << context->errstr << std::endl;
            break;
        }
    }
}

// TODO: Implement the subscribe_to_channel function that takes 'redisContext* context, const char* channel' as input
    // TODO: Subscribe to the channel 
    // TODO: Return a new std::thread running run_pubsub function passing 'context'
    
   std::thread subscribe_to_channel(redisContext* context, const char* channel)
   {
    redisReply* publish_reply = (redisReply*)redisCommand(context, "SUBSCRIBE  %s", channel);
    freeReplyObject(publish_reply);
    return std::thread(run_pubsub, context);
   }

// main function or other necessary code goes here

int main() {
    // Connect to the Redis server for subscribing
    redisContext* sub_context = redisConnect("127.0.0.1", 6379);
    if (sub_context == nullptr || sub_context->err) {
        if (sub_context) {
            std::cerr << "Connection error (sub): " << sub_context->errstr << std::endl;
        } else {
            std::cerr << "Connection error: can't allocate Redis context (sub)" << std::endl;
        }
        return 1;
    }

    // Connect to the Redis server for publishing
    redisContext* pub_context = redisConnect("127.0.0.1", 6379);
    if (pub_context == nullptr || pub_context->err) {
        if (pub_context) {
            std::cerr << "Connection error (pub): " << pub_context->errstr << std::endl;
        } else {
            std::cerr << "Connection error: can't allocate Redis context (pub)" << std::endl;
        }
        redisFree(sub_context);
        return 1;
    }

    // TODO: Subscribe to a chat channel and store the thread using the subscribe_to_channel function
    std::thread listener_thread = subscribe_to_channel(sub_context, "chat_room");
    // Sleep to allow listener to set up
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Publish messages to the channel
    const char* messages[] = {
        "alice:Hello everyone!",
        "bob:Hi Alice! How are you?",
        "bob:Did you see the latest news?"
    };

    for (const char* msg : messages) {
        std::cout << "Publishing message: " << msg << std::endl;
        redisReply* publish_reply = (redisReply*)redisCommand(pub_context, "PUBLISH chat_room %s", msg);
        if (publish_reply && publish_reply->type == REDIS_REPLY_INTEGER) {
            std::cout << "Message published, number of subscribers that received the message: " << publish_reply->integer << std::endl;
        } else {
            std::cerr << "Failed to publish message or unexpected reply type." << std::endl;
        }
        if (publish_reply) freeReplyObject(publish_reply);
    }

    // TODO: Unsubscribe and stop the listener
    std::cout << "Unsubscribing and stopping listener..." << std::endl;
    keep_running = false;
    redisCommand(sub_context, "UNSUBSCRIBE chat_room");
    listener_thread.join();
    

    // Free the Redis contexts
    redisFree(sub_context);
    redisFree(pub_context);
    std::cout << "Program finished." << std::endl;

    return 0;
}