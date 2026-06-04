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

    // TODO: Store the movie details using hashes
    // Use the key 'movie:3000' and the fields 'title', 'director', and 'year' with the values 'Inception', 'Christopher Nolan', and 2010 respectively
    
    redisReply* reply;
    const char* userKey = "movie:3000";
    reply = (redisReply*)redisCommand(context, "HSET %s title %s director %s year %s ",userKey, "Inception", "Christopher Nolan",  "2010");
    if (reply == NULL) {
        redisFree(context);
        return 1;
    }
    freeReplyObject(reply);

    // TODO: Retrieve the movie details using the key 'movie:3000'
    reply = (redisReply*)redisCommand(context, "HGETALL %s", userKey);
    if(reply != NULL && reply -> type == REDIS_REPLY_ARRAY)
    {
        std::cout<< "Movie details: {";
        for(size_t i = 0; i < reply -> elements;  i += 2)
        {
            std::cout<<reply->element[i]->str<< ": "<<reply -> element[i + 1] -> str;
            if(i < reply->elements - 2)
            {
                std::cout<<", ";
            }
        }
        std::cout << "}" << std::endl;
    }
    freeReplyObject(reply);
    // Print the movie details in the specified format
    // Example output: "Movie details: { title: Inception, director: Christopher Nolan, year: 2010 }"
    
    

    // Free the context
    redisFree(context);

    return 0;
}