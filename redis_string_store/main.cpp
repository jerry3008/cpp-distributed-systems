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

    // TODO: Set the key and value pair with the key 'hero' and value 'Iron Man'
    redisReply* reply = (redisReply*)redisCommand(context, "SET hero %s",  "Iron Man");
    freeReplyObject(reply);
    // TODO: Retrieve the value and ensure the print statement decodes the retrieved value correctly
    reply = (redisReply*)redisCommand(context, "GET hero");
    if(reply ->type == REDIS_REPLY_STRING)
    {
         std::cout << "Stored string in Redis: " << reply -> str<< std::endl;
    }
     else 
    {
        std::cout << "Failed to retrieve the value." << std::endl;
    }
    freeReplyObject(reply);
   

    // Free the context
    redisFree(context);

    return 0;
}