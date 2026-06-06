#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

int main() {
    // Connect to the Redis server
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if (context == nullptr || context->err) {
        if (context) {
            std::cerr << "Connection error: " << context->errstr << std::endl;
        } else {
            std::cerr << "Connection error: can't allocate Redis context" << std::endl;
        }
        return 1;
    }

    // Add elements to the set
    redisReply* reply = (redisReply*)redisCommand(context, "SADD cities NewYork LosAngeles Chicago NewYork");
    freeReplyObject(reply);

    // TODO: Get the number of cities in the set
    // hint: use SCARD command
    reply = (redisReply*)redisCommand(context, "SCARD cities");
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
        std::cout << "Number of cities in the set: "<< reply ->integer << std::endl;
    }
    freeReplyObject(reply);
    

    // TODO: Remove 'Chicago' from the set 'cities'
    // hint: use SREM command
    reply = (redisReply*)redisCommand(context, "SREM cities %s", "Chicago");
    freeReplyObject(reply);
    // TODO: Get the number of cities in the set after removal
    // hint: use SCARD command after SREM
    reply = (redisReply*)redisCommand(context, "SCARD cities");
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
        std::cout << "Number of cities in the set after removal: " << reply ->integer <<  std::endl; 
    }
    freeReplyObject(reply);
   

    // Free the context
    redisFree(context);

    return 0;
}