# Redis Movie Hash (C++)

This project demonstrates how to store and retrieve movie details using a Redis hash in C++.

## Objective

Store details for the movie `Inception` in Redis and retrieve the stored fields.

## Redis Concepts Used

Redis hashes are useful for storing objects with multiple fields.

Example movie fields:

- title
- director
- year
- genre
- rating

## Workflow

1. Connect to a Redis server.
2. Store movie details using a Redis hash.
3. Retrieve the movie details from Redis.
4. Print the retrieved values to the console.

## Redis Commands Practiced

- `HSET`
- `HGET`
- `HGETALL`

## Files

- `main.cpp`
  - Connects to Redis
  - Stores movie details
  - Retrieves movie details
  - Prints output

## Build and Run

Example using hiredis:

```bash
g++ redis_movie_hash/main.cpp -o redis_movie_hash_app -lhiredis
./redis_movie_hash_app
Learning Outcome

This project helps demonstrate how Redis hashes can represent structured data such as movie records in a backend system.