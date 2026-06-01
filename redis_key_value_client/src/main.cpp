#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

int main() 
{
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if(context == nullptr || context -> err)
    {
        if(context)
        {
            std::cerr << "Connection error: "<<context->errstr<<std::endl;
        }else {
            std::cerr << "Connection error: can't allocate Redis context"<< std::endl;
        }
        return 1;
    }
    redisReply* reply = (redisReply*)redisCommand(context,  "SET city %s", "Gotham");
    freeReplyObject(reply);
    
    reply = (redisReply*)redisCommand(context, "Get city");
    if(reply -> type == REDIS_REPLY_STRING)
    {
        std::cout << "Stored string in Redis: " <<reply -> str << std::endl;
    }else {
        std::cout<<"Failed to retrieve the value." <<std::endl;
    }
    freeReplyObject(reply);
    redisFree(context);

    return 0;
}