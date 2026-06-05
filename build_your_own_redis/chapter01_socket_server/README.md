# Chapter 01 - Socket Server

## Objective

Learn the fundamentals of TCP socket programming.

## Concepts Learned

* TCP connections
* socket()
* bind()
* listen()
* accept()
* connect()
* close()

## What Was Built

A simple TCP server and TCP client.

The server waits for incoming connections.

The client connects to the server.

When a connection is established, the server prints:

```text
Client Connected
```

## Files

### server.cpp

Creates a listening TCP socket and accepts incoming connections.

### client.cpp

Creates a TCP connection to the server.

## Build

```bash
g++ server.cpp -o server
g++ client.cpp -o client
```

## Run

Terminal 1:

```bash
./server
```

Terminal 2:

```bash
./client
```

## Learning Outcome

This chapter introduces the foundation of all networked applications.

Every Redis command, HTTP request, RPC call, and distributed system starts with a client establishing a TCP connection to a server.

