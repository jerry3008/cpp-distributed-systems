#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>
#include <sstream>
#include <string>

// TODO: Define a function `update_points` that takes three parameters: `redisContext* context`, `int user_id` and `int points`
// Inside the function, implement the following in a loop:
// - Use the `redisCommand` function with the "WATCH" command to monitor the key `points:{user_id}`
// - Retrieve the current points with the "GET" command
// - Use the `MULTI` command to begin the transaction
// - Update the points by adding the given `points` to the current points using the "SET" command
// - Execute the transaction using the "EXEC" command
// - Ensure all operations succeed before releasing watch

void update_points(redisContext* context, int user_id, int points)
{
    while (true) 
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "WATCH points:%d", user_id);
        freeReplyObject(reply);
        
        reply = (redisReply*)redisCommand(context, "GET points:%d", user_id);
        if(reply -> type == REDIS_REPLY_STRING)
        {
            std::cout << "THE current points for Post:"<< reply ->str<<std::endl;
        }
        int currPoint = (reply -> type == REDIS_REPLY_NIL) ? 0 : std::stoi(reply -> str);
        freeReplyObject(reply);
        reply = (redisReply*)redisCommand(context, "MULTI");
        freeReplyObject(reply);
        
        reply = (redisReply*)redisCommand(context, "SET points:%d %d", user_id, currPoint + points);
        freeReplyObject(reply);
        
        
        reply = (redisReply*)redisCommand(context, "EXEC");
        if(reply -> type == REDIS_REPLY_ARRAY && reply -> elements == 1)
        {
            freeReplyObject(reply);
            break;
        }
        std::cerr << "Retrying transaction due to an external modification." << std::endl;
        freeReplyObject(reply);
    }
}

int main() {
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if (context == nullptr || context->err) {
        if (context) {
            std::cerr << "Connection error: " << context->errstr << std::endl;
        } else {
            std::cerr << "Connection error: can't allocate Redis context" << std::endl;
        }
        return 1;
    }

    // Set initial points
    redisReply* reply = (redisReply*)redisCommand(context, "SET %s %d", "points:2", 200);
    freeReplyObject(reply);

    // Update points
    // TODO: Call update_points with the correct parameters
    update_points(context, 2, 30);

    // Get updated points
    reply = (redisReply*)redisCommand(context, "GET %s", "points:2");
    if (reply->type == REDIS_REPLY_STRING) {
        std::cout << "Updated points for user 2: " << reply->str << std::endl;
    }
    freeReplyObject(reply);

    redisFree(context);
    return 0;
}