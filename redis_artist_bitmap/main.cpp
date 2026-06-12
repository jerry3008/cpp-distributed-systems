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

    // Set bits to track whether specific artists are online
    redisReply* reply = (redisReply*)redisCommand(context, "SETBIT artist_online 0 1");
    freeReplyObject(reply);

    // TODO: Set bits to track if the artists are online in the bitmap 'artist_online' for 2 more artists with IDs 1 and 2 and set them to 1 and 0 respectively
    reply = (redisReply*)redisCommand(context, "SETBIT artist_online 1 1");
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "SETBIT artist_online 2 0");
    freeReplyObject(reply);
    int artist_0_online;
    int artist_1_online;
    // TODO: Get and print the status of two artists with IDs 0 and 1
    reply = (redisReply*)redisCommand(context, "GETBIT artist_online 0");
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
        artist_0_online = reply -> integer;
    }
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "GETBIT artist_online 1");
    if(reply -> type == REDIS_REPLY_INTEGER)
    {
        artist_1_online = reply -> integer;
    }
    freeReplyObject(reply);

    std::cout << "Artist 0 online: " << artist_0_online << ", Artist 1 online: " << artist_1_online << std::endl;

    // Free the context
    redisFree(context);

    return 0;
}