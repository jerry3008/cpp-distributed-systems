# Redis Watch Post Likes (C++)

This project demonstrates how to use Redis WATCH with C++ and Hiredis to safely update post likes.

## Objective

Update the number of likes for a post only if the post's likes key has not been modified by another client during the transaction.

If another client modifies the key, the transaction is retried until it succeeds.

## Redis Concepts Used

- WATCH
- MULTI
- EXEC
- GET
- SET
- Optimistic locking
- Retry logic

## Task

The program should:

1. Connect to Redis.
2. Watch the likes key for a given post.
3. Read the current number of likes.
4. Start a transaction with `MULTI`.
5. Queue the updated likes value.
6. Execute the transaction with `EXEC`.
7. Retry if the transaction fails because another client changed the watched key.

## Example

Initial value:

```text
post:99:likes = 150

After update:

post:99:likes = 165

If another client changes the value before EXEC, Redis cancels the transaction and the function retries.

Redis Commands Practiced
WATCH
GET
MULTI
SET
EXEC
UNWATCH
Learning Outcome

This project demonstrates optimistic concurrency control in Redis using WATCH, allowing safe updates when multiple clients may modify the same key.