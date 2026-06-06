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

    // TODO: Add UNESCO World Heritage sites to the set 'heritage_sites'
    // Use value 'Great Wall of China', 'Pyramids of Giza', 'Eiffel Tower', 'Great Wall of China'
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "SADD  heritage_sites %s %s %s %s", "Great Wall of China", "Pyramids of Giza", "Eiffel Tower", "Great Wall of China");
    if(reply == NULL)
    {
        redisFree(context);
    };
    freeReplyObject(reply);
    // TODO: Add a line below to retrieve and print all the unique sites from the set 'heritage_sites'
    reply = (redisReply*)redisCommand(context, "SMEMBERS heritage_sites ");
    if(reply -> type == REDIS_REPLY_ARRAY)
    {
        std::cout << "UNESCO World Heritage sites:";
        for(size_t i = 0; i < reply -> elements; i++)
        {
            std::cout << " " << reply->element[i]->str;
        }
        std::cout << std::endl;
    }else {
        std::cerr << "Failed to retrieve members of the set." << std::endl;
    }
    freeReplyObject(reply);
    // Expected Output: Heritage Sites in the set: [Pyramids of Giza, Eiffel Tower, Great Wall of China]
    
    // Free the context
    redisFree(context);

    return 0;
}