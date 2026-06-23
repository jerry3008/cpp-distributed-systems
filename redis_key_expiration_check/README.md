# Redis Key Expiration Check (C++)

This project demonstrates how to create a Redis key with an expiration time, retrieve it before expiration, wait for it to expire, and verify that it no longer exists.

## Objective

Use Redis expiration features to store temporary data and confirm that Redis automatically removes expired keys.

## Redis Concepts Used

- SET
- EXPIRE
- GET
- EXISTS
- TTL
- Key expiration

## Task

The program should:

1. Connect to Redis.
2. Create a key with a value.
3. Set an expiration time for the key.
4. Retrieve and print the value before expiration.
5. Wait for the key to expire.
6. Verify that the key no longer exists.

## Example

```text
session:auth_token = user123_token
expiration = 7 seconds

Before expiration:

active

After expiration:

key no longer exists
Files
main.cpp
Connects to Redis
Sets a key
Applies expiration
Retrieves value
Waits
Checks key existence
Build
g++ main.cpp -lhiredis -o key_expiration_check
./key_expiration_check
Learning Outcome

Learn how Redis key expiration can be used for sessions, temporary tokens, caches, and short-lived data.