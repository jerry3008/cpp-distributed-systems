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

    // TODO: Modify the code to use a pipeline
    const int iterations = 100;
    for (int i = 0; i < iterations; ++i) {
        std::string command = "SET key" + std::to_string(i) + " value" + std::to_string(i);
        
        redisAppendCommand(context, command.c_str());
        
    }
    
    void* res;
    redisReply* reply;
    
    for(int i = 0; i < iterations; ++i)
    {
        redisGetReply(context, &res);
        reply= (redisReply*)res;
        
        if(reply -> type == REDIS_REPLY_STATUS)
        {
            std::cout<<reply -> str << std::endl;
        }
        freeReplyObject(reply);
    }

    redisFree(context);

    return 0;
}