# Redis Movie Titles Set (C++)

This project demonstrates how to store and retrieve unique movie titles using Redis Sets and C++.

## Objective

Create a Redis Set named:

movies

Store unique movie titles and retrieve all stored values.

## Redis Concepts Used

Redis Sets provide:

- Unique element storage
- Fast membership checks
- Automatic duplicate prevention

Commands practiced:

- SADD
- SMEMBERS
- SCARD

## Example Movies

- Inception
- Interstellar
- The Dark Knight
- The Matrix
- Avatar

## Workflow

1. Connect to Redis using Hiredis.
2. Create a Redis Set named movies.
3. Add movie titles using SADD.
4. Retrieve all movie titles using SMEMBERS.
5. Print the results.

## Files

### main.cpp

Contains:

- Redis connection logic
- SADD commands
- SMEMBERS retrieval
- Console output

## Build

Using hiredis:

```bash
g++ main.cpp -lhiredis -o movie_titles
./movie_titles


Learning Outcome

This project demonstrates how Redis Sets can be used to store collections of unique values while automatically preventing duplicates.