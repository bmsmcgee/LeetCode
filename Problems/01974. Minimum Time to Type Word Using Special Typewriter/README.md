# 1974. Minimum Time to Type Word Using Special Typewriter

## Problem

There is a special typewriter with lowercase English letters `'a'` to `'z'` arranged in a **circle** with a **pointer**. A character can **only** be typed if the pointer is pointing to that character. The pointer is **initially** pointing to the character `'a'`.

Each second, you may perform one of the following operations:
 - Move the pointer one character **counterclockwise** or **clockwise**.
 - Type the character the pointer is **currently** on.

Given a string `word`, return the **minimum** number of seconds to type out the characters in `word`.

#### Constraints

 - `1 <= word.length <= 100`
 - `word` consists of lowercase English letters

## Guide

### Step 1: Understand

Each character requires:
 - **Movement time** (to reach it from the current pointer position)
 - **Typing time** (always 1 second per letter)

So for each character in `word`, the total time is:

> `total_time += min(clockwise_distance, counterclockwise_distance) + 1`


### Step 2: Greedy

For each letter:
 - Can move either **counterclockwise** or **clockwise**
 - Since the letters are arranged in a circle, the optimal choice is to **always** take the **shortest path** (i.e., **greedy choice**)

To compute shortest path:
 - Convert letters to **indices**: `'a' -> 0, 'b' -> 1, …, 'z' -> 25`
 - Let `pos` be the current pointer position
 - let `target` be the letter you want to type next
 - Compute:
   - `direct_distance = abs(pos - target)`
   - `circular_distance = 26 - direct_distance`
   - Take the **minimum** of the two
        > `move_time = min(direct_distance, circular_distance)` 

This is the **greedy step**, at each point, take the fastest move to reach the next character.

### Step 3: Initialize State

Start at `'a' -> 0` 

Maintain:
 - `currPos`: current pointer `idx`
 - `totalTime`: running total of seconds

### Step 4: Iterate Through Each Character

for each character, `ch`, in `word`:
  1. Convert `ch` to an `idx` 
  2. Compute both `direct_distance` and `circular_distance` between `currPos` and `ch`
  3. Choose the **smaller distance** as move time
  4. Add **1 second** for typing the character
  5. Update `currPos` to the current character's `idx`

Repeat this for all characters

### Step 5: Return Total Time

After all characterrs are processed, return `totalTime`