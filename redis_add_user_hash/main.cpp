#include <cstddef>
#include <iostream>
#include <hiredis/hiredis.h>
#include <string>

void add_user(redisContext* context, int user_id, std::string name, int age, std::string email)
{
    std::string key  =  "user:" + std::to_string(user_id);
    std::string user_data = " name:"+ name + ", age: " + std::to_string(age) +"email: "+ email;
    redisReply* reply;
    reply = (redisReply*)redisCommand(context, "SETEX %s %d %s", key.c_str(), 5, user_data.c_str());
    if(reply == NULL)
    {
        std::cerr<<"Command execution failed"<< std::endl;
        redisFree(context);
    }
    freeReplyObject(reply);
    
}

int main() 
{
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if(context == nullptr || context -> err)
    {
        if (context) 
        {
            std::cout<<"Error connecting to the server"<< context ->errstr <<std::endl;
            redisFree(context);
        } else 
        {
            std::cerr << "Can't allocate redis context" << std::endl;
        }
        return 1;
    }
    add_user(context, 1, "Alice", 30,"alice@example.com");
    return 0;
}