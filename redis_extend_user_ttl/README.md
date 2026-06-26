# Redis Extend User TTL (C++)

This project demonstrates how to extend the expiration time of user data stored in Redis.

## Objective

Store user data with an expiration time and later extend the remaining TTL (Time To Live) if the key is still active.

## Redis Concepts Used

- Strings
- SET
- GET
- EXPIRE
- TTL
- Key expiration
- Session management

## Task

The program should:

1. Connect to Redis.
2. Store user data with an initial expiration time.
3. Retrieve the current TTL using:

```text
TTL
If the key still has a valid TTL:
Add additional time to the expiration period.
Update the expiration using:
EXPIRE
Retrieve and display the user data.
Example

Initial user:

user:1

Initial TTL:

86400 seconds

Extension:

86400 seconds

New TTL:

172800 seconds
Redis Commands Practiced
SET
GET
TTL
EXPIRE
Files
main.cpp
Connects to Redis
Stores user data
Reads current TTL
Extends expiration time
Retrieves user data
README.md
Project documentation
Build
g++ main.cpp -lhiredis -o extend_user_ttl
./extend_user_ttl
Learning Outcome

Learn how Redis manages key expiration and how applications can extend the lifetime of existing data by reading and updating TTL values.