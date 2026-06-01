#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

int main() 
{
    // TODO: Connect to the Redis server using the localhost and port 6379
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if(context == NULL || context ->err)
    {
        if(context)
        {
            std::cerr << "ERROR: "<<context->errstr <<std::endl;
        }else {
         std::cerr <<" Can't allocate redis context" << std::endl;
        }
        return -1;
    }
    // TODO: Set numeric values for 'count' and 'completion_rate' in the Redis server with values 5 and 95.5, respectively
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "SET count %d", 5);
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "SET completion_rate %f", 95.5);
    freeReplyObject(reply);

    // TODO: Retrieve the values of 'count' and 'completion_rate' from the Redis server
    reply = (redisReply*)redisCommand(context, "GET count");
    if(reply -> type == REDIS_REPLY_STRING)
    {
        std::cout << "count: "<<reply ->str <<std::endl;
    }
    freeReplyObject(reply);
    
    
    reply = (redisReply*)redisCommand(context, "GET completion_rate");
    if(reply -> type == REDIS_REPLY_STRING)
    {
        std::cout<< "completion_rate : "<<reply -> str <<std::endl;
    }
    freeReplyObject(reply);
    redisFree(context);
    // TODO: Print the retrieved values for 'count' and 'completion_rate'

    // NOTE: Don't forget to free resources and handle any errors

    return 0;
}