# Redis Travel Destination Hash (C++)

This project demonstrates how to store and retrieve travel destination information using Redis hashes in C++.

## Objective

Store information about a travel destination in Redis and retrieve the stored fields.

## Redis Concepts Used

Redis Hashes

Common commands:

- HSET
- HGET
- HGETALL

## Example Destination Data

Destination: Paris

Fields:

- country
- continent
- language
- population
- attraction

## Workflow

1. Connect to Redis.
2. Store destination information in a Redis hash.
3. Retrieve the stored information.
4. Display the results.

## Files

### main.cpp

Contains:

- Redis connection logic
- Hash creation
- Field retrieval
- Console output

## Build

Using hiredis:

```bash
g++ main.cpp -lhiredis -o travel_destination
./travel_destination
Learning Outcome

This project demonstrates how Redis hashes can be used to represent structured records such as travel destinations, user profiles, products, and other entity-based data.