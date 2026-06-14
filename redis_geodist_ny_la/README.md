# Redis Geodist New York Los Angeles (C++)

This project demonstrates Redis geospatial indexing using C++ and Hiredis.

## Objective

Connect to Redis, add New York and Los Angeles with their coordinates, calculate the distance between them in miles, and print the result.

## Redis Commands Practiced

- GEOADD
- GEODIST

## Coordinates

New York:

```text
Longitude: -74.0060
Latitude: 40.7128

Los Angeles:

Longitude: -118.2437
Latitude: 34.0522
Workflow
Connect to Redis.
Add New York using GEOADD.
Add Los Angeles using GEOADD.
Calculate distance using GEODIST.
Print distance in miles.
Files
main.cpp
Connects to Redis
Adds city coordinates
Calculates distance
Prints result
Build
g++ main.cpp -lhiredis -o geodist_ny_la
./geodist_ny_la
Learning Outcome

This project demonstrates how Redis geospatial indexes can store coordinates and calculate distances between locations.