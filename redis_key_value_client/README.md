# Redis Key Value Client (C++)

A simple C++ client application that connects to a Redis server, stores a key-value pair, and retrieves the stored value.

## Overview

This project demonstrates the fundamentals of communicating with a Redis server from a C++ application.

The application performs the following operations:

1. Connects to a Redis server
2. Stores a key-value pair using SET
3. Retrieves the value using GET
4. Displays the result

## Features

- Redis server connection
- Key-value storage
- Value retrieval
- Error handling
- Modular C++ design
- CMake build configuration

## Project Structure

```text
include/
└── redis_client.hpp

src/
├── main.cpp
└── redis_client.cpp

build/

README.md
CMakeLists.txt
```

## Build

Configure:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build
```

Run:

```bash
./build/redis_key_value_client
```

## Concepts Demonstrated

- Client-server communication
- Redis commands
- Distributed systems fundamentals
- Modern C++ project structure

## Future Improvements

- Multiple key support
- Connection pooling
- Transaction support
- Publish/Subscribe messaging
- Distributed cache implementation

## Author

Jerry Gbemudu