# cpp-distributed-systems
C++ distributed systems, Redis, networking, RPC, and infrastructure projects
A collection of distributed systems projects implemented in C++.

This repository focuses on the engineering concepts that power large-scale backend infrastructure, cloud services, messaging systems, distributed storage, and high-performance networked applications.

The goal of this repository is to strengthen understanding of distributed systems fundamentals through practical implementations and hands-on projects.

---

## Topics Covered

### Distributed Storage
- Redis integration
- Key-value stores
- Distributed caching
- Replication concepts
- Persistence strategies

### Networking
- TCP/IP programming
- Socket programming
- Client-server architectures
- Connection management
- Network protocols

### Messaging Systems
- Publish/Subscribe
- Message queues
- Event-driven systems
- Producer-consumer architectures

### Service Communication
- RPC frameworks
- Service discovery
- Load balancing
- API communication

### Reliability
- Fault tolerance
- Retry mechanisms
- Health checks
- Monitoring
- Logging

### Performance
- Latency analysis
- Throughput optimization
- Concurrent request handling
- Resource management

---

# Repository Structure

```text
cpp-distributed-systems/
│
├── README.md
│
├── redis_string_store/
│
├── redis_pub_sub/
│
├── distributed_cache/
│
├── message_queue/
│
├── service_discovery/
│
├── rpc_framework/
│
├── distributed_key_value_store/
│
├── tcp_server/
│
├── tcp_client/
│
└── load_balancer/
```

---

# Current Projects

## Redis String Store

Demonstrates basic Redis integration using C++.

Concepts covered:

- Redis connections
- SET operations
- GET operations
- Key-value storage
- Client-server communication

Folder:

```text
redis_string_store/
```

---

# Skills Demonstrated

- Modern C++
- Object-Oriented Design
- Networking Fundamentals
- Distributed Systems Concepts
- Concurrent Programming
- Infrastructure Engineering
- System Reliability
- Performance Optimization

---

# Future Additions

Planned projects include:

- Redis Pub/Sub
- Distributed Cache
- Service Discovery
- RPC Framework
- Distributed Key-Value Store
- Consistent Hashing
- Distributed Locking
- Load Balancer
- Message Broker
- Monitoring Infrastructure

---

# Build

Most projects can be compiled using:

```bash
g++ main.cpp -o app
```

Some projects may require additional libraries such as:

- Redis client libraries
- Boost
- gRPC
- Protobuf

Project-specific instructions will be provided in each project folder.

---

# Purpose

This repository serves as a learning platform for distributed systems engineering and backend infrastructure development using C++.

The focus is on understanding how large-scale systems communicate, coordinate, store data, and remain reliable under load.
