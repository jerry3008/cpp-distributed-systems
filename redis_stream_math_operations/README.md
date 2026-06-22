# Redis Stream Math Operations (C++)

This project demonstrates how to add and process typed events from a Redis Stream using C++ and Hiredis.

## Objective

Add `add` and `sub` events to a Redis Stream named `math_operations`, process each event based on its type, and print the result.

## Redis Concepts Used

- Redis Streams
- XADD
- XRANGE
- Event type processing
- Stream IDs

## Task

The program should:

1. Connect to Redis.
2. Add math operation events to `math_operations`.
3. Read events from the stream.
4. Check each event type.
5. Process:
   - `add`
   - `sub`
6. Print the result.

## Example Events

```text
Example: Operation: add, Operands: 5, 3, Result: 8
                 Operation: sub, Operands: 10, 4, Result: 6

Files
main.cpp
Connects to Redis
Adds stream events
Reads events
Processes math operations
Build
g++ main.cpp -lhiredis -o stream_math_operations
./stream_math_operations
Learning Outcome

Learn how Redis Streams can represent event-driven workflows where each event type triggers different processing logic.