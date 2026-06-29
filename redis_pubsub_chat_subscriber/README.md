# Redis Pub/Sub Chat Subscriber (C++)

This project demonstrates how to subscribe to a Redis Pub/Sub channel and process incoming chat messages using C++ and Hiredis.

## Objective

Build a Redis Pub/Sub subscriber that listens to a chat channel, processes incoming messages, and displays them in a readable format.

## Redis Concepts Used

- Pub/Sub
- SUBSCRIBE
- PUBLISH
- redisGetReply()
- Threads
- Message handling
- Atomic flag for thread shutdown

## Task

The program should:

1. Connect to Redis using a subscriber connection.
2. Connect to Redis using a publisher connection.
3. Subscribe to a chat channel.
4. Start a listener thread.
5. Receive incoming Pub/Sub messages.
6. Parse and display each message.
7. Publish sample chat messages.
8. Unsubscribe and stop the listener gracefully.

## Example Channel

```text
chat_room
```

## Example Messages

```text
alice:Hello everyone!
bob:Hi Alice! How are you?
bob:Did you see the latest news?
```

Example Output:

```text
Received message from alice: Hello everyone!
Received message from bob: Hi Alice! How are you?
Received message from bob: Did you see the latest news?
```

## Files

- `main.cpp`
  - Connects to Redis
  - Subscribes to a Pub/Sub channel
  - Publishes messages
  - Processes incoming messages
  - Stops the listener thread cleanly

## Build

```bash
g++ main.cpp -lhiredis -pthread -o pubsub_chat_subscriber
./pubsub_chat_subscriber
```

## Learning Outcome

This project demonstrates how Redis Pub/Sub enables real-time messaging between publishers and subscribers, while introducing multithreading and asynchronous message handling in C++.