# Redis Geodist London Paris (C++)

This project demonstrates Redis geospatial indexing using C++ and Hiredis.

## Objective

Add London and Paris to Redis using `GEOADD`, then calculate the distance between them in kilometers using `GEODIST`.

## Redis Commands Practiced

- GEOADD
- GEODIST

## Example Locations

- London
- Paris

## Workflow

1. Connect to Redis.
2. Add London coordinates.
3. Add Paris coordinates.
4. Calculate distance in kilometers.
5. Print the result.

## Files

- `main.cpp`
  - Connects to Redis
  - Uses GEOADD
  - Uses GEODIST
  - Prints the London-to-Paris distance

## Build

```bash
g++ main.cpp -lhiredis -o geodist_london_paris
./geodist_london_paris
Learning Outcome

This project shows how Redis can store geographic locations and calculate distances between them.