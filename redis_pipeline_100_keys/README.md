# Redis Pipeline 100 Keys (C++)

This project demonstrates how to use Redis pipelining in C++ with Hiredis to set multiple keys efficiently.

## Objective

Use a Redis pipeline to set 100 key-value pairs and print the results of the pipeline execution.

## Redis Concepts Used

- Redis pipelining
- Batch command execution
- SET command
- Hiredis pipeline replies

## Task

The program should:

1. Connect to Redis.
2. Queue 100 `SET` commands using a pipeline.
3. Send the commands efficiently.
4. Read and print each pipeline reply.

## Example

Keys:

```text
key:1 -> value:1
key:2 -> value:2
key:3 -> value:3
...
key:100 -> value:100

Why Pipeline?

Without pipelining, the client sends one command and waits for one response repeatedly.

With pipelining, the client sends many commands together and then reads the responses afterward.

This reduces network round trips.

Files
main.cpp
Connects to Redis
Queues 100 SET commands
Reads pipeline replies
Prints execution results
Build
g++ main.cpp -lhiredis -o pipeline_100_keys
./pipeline_100_keys
Learning Outcome

This project demonstrates how Redis pipelines improve efficiency when executing many commands in batch.