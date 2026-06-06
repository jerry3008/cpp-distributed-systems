# Redis Set Count (C++)

This project demonstrates how to add elements to a Redis Set and count the number of unique elements stored in the set.

## Objective

Store items in a Redis Set and retrieve the total number of unique elements.

## Redis Concepts Used

Redis Sets:

- SADD
- SCARD
- SMEMBERS

## Workflow

1. Connect to Redis.
2. Create a Redis Set.
3. Add multiple elements using SADD.
4. Count elements using SCARD.
5. Display the result.

## Example

Set Name:

favorite_fruits

Values:

- Apple
- Banana
- Orange
- Apple

Expected Count:

3

Because Redis Sets automatically remove duplicates.

## Files

### main.cpp

Contains:

- Redis connection
- SADD operations
- SCARD operation
- Console output

## Build

Using hiredis:

g++ main.cpp -lhiredis -o redis_set_count

./redis_set_count

## Learning Outcome

This project demonstrates how Redis Sets maintain uniqueness and how to retrieve the size of a set efficiently using SCARD.