# Redis Product Price Catalog (C++)

This project demonstrates how to store product prices in Redis and retrieve the most expensive product using C++ and Hiredis.

## Objective

Connect to a Redis server, add product prices to a catalog, and retrieve the product with the highest price.

## Redis Concept Used

This project uses Redis Sorted Sets.

Sorted Sets are useful when each item needs a numeric score.

In this project:

- Product name = member
- Product price = score

## Example

```text
Product Catalog:
Laptop -> 1200
Phone -> 850
Headphones -> 200
Monitor -> 400

The most expensive product is:

Laptop
Redis Commands Practiced
ZADD
ZREVRANGE
WITHSCORES
Workflow
Connect to Redis.
Create a sorted set for product prices.
Add products with prices as scores.
Retrieve the highest-priced product.
Print the product name and price.
Files
main.cpp
Connects to Redis
Adds product prices
Retrieves the most expensive product
Prints the result
Build

Using Hiredis:

g++ main.cpp -lhiredis -o product_catalog
./product_catalog
Learning Outcome

This project demonstrates how Redis Sorted Sets can be used to rank items by numeric values such as prices, scores, ratings, or priorities.