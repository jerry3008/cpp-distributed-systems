#include <hiredis/read.h>
#include <iostream>
#include <hiredis/hiredis.h>

void add_to_stream(redisContext* context, const std::string& event, int num1, int num2) 
{
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "XADD math_operations * event %s num1 %d num2 %d ", event.c_str(), num1, num2 );
    freeReplyObject(reply);
    // TODO: Implement this function to add events to the 'math_operations' stream
}

void process_stream(redisContext* context) 
{
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "XREAD STREAMS math_operations 0");
    if(reply ->type  == REDIS_REPLY_ARRAY)
    {
        std::cout <<"STREAMS Arithmetics: "<<std::endl;
        for(size_t i = 0; i < reply->elements; i++)
        {
            redisReply* stream = reply ->element[i];
            if(stream -> type == REDIS_REPLY_ARRAY &&  stream -> elements  == 2)
            {
                std::cout << "Stream: " << stream -> element[0] -> str << std::endl;
                
                redisReply* val_IDs = stream -> element[1];
                for (size_t j = 0; j < val_IDs->elements; ++j) 
                {
                    redisReply* val_ID = val_IDs->element[j];
                    if(val_ID -> type == REDIS_REPLY_ARRAY &&  val_ID -> elements  == 2)
                    {
                        std::cout << "  ID: " << val_ID ->element[0]->str << std::endl; 
                        redisReply* fields = val_ID->element[1];
                        int n1, n2;
                        std::string operation;
                        for (size_t k = 0; k < fields->elements; k += 2) 
                        {
                            std::string key = fields->element[k]->str;
                            std::string val = fields->element[k+1]->str;
                           
                            if (key == "event") operation = val;
                            else if (key == "num1") n1 = std::stoi(val);
                            else if (key == "num2") n2 = std::stoi(val);
                            
                        }
                        int result = 0; 
                        if(operation == "add")
                        {
                            result = n1 + n2;
                        }else if (operation == "sub") 
                        {
                            result = n1 - n2;
                        }
                        std::cout << "Operation: " << operation << " Operands: " << n1<<", "<< n2<<", Result: " << result << std::endl;
                    }
                }
            }
        }
        
    } else 
    {
        std::cerr << "Failed to read stream." << std::endl;
    }
    freeReplyObject(reply);

    /*
     TODO: 
     1. Read all events from the 'math_operations' stream using the XREAD command.
     2. Validate the structure of the reply to ensure it contains valid data.
     3. Loop through the messages in the stream:
        a. Extract the fields: 'event', 'num1', and 'num2'.
        b. Ensure each field is not null and properly formatted.
     4. Perform the corresponding operation ('add' or 'sub') based on the 'event' field.
     5. Output the operation and its result in a human-readable format.
        Example: Operation: add, Operands: 5, 3, Result: 8
                 Operation: sub, Operands: 10, 4, Result: 6
     */
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

    add_to_stream(context, "add", 5, 3);
    add_to_stream(context, "sub", 10, 4);

    process_stream(context);
    // Free the context
    redisFree(context);
    return 0;
}