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

    // TODO: Add location for London (longitude: -0.127758, latitude: 51.507351) to the 'locations' key
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "GEOADD locations %f %f %s",  -0.127758,  51.507351, "London" );
    freeReplyObject(reply);
    // TODO: Add location for Paris (longitude: 2.352222, latitude: 48.856614) to the 'locations' key
    reply = (redisReply*)redisCommand(context, "GEOADD locations %f %f %s",   2.352222,  48.856614, "Paris" );
    freeReplyObject(reply);
    // TODO: Calculate the distance between London and Paris in kilometers
    reply = (redisReply*)redisCommand(context, "GEODIST locations %s %s %s",   "London",  "Paris", "km");
    
    if(reply -> type == REDIS_REPLY_STRING || reply -> type == REDIS_REPLY_INTEGER)
    {
        std::cout << "Distance between London and Paris: " << reply->str << " km" << std::endl;
    } else {
        std::cout << "Failed to calculate the distance." << std::endl;
    }
    freeReplyObject(reply);
    // Free the context
    redisFree(context);

    return 0;
}