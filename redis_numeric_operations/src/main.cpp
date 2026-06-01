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

    // TODO: Set initial values for 'stars', 'rating', and 'reviews' to 5, 4.5, and 10 respectively
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "SET stars %d", 5);
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "SET rating %f", 4.5);
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "SET reviews %d", 10);
    freeReplyObject(reply);
    // TODO: Decrease 'stars' by 1
    
    redisCommand(context, "DECR stars");
    redisCommand(context, "INCRBYFLOAT rating 0.5");
    redisCommand(context, "INCR reviews ");
    // TODO: Increase 'rating' by 0.5
    
    
    reply = (redisReply*)redisCommand(context, "GET stars");
    if(reply->type == REDIS_REPLY_STRING)
    {
        std::cout<<"stars: "<<reply -> str <<std::endl;
    }
    freeReplyObject(reply);
    // TODO: Increase 'reviews' by 1
    reply = (redisReply*)redisCommand(context, "GET rating");
    if(reply->type == REDIS_REPLY_STRING)
    {
        std::cout<<"rating: "<<reply -> str <<std::endl;
    }
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "GET reviews");
    if(reply->type == REDIS_REPLY_STRING)
    {
        std::cout<<"reviews: "<<reply -> str <<std::endl;
    }
    freeReplyObject(reply);
    // TODO: Retrieve and print the values of 'stars', 'rating', and 'reviews'

    // Free the context
    redisFree(context);

    return 0;
}