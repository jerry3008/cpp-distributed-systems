# Redis List of Famous Books (C++)

This project demonstrates how to work with Redis Lists using C++.

## Objective

Connect to a Redis server, store several famous book titles inside a Redis list, retrieve the list contents, and display them.

## Redis Concepts Used

### Lists

Redis Lists are ordered collections of strings.

Common operations:

- LPUSH
- RPUSH
- LRANGE
- LPOP
- RPOP

## Workflow

1. Connect to Redis
2. Create a list named:

```text
famous_books

Insert several book titles
Retrieve all titles using LRANGE
Print results to the console

The Great Gatsby
1984
To Kill a Mockingbird
Pride and Prejudice
Moby Dick
Files
main.cpp
Redis connection
RPUSH operations
LRANGE retrieval
Console output
Build

Example using hiredis:

g++ main.cpp -lhiredis -o redis_books
./redis_books
Learning Outcome

This project demonstrates:

Redis list operations
Redis client communication
Ordered data storage
Basic distributed storage concepts