# Redis Numeric Operations (C++)

A C++ project demonstrating how to perform numeric operations on Redis keys.

## Overview

This project connects to a Redis server and performs arithmetic operations directly on stored values using Redis commands.

The application demonstrates how Redis can be used as a lightweight and high-performance data store for counters, metrics, and other numeric workloads.

## Features

- Connect to a Redis server
- Store numeric values
- Increment numeric values
- Decrement numeric values
- Retrieve updated values
- Display results
- Basic error handling

## Project Structure

```text
redis_numeric_operations/
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

## Concepts Demonstrated

- Redis INCR command
- Redis DECR command
- Numeric key manipulation
- Client-server communication
- Distributed systems fundamentals

## Technologies

- C++17
- Redis
- Redis++
- STL
- CMake

## Learning Objectives

- Working with Redis numeric data
- Counter-based systems
- Real-time metric tracking
- Distributed caching concepts

## Future Improvements

- Atomic counters
- Rate limiting implementation
- Leaderboards
- Real-time analytics
- Distributed monitoring systems

## Author

Jerry Gbemudu