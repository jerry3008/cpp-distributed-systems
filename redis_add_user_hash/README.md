# Redis Add User Hash (C++)

This project demonstrates how to store user information in Redis using a hash.

## Objective

Create a function that stores user information in Redis using a key of the form:

```text
user:{user_id}

The user record contains:

User ID
Name
Age
Email
Redis Concepts Used
Hashes
HSET
HGET
HGETALL
Structured data storage
Task

The program should:

Connect to Redis.
Create a user record.
Store the user data under:
user:1
Save:
Name
Age
Email
Verify the data was stored successfully.
Example

Key:

user:1

Fields:

name  = Alice
age   = 30
email = alice@example.com

Redis Commands Practiced
SETEX
HSET
HGET
HGETALL

Files
main.cpp
Connects to Redis
Creates a user record
Stores user information in a Redis hash
README.md
Project documentation
Build

g++ main.cpp -lhiredis -o add_user_hash
./add_user_hash
Learning Outcome

Learn how Redis hashes can be used to store structured user information using a single Redis key.

