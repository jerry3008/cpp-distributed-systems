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

    // TODO: Add unique movie titles to the 'movies' set. Values: 'Inception', 'The Matrix', 'Interstellar', 'Inception'
    redisReply* reply;
    reply = (redisReply*)redisCommand(context,  "DEL movies");
    reply = (redisReply*)redisCommand(context,"SADD  movies  %s %s %s %s", "Inception", "The Matrix", "Interstellar", "Inception");
    if(reply == NULL)
    {
        redisFree(context);
    }
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "SCARD movies");
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
         std::cout << "Number of movies in the set: "<<reply ->integer<<std::endl;
    }
     freeReplyObject(reply);
    
    // TODO: Print the size of the 'movies' set

    // TODO: Print all movie titles from the 'movies' set
    
    reply = (redisReply*)redisCommand(context, "SMEMBERS movies");
    if(reply -> type == REDIS_REPLY_ARRAY)
    {
        std::cout << "movies in the set:";
        for(size_t i = 0; i < reply -> elements; ++i)
        {
            std::cout << " " << reply->element[i]->str;
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Failed to retrieve members of the set." << std::endl;
    }
    freeReplyObject(reply);

    // Free the context
    redisFree(context);

    return 0;
}