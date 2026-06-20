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

    // TODO: Write a Lua script to update the player XP
    const char* script = 
        "         local current = redis.call('get', KEYS[1])             "
        "         if current then               "
        "         current = tonumber(current)           "
        "      redis.call('SET', KEYS[1], current + ARGV[1] )               "
        " return current + ARGV[1]  "
        "   else    "
        "  redis.call('SET', KEYS[1], ARGV[1] )  "
        "   return tonumber(ARGV[1]) "
        "   end ";

    redisReply* reply = (redisReply*)redisCommand(context, "EVAL %s 1 %s %d", script, "player_xp", 20);
    if (reply && reply->type == REDIS_REPLY_INTEGER) {
        std::cout << "New player XP: " << reply->integer << std::endl;
    } else {
        std::cout << "Failed to update player XP." << std::endl;
    }

    freeReplyObject(reply);
    redisFree(context);

    return 0;
}