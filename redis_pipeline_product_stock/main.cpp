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

    // TODO: Set initial values for 'product' and 'stock' to empty string and 10, respectively.
    redisReply* reply;
    
    reply = (redisReply*)redisCommand(context, "SET product %s", " ");
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "SET stock %d", 10);
    freeReplyObject(reply);
    
    redisAppendCommand(context, "SET product %s", "Laptop");
    redisAppendCommand(context, "DECRBY stock %d", 1);
    
    void* res = nullptr;
    redisGetReply(context, &res);
    reply = (redisReply*)res;
    if(reply->type == REDIS_REPLY_STATUS)
    {
        std::cout<<"Product set successfully: "<<reply ->str <<std::endl;
    }
    freeReplyObject(reply);
    
    
    redisGetReply(context, &res);
    reply = (redisReply*)res;
    if(reply -> type == REDIS_REPLY_INTEGER)
    {   
        std::cout<<"Stock completed Decremented to: "<<reply ->integer <<std::endl;
    }
    freeReplyObject(reply);
    
    
    reply = (redisReply*)redisCommand(context, "GET product");
    if(reply -> type == REDIS_REPLY_STRING)
    {
        std::cout<<"Product: "<<reply ->str <<std::endl;
    }
    freeReplyObject(reply);
    
    
    reply = (redisReply*)redisCommand(context, "GET stock");
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
        std::cout<<"Product: "<<reply ->integer <<std::endl;
    }
    freeReplyObject(reply);
    
    redisFree(context);

    return 0;
}