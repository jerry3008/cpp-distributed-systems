# Redis Stream EventStream (C++)

This project demonstrates Redis Streams using C++ and Hiredis.

## Objective

Create a stream named `eventstream`, add three different events, then read and print the first two messages.

## Redis Concepts Used

- Streams
- XADD
- XRANGE
- Stream IDs
- Event processing

## Task

The program should:

1. Connect to Redis.
2. Add three events to `eventstream`.
3. Read the stream.
4. Print the first two messages.

## Example Events

```text
login
purchase
logout

Example Redis commands:

XADD eventstream * event login
XADD eventstream * event purchase
XADD eventstream * event logout

Read:

XRANGE eventstream - +

Print the first two entries returned.

Files
main.cpp
Connects to Redis
Adds stream entries
Reads stream entries
Prints results
Build
g++ main.cpp -lhiredis -o stream_eventstream
./stream_eventstream
Learning Outcome

Learn how Redis Streams store ordered events and how to read them back for processing.