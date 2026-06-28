# Redis Pipeline User Leaderboard (C++)

This project demonstrates how to use Redis pipelines with C++ and Hiredis to add user details and leaderboard scores efficiently.

## Objective

Modify helper functions so user details and scores can be executed either normally or through a Redis pipeline.

## Redis Concepts Used

- Redis pipelining
- HSET
- ZADD
- Pipeline execution
- Hiredis command batching

## Task

The program should:

1. Connect to Redis.
2. Add user profile details.
3. Add user scores to a leaderboard.
4. Support a `pipeline` argument in helper functions.
5. Queue commands when pipeline mode is enabled.
6. Execute and read pipeline replies after batching commands.

## Example Users

```text
alice   -> Alice,30,alice@example.com   score: 50
bob     -> Bob,25,bob@example.com       score: 80
charlie -> Charlie,35,charlie@example.com score: 70

Files
main.cpp
Connects to Redis
Adds user details
Adds leaderboard scores
Supports pipeline and non-pipeline execution
Build
g++ main.cpp -lhiredis -o pipeline_user_leaderboard
./pipeline_user_leaderboard
Learning Outcome

This project demonstrates how Redis pipelines can batch related operations, reducing round trips between a C++ client and Redis server.