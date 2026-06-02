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

    redisReply* reply;
    reply = static_cast<redisReply*>(redisCommand(context, "RPUSH famous_books %s %s %s", "1984", "To Kill a Mockingbird",  "The Great Gatsby" ));
    freeReplyObject(reply);
    reply = static_cast<redisReply*>(redisCommand(context,"LRANGE famous_books 0 -1"));
    
    if(reply == NULL || reply->type  != REDIS_REPLY_ARRAY)
    {
        redisFree(context);
        return 1;
    }
   
    
    for(int i =0; i < reply -> elements; ++i)
    {
        std::cout<<reply -> element[i] -> str<<" ";
    }
    
    std::cout <<std::endl;
    freeReplyObject(reply);
 
    redisFree(context);

    return 0;
}