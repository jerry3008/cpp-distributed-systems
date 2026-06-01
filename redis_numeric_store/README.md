# Redis Numeric Store (C++)

A C++ project that demonstrates how to connect to a Redis server, store numeric values, retrieve them, decode them into native C++ types, and display the results.

## Overview

Redis stores data as strings. In this project, numeric values are written to Redis and later retrieved and converted back into C++ numeric types such as integers and floating-point values.

This exercise introduces the fundamentals of interacting with Redis from a C++ application and handling data serialization and deserialization.

## Features

- Connect to a Redis server
- Store numeric values using Redis SET commands
- Retrieve values using Redis GET commands
- Convert Redis string data to C++ numeric types
- Display decoded values
- Basic error handling
- Modular project structure

## Project Structure

```text
redis_numeric_store/
│
├── include/
│   └── redis_client.hpp
│
├── src/
│   ├── main.cpp
│   └── redis_client.cpp
│
├── build/
│
├── README.md
├── CMakeLists.txt
└── .gitignore
```

## How It Works

The application performs the following steps:

1. Establishes a connection to a Redis server.
2. Stores one or more numeric values.
3. Retrieves the stored values.
4. Converts the retrieved strings into numeric types.
5. Prints the results to the console.

## Example Workflow

```text
Connect to Redis
        ↓
Store Numeric Values
        ↓
Retrieve Values
        ↓
Decode to C++ Types
        ↓
Display Results
```

## Technologies Used

- C++17
- Redis
- Redis++ (redis-plus-plus)
- STL
- CMake

## Build Instructions

### Configure

```bash
cmake -S . -B build
```

### Build

```bash
cmake --build build
```

### Run

```bash
./build/redis_numeric_store
```

## Learning Objectives

- Redis client-server communication
- Key-value storage concepts
- Numeric data encoding and decoding
- C++ string conversion utilities
- Distributed systems fundamentals

## Future Improvements

- Store arrays of numeric values
- Batch retrieval operations
- Transaction support
- Publish/Subscribe messaging
- Connection pooling
- Performance benchmarking

## Author

Jerry Gbemudu