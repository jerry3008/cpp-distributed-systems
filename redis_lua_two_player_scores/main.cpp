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

    // Define a Lua script for updating scores
    const char* lua_script =
        "   local current1 = redis.call('get', KEYS[1])  "
        "   local current2 = redis.call('get', KEYS[2])   "
        "   local score1 = tonumber(current1) or 0  "
        "   local score2 = tonumber(current2) or 0  "
        "   score1 = score1 + tonumber(ARGV[1])     "
        "   score2 = score2 + tonumber(ARGV[2])     "
        "   redis.call('set', KEYS[1], score1 )  "
        "   redis.call('set', KEYS[2], score2 )  "
        "   return {score1, score2}  ";
        

    // Execute the Lua script
    redisReply* reply = (redisReply*)redisCommand(context, "EVAL %s 2 %s %s %s %s", lua_script, "player1_score", "player2_score", "5", "3");

    if (reply != nullptr && reply->type == REDIS_REPLY_ARRAY) {
        std::cout << "New scores: " << reply->element[0]->integer << ", " << reply->element[1]->integer << std::endl;
    } else {
        std::cerr << "Failed to execute script" << std::endl;
    }

    freeReplyObject(reply);

    // Free the context
    redisFree(context);

    return 0;
}