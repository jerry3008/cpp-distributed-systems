#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>
#include <map>
#include <string>

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

    // Dictionary of users
    std::map<std::string, std::pair<int, bool>> users = {
        {"lily", {0, true}},
        {"john", {1, true}},
        {"jane", {2, false}}
    };

    // TODO: Iterate over the users and set their activity status in the bitmap 'user_active'.
    for(const auto& [name, info]: users)
    {
        redisReply* reply; 
       reply = (redisReply*)redisCommand(context, "SETBIT user_active %d %d ", info.first, info.second);
       freeReplyObject(reply);
    }
    // TODO: Retrieve the activity statuses of user 0 and user 2.
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, " GETBIT user_active %d" , 0);
    
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
          std::cout << "User 0 active: " << reply->integer << std::endl; 
    }
    freeReplyObject(reply);
    
    reply = (redisReply*)redisCommand(context, " GETBIT user_active %d" , 2);
    
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
          std::cout << "User 2 active: " << reply->integer << std::endl; 
    }
    freeReplyObject(reply);
   
    redisFree(context);

    return 0;
}