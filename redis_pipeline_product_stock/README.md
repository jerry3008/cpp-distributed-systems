# Redis Pipeline Product Stock (C++)

This project demonstrates how to use Redis pipelines in C++ with Hiredis.

## Objective

Set initial values for a product and its stock, then batch multiple Redis commands in a pipeline to update both values together.

## Redis Concepts Used

Redis pipelining allows multiple commands to be sent to Redis without waiting for each response one by one.

This improves efficiency by reducing round-trip time between the client and Redis server.

## Task

The program should:

1. Connect to Redis.
2. Set an initial product value.
3. Set an initial stock value.
4. Use a pipeline to:
   - decrement the stock
   - set the product name to `Laptop`
5. Read pipeline replies.
6. Retrieve and print the final product and stock values.

## Redis Commands Practiced

- `SET`
- `DECR`
- `GET`
- Redis pipelining with Hiredis

## Example

Initial values:

```text
product = Phone
stock = 10
Pipeline updates:

DECR stock
SET product Laptop

Final values:

product = Laptop
stock = 9
Files
main.cpp
Connects to Redis
Sets initial values
Sends pipeline commands
Reads replies
Prints final values
Build
g++ main.cpp -lhiredis -o pipeline_product_stock
./pipeline_product_stock
Learning Outcome

This project shows how Redis pipelines can batch related operations and reduce client-server round trips.