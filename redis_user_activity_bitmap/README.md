# Redis User Activity Bitmap (C++)

This project demonstrates how to track user activity using Redis Bitmaps and C++.

## Objective

Store and retrieve user activity status using Redis bits.

## Redis Commands Practiced

- SETBIT
- GETBIT

## Example

User Activity:

Alice -> Active
Bob -> Inactive
Charlie -> Active
David -> Active

Bitmap Representation:

Bit 0 -> Alice
Bit 1 -> Bob
Bit 2 -> Charlie
Bit 3 -> David

Stored Values:

1 0 1 1

## Workflow

1. Connect to Redis.
2. Iterate through a collection of users.
3. Store activity status using SETBIT.
4. Retrieve activity status using GETBIT.
5. Print results.

## Learning Outcome

Learn how Redis Bitmaps efficiently store boolean values using individual bits, making them ideal for tracking online status, attendance, feature flags, and user activity.
