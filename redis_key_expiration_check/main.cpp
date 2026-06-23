#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>
#include <thread>
#include <chrono>

int main() {
    redisContext* context = redisConnect("127.0.0.1", 6379);
    
    if(context == nullptr || context -> err)
    {
        if(context)
        {
            std::cerr << "Connection error: "<<context -> errstr;
        }else{
            std::cerr << "Connection error: can't allocate Redis context" << std::endl;
        }
        return 1;
    }
    
    const char* key = "session:auth_token";
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "SET %s %s EX %d", key,"user123_token", 7);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", key);
    if(reply -> type != REDIS_REPLY_NIL)
    {
         std::cout << reply->str << std::endl;
    } else {
        std::cout << "Unexpected return value." << std::endl;
    }
    freeReplyObject(reply);
        
    std::this_thread::sleep_for(std::chrono::seconds(8));
    
    reply = (redisReply*)redisCommand(context, "GET %s", key);
    if(reply -> type == REDIS_REPLY_NIL)
    {
        std::cout << "Value: None" << std::endl;
    } else {
        std::cout << "Unexpected return value." << std::endl;
    }
    freeReplyObject(reply);

    return 0;
}