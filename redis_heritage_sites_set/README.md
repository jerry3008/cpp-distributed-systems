# Redis UNESCO Heritage Sites Set (C++)

This project demonstrates how to use Redis Sets in C++ with Hiredis.

## Objective

Store and retrieve UNESCO World Heritage Sites using a Redis Set named:

heritage_sites

## Redis Concepts Used

Redis Sets store unique values.

Common operations:

- SADD
- SMEMBERS
- SCARD
- SISMEMBER

## Example Sites

- Great Wall of China
- Machu Picchu
- Taj Mahal
- Pyramids of Giza
- Stonehenge

## Workflow

1. Connect to Redis.
2. Create a set named heritage_sites.
3. Add UNESCO heritage sites.
4. Retrieve all sites.
5. Print the results.

## Files

### main.cpp

Contains:

- Redis connection
- SADD operations
- SMEMBERS retrieval
- Console output

## Build

Using hiredis:

g++ main.cpp -lhiredis -o heritage_sites

./heritage_sites

## Learning Outcome

This project demonstrates how Redis Sets can be used to store unique collections of data while automatically preventing duplicates.