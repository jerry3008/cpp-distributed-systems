#include <cstddef>
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

    // TODO: Add product prices to the catalog 'product_catalog' with the following prices: Laptop: 1200, Smartphone: 800, Tablet: 400, Monitor: 600
    redisReply* reply;
    
    reply = (redisReply*) redisCommand(context, "ZADD product_catalog 1200 Laptop 800 Smartphone 400 Tablet 600 Monitor");
    
    freeReplyObject(reply);
    // TODO: Retrieve the most expensive product based on the prices
    reply = (redisReply*) redisCommand(context, "ZREVRANGE product_catalog 0 0 WITHSCORES");
    // TODO: Print the most expensive product and its price
    if(reply -> type == REDIS_REPLY_ARRAY)
    {
        std::cout << "most expensive product: ";
        for(size_t i = 0;  i < reply -> elements;  i += 2)
        {
            std::cout << "(" <<reply -> element [i]  -> str << ", " << reply -> element[i + 1] -> str << ") ";
        }
        std::cout << std::endl;
    }
    freeReplyObject(reply);
    // Free the context
    redisFree(context);

    return 0;
}