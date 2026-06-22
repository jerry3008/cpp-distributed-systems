#include <cstddef>
#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

void add_events_to_stream(redisContext* context) 
{
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "XADD eventstream * event signup user John" );
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "XADD eventstream * event login user Jane" );
    freeReplyObject(reply);
    reply = (redisReply*)redisCommand(context, "XADD eventstream * event logout user John" );
    freeReplyObject(reply);
}

void read_and_print_stream_messages(redisContext* context) 
{
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "XREAD COUNT 2 STREAMS eventstream 0" );
    
    if(reply ->type == REDIS_REPLY_ARRAY)
    {
        std::cout<<"STREAM MESSAGES:"<<std::endl;
        for(size_t i = 0; i< reply->elements; ++i)
        {
            redisReply* stream = reply  -> element[i];
            if(stream -> type == REDIS_REPLY_ARRAY && stream ->elements == 2)
            {
                std::cout <<"STREAM: "<<stream ->element[0]->str <<std::endl;
                redisReply* messages = stream -> element[1];
                for(size_t j = 0; j < messages ->elements; ++j)
                {
                    redisReply* message = messages->element[j];
                    if(message -> type == REDIS_REPLY_ARRAY && message ->elements == 2)
                    {
                       std::cout << "  ID: " << message -> element[0] ->str << std::endl; 
                       redisReply* fields = message -> element[1];
                       for(size_t k = 0; k < fields  -> elements; k += 2)
                       {
                            std::cout << "    "<< fields -> element[k] -> str << ": " << fields ->element[k + 1] -> str <<std::endl;
                       } 
                    }
                }
                
            }
        }
    }else {
        std::cerr <<"Failed to read stream." << std::endl;
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

    // Call functions to add events and read messages
    add_events_to_stream(context);
    read_and_print_stream_messages(context);

    // Free the context
    redisFree(context);

    return 0;
}