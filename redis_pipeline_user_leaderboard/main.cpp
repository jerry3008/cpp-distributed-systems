#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

void add_user(redisContext* context, const std::string& user_id, const std::string& data, bool pipeline) 
{
    redisReply* treply;
    
    if(pipeline)
    {
        
        redisAppendCommand(context, "SET user:%s %s", user_id.c_str(), data.c_str());
    }else{
        treply = (redisReply*)redisCommand(context, "SET user:%s %s", user_id.c_str(), data.c_str());
        freeReplyObject(treply);
    }
    
    
    // TODO: Add implementation to set the user data using pipeline if necessary
}

void add_score(redisContext* context, const std::string& user_id, int score, bool pipeline) {
    // TODO: Add implementation to add the user score using pipeline if necessary
   redisReply* treply;
    if(pipeline)
    {
        redisAppendCommand(context, "ZADD leaderboard %d %s", score,  user_id.c_str());
    }else{
        treply = (redisReply*)redisCommand(context, "ZADD leaderboard %d %s", score,  user_id.c_str());
        freeReplyObject(treply);
    }
   
}

int main()
{
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

    const bool pipeline = true;
    add_user(context,"alice", "Alice,30,alice@example.com", pipeline );
   
    add_score(context,"alice", 50, pipeline);
    
    add_user(context,"bob", "Bob,25,bob@example.com", pipeline );
    
    add_score(context,"bob", 80, pipeline);
  
    add_user(context,"charlie", "Charlie,35,charlie@example.com", pipeline );

    add_score(context,"charlie", 70, pipeline);

    
    if (pipeline) 
    {
        
        for (size_t i = 0; i < 6; ++i) 
        {
            redisReply* reply;
            if (redisGetReply(context, (void**)&reply) == REDIS_OK && reply) 
            {
                if (reply->type == REDIS_REPLY_STRING || reply->type == REDIS_REPLY_STATUS) 
                {
                    std::cout << "Result: " << reply->str << std::endl;
                } else if (reply->type == REDIS_REPLY_INTEGER) {
                    std::cout << "Result: " << reply->integer << std::endl;
                }
            }
        }
    }
    redisFree(context);

    return 0;
}