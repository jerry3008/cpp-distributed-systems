# Redis Lua Player XP (C++)

This project demonstrates Redis Lua scripting with Hiredis.

## Objective

Update a player's experience points (XP).

Rules:

- If the player's XP already exists, increment it by the provided value.
- If the player's XP does not exist, initialize it with the provided value.

## Redis Concepts Used

- Lua scripting
- EVAL
- GET
- SET
- INCRBY
- Atomic operations

## Files

- main.cpp
  - Connects to Redis
  - Executes Lua script
  - Prints updated XP

- player_xp.lua
  - Reads player XP
  - Creates or updates XP
  - Returns new XP value

## Example

Initial:

```text
player:xp = 100
increment = 25

Result:

player:xp = 125

If key does not exist:

player:xp = 25
Learning Outcome

Learn how Redis Lua scripts execute multiple operations atomically on the server.