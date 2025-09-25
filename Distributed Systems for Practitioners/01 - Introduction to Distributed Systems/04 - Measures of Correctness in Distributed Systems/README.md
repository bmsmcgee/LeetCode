# Measures of Correctness in Distributed Systems

> Let's see how to measure the correctness of a distributed system.

## Correctness

We can define the correctness of a system in terms of the properties it must satisfy.

## Measures of Correctness

The correctness measures for distributed systems are the two properties they must satisfy:
  - Safety property
  - Liveness property

### Safety

A safety property defines something that must never happen in a correct system.

IMAGE

### Liveness

A liveness property defines something that must eventually happen in a correct system.

IMAGE

## Example of a Correct System

If we consider the correct properties of an over, we can say that "the oven not exceeding a maximum temperature threshold" is a safety property. The property of "the oven eventually reaching the temperature we specified via the button" is a liveness property.

Similar to this example, it's usually more important in a distributed system to ensure the system satisfies the safety property than the liveness one.

IMAGE

