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
       redisReply* reply = nullptr;
     // TODO: Use GEOADD to add New York with coordinates (-74.0060, 40.7128)
    reply = (redisReply*)redisCommand(context, "GEOADD locations %f %f %s",  -74.0060,  40.7128, "New York" );
    freeReplyObject(reply);
   // TODO: Use GEOADD to add Los Angeles with coordinates (-118.2437, 34.0522)
    reply = (redisReply*)redisCommand(context, "GEOADD locations %f %f %s",   -118.2437,  34.0522, "Los Angeles" );
    freeReplyObject(reply);
    // TODO: Calculate the distance between New York and Los Angeles in miles
    reply = (redisReply*)redisCommand(context, "GEODIST locations %s %s %s",   "New York",  "Los Angeles", "mi");
    
    if(reply -> type == REDIS_REPLY_STRING || reply -> type == REDIS_REPLY_INTEGER)
    {
        std::cout << "Distance between New York and Los Angeles: " << reply->str << " mi" << std::endl;
    } else {
        std::cout << "Failed to calculate the distance." << std::endl;
    }
    freeReplyObject(reply);
    // Free the context
    redisFree(context);

    return 0;
}



