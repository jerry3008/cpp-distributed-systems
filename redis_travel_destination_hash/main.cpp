#include <cstddef>
#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

int main() {
    // TODO: Connect to the Redis server
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if(context == NULL || context -> err)
    {
        if (context) 
        {
            std::cerr << "ERROR: " <<context -> errstr <<std::endl;
            redisFree(context);
        }else {
            std::cerr << "Caan't allocate redis context"<< std::endl;
        }
        return 1;
    }
    // TODO: Store travel destination details using hashes
    // Use the key 'destination:9008' and add fields 'city', 'country', and 'attraction'
    // Use values 'Rome', 'Italy', and 'Colosseum'
    
    redisReply* reply;
    
    const char*  Userkey = "destination:9008";
    reply = (redisReply*) redisCommand(context, "HSET %s city %s country %s attraction %s", Userkey, "Rome", "Italy",  "Colosseum");
    if(reply == NULL)
    {
        redisFree(context);
        return 1;
    }
    freeReplyObject(reply);
    

    // TODO: Retrieve all fields and values of the hash
    reply = (redisReply*) redisCommand(context, "HGETALL %s", Userkey);
    if (reply != NULL && reply->type  == REDIS_REPLY_ARRAY) 
    {
        std::cout << "travel destination: {";
        for(size_t i = 0; i < reply ->elements; i += 2)
        {
            std::cout<<reply -> element[i] ->str << ": "<<reply ->element[i + 1] ->str;
            if( i < reply->elements - 2)
            {
                std::cout << ", ";
            }
        }
        std::cout<<"}"<<std::endl;
    }
    freeReplyObject(reply);
    redisFree(context);

    // TODO: Print the retrieved details

    return 0;
}