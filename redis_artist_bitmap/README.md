# Redis Artist Bitmap (C++)

This project demonstrates how to use Redis Bitmaps with C++ and Hiredis to track artist online status.

## Objective

Store and retrieve artist activity using Redis bits.

## Redis Commands Practiced

- SETBIT
- GETBIT

## Example

Artist Index Mapping

0 -> Drake
1 -> Taylor Swift
2 -> The Weeknd
3 -> Adele

Status:

Drake = Online
Taylor Swift = Offline
The Weeknd = Online
Adele = Offline

## Workflow

1. Connect to Redis.
2. Set artist status using SETBIT.
3. Retrieve status using GETBIT.
4. Print online/offline results.

## Learning Outcome

Learn how Redis Bitmaps efficiently store boolean values using individual bits instead of full strings.