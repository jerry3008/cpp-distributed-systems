#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

void update_likes(redisContext *context, int post_id, int increment) {
    while (true) 
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "WATCH likes:%d", post_id);
        freeReplyObject(reply);
        reply = (redisReply*)redisCommand(context, "GET likes:%d", post_id);
        if(reply -> type == REDIS_REPLY_STRING)
        {
            std::cout << "THE current likes for Post:"<< reply ->str<<std::endl;
        }
        int likes =(reply->type == REDIS_REPLY_NIL) ? 0 :std::stoi(reply -> str);
        freeReplyObject(reply);
        reply = (redisReply*)redisCommand(context, "MULTI");
        freeReplyObject(reply);
        
        reply = (redisReply*)redisCommand(context, "SET likes:%d %d", post_id, likes + increment );
        freeReplyObject(reply);
        
         reply = (redisReply*)redisCommand(context, "EXEC");
        if(reply -> type ==REDIS_REPLY_ARRAY && reply->elements == 1)
        {
            freeReplyObject(reply);
            break; // Transaction succeeded
        }
        std::cerr << "Retrying transaction due to an external modification." << std::endl;
        freeReplyObject(reply);
        
    }
}

int main() {
    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context == nullptr || context->err) {
        if (context) {
            std::cerr << "Connection error: " << context->errstr << std::endl;
        } else {
            std::cerr << "Connection error: can't allocate Redis context" << std::endl;
        }
        return 1;
    }

    redisReply *reply = (redisReply *)redisCommand(context, "SET likes:99 %d", 150);
    freeReplyObject(reply);

    update_likes(context, 99, 15);

    reply = (redisReply *)redisCommand(context, "GET likes:99");
    if (reply->type == REDIS_REPLY_STRING) {
        std::cout << "Updated likes for post 99: " << reply->str << std::endl;
    }
    freeReplyObject(reply);

    redisFree(context);
    return 0;
}