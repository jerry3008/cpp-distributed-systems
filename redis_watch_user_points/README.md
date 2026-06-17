# Redis Watch User Points (C++)

This project demonstrates how to use Redis WATCH with C++ and Hiredis to safely update user points.

## Objective

Update a user's points only if the monitored Redis key remains unchanged during the transaction.

If another client modifies the key before the transaction completes, the update should retry until it succeeds.

## Redis Concepts Used

- WATCH
- GET
- MULTI
- SET
- EXEC
- UNWATCH
- Optimistic locking
- Retry logic

## Task

The program should:

1. Connect to Redis.
2. Watch the user's points key.
3. Retrieve the current points.
4. Calculate the updated points.
5. Start a transaction using `MULTI`.
6. Queue the updated value using `SET`.
7. Execute the transaction using `EXEC`.
8. Retry if Redis cancels the transaction because the watched key changed.

## Example

Initial value:

```text
user:2:points = 200
Update:

+30 points

Final value:

user:2:points = 230
Why WATCH?

WATCH provides optimistic concurrency control.

It allows Redis to monitor a key and cancel the transaction if another client modifies that key before EXEC.

Files
main.cpp
Connects to Redis
Watches the user points key
Updates points inside a transaction
Retries if the transaction fails
Build
g++ main.cpp -lhiredis -o watch_user_points
./watch_user_points
Learning Outcome

This project demonstrates how Redis transactions can safely update shared values in concurrent environments.