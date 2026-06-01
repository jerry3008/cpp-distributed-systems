cmake_minimum_required(VERSION 3.10)

project(redis_key_value_client)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    redis_key_value_client
    src/main.cpp
    src/redis_client.cpp
)