# Redis Lua Two Player Scores (C++)

This project demonstrates Redis Lua scripting for updating multiple player scores atomically.

## Objective

Update the scores of two players in Redis.

Rules:

- If a player's score exists, increment it by the provided amount.
- If a player's score does not exist, initialize it with the provided amount.
- Update both players inside a single Lua script execution.

## Redis Concepts Used

- Lua scripting
- EVAL
- GET
- SET
- Atomic updates
- Multiple keys
- Multiple arguments

## Files

- main.cpp
  - Connects to Redis
  - Executes Lua script
  - Prints updated scores

- update_scores.lua
  - Updates player 1 score
  - Updates player 2 score
  - Returns updated values

## Example

Initial:

```text
player1 = 100
player2 = 50

Arguments:

player1 += 25
player2 += 10

Result:

player1 = 125
player2 = 60

If a player does not exist:

player1 = 25
player2 = 10
Learning Outcome

Learn how Redis Lua scripts can update multiple keys atomically in a single server-side operation.