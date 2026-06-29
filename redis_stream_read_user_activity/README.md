# Redis Stream Read User Activity (C++)

This project demonstrates how to write and read user activity entries from a Redis Stream using C++ and Hiredis.

## Objective

Add user activity data to a Redis Stream and implement a function that reads stream entries from the beginning.

## Redis Concepts Used

- Redis Streams
- XADD
- XRANGE
- Stream IDs
- Hiredis command execution

## Task

The program should:

1. Connect to Redis.
2. Add user activity records to a stream.
3. Add user scores.
4. Implement `read_from_stream`.
5. Read entries from the stream starting from the beginning.
6. Print the stream entries.

## Example Stream

Stream name:

```text
user_activity_stream

Example entries:

alice   -> Alice:30:alice@example.com
bob     -> Bob:25:bob@example.com
charlie -> Charlie:35:charlie@example.com
Files
main.cpp
Connects to Redis
Adds users and scores
Reads stream entries
Build
g++ main.cpp -lhiredis -o stream_read_user_activity
./stream_read_user_activity
Learning Outcome

This project demonstrates how Redis Streams can store ordered activity events and how to read those entries from the beginning of the stream.