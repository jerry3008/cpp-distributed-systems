#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>
#include <vector>
#include <string>
#include <cstdlib>

void add_user(redisContext* context, const std::string& user_id, const std::string& data) 
{
    redisReply* reply;
    std::string key  = "user:" + user_id;
    reply = (redisReply*)redisCommand(context, "SET %s %s", key.c_str(), data.c_str());
    freeReplyObject(reply);
    // Implement add_user function
}

void add_score(redisContext* context, const std::string& user_id, int score) 
{
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "ZADD leaderboard %d %s",score, user_id.c_str());
    freeReplyObject(reply);
    // Implement add_score function
}

void read_from_stream(redisContext* context, const std::string& stream_name) 
{
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "XREAD STREAMS %s 0", stream_name.c_str());
    if(reply -> type == REDIS_REPLY_ARRAY)
    {
        std::cout << "Stream Messages " << std::endl;
        for(size_t i = 0; i < reply -> elements; ++i)
        {
            redisReply* stream = reply->element[i];
            redisReply* entries = stream->element[1];
            for (size_t j = 0; j < entries->elements; ++j) 
            {
                redisReply* entry = entries->element[j];
                std::cout << "Stream entry ID: " << entry->element[0]->str << std::endl;
                redisReply* entry_data = entry->element[1];
                if (entry_data->type == REDIS_REPLY_ARRAY) 
                {
                    for (size_t k = 0; k < entry_data->elements; k += 2) 
                    {
                        std::cout << "Key: " << entry_data->element[k]->str << ", Value: " << entry_data->element[k+1]->str << std::endl;
                    }
                }
            }
        }
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

    // Stream name for user activities
    std::string stream_name = "user_activity_stream";

    std::vector<std::pair<std::string, std::string>> users = {
        {"alice", "Alice:30:alice@example.com"},
        {"bob", "Bob:25:bob@example.com"},
        {"charlie", "Charlie:35:charlie@example.com"}
    };

    for(const auto& user : users)
    {
        add_user(context, user.first, user.second);
        add_score(context, user.first, std::rand());
        redisCommand(context, "XADD %s * user %s action added", stream_name.c_str(), user.first.c_str());
    }
    read_from_stream(context, stream_name);

    redisFree(context);

    return 0;
}


