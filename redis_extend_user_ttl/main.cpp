#include <iostream>
#include <hiredis/hiredis.h>

void add_user(redisContext* context, int user_id, const std::string& name, int age, const std::string& email) {
    std::string key = "user:" + std::to_string(user_id);
    std::string value = name + "|" + std::to_string(age) + "|" + email;
    redisCommand(context, "SET %s %s EX %d", key.c_str(), value.c_str(), 86400);
}

std::string get_user(redisContext* context, int user_id) {
    std::string key = "user:" + std::to_string(user_id);
    redisReply* reply = (redisReply*)redisCommand(context, "GET %s", key.c_str());
    
    std::string user_data;
    if (reply->type == REDIS_REPLY_STRING) {
        user_data = reply->str;
    }
    freeReplyObject(reply);
    return user_data;
}

    
void extend_user_ttl(redisContext* context, int user_id, int incr)
{
    std::string user_key = "user:"+ std::to_string(user_id);
    
    redisReply* reply = (redisReply*)redisCommand(context, "TTL %s ", user_key.c_str());
    
    if(reply -> integer  > 0)
    {
        int newTime = reply->integer + incr;
        freeReplyObject(reply);
        reply = (redisReply*)redisCommand(context, "EXPIRE %s %d", user_key.c_str(), newTime);
    }
    freeReplyObject(reply);
}

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

    // User data
    add_user(context, 1, "Alice", 30, "alice@example.com");

    extend_user_ttl(context, 1, 86400);

    
    std::cout << "User 1 data: " << get_user(context, 1) << std::endl;

   
    redisFree(context);

    return 0;
}