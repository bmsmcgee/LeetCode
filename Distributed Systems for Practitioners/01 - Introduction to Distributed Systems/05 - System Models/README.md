# System Models

> Let's see the distributed system models.

## Nature of Real-Life Distributed Systems

Real-life distributed systems can differ drastically in many dimensions. These differences depend on factors like the network that deploys them, the hardware they run on, etc.

Thus, we need a common framework to solve problems generically. This way, we don't need to repeat the reasoning for the different variations of these systems.

## Making a Generic Model

To create a model of a distributed system, we must define several properties it must satisfy. If we prove an algorithm is correct for this model, we can be sure that it'll also be correct for all the systems that satisfy these properties.

### Properties Each System Follows

The main important properties in a distributed system concern the following:
  - How the nodes of a distributed system interact with each other.
  - How the nodes of a distributed system can fail.

## Categories of Distributed Systems

There are two main categories of distributed systems that depend on the nature of communication:
  1. Synchronous systems
  2. Asynchronous systems

### Synchronous System

A **synchronous system** is one where each node has an accurate clock, and there is a known upper bound on the message transmission delay and processing time. As a result, the execution is split into rounds. This way, every node sends a message to another node, the messages deliver, and every node computes based on the messages it receives. During this, all nodes run in lock-step.

### Asynchronous System

An **asynchronous system** is one where there is no fixed upper bound on how long it takes for a node to deliver a message, or how much time elapses between consecutive steps of a node. The system nodes do not have a common notion of time and, thus, run at independant rates.

So, it should be clear by now that the *synchronous* model is much easier to describe, program, and reason about. However, the *asynchronous* model is closer to real-life distributed systems, such as the Internet, where we cannot control all the components they involve. Also, there are minimal guarentees on the time it takes to send a message between two places.

> **How does network asynchrony contribute to the complexity of distributed systems?**
>
> Network asynchrony in distributed systems refers to the lack of strong guarentees regarding the timing of event delivery within the communication network. This property introduces complexities, as messages may experience unpredictable delays, arrive out of order, or even fail to be delivered. Unlike non-distributed systems where communication is typically more deterministic, the inherent asynchrony in distributed systems can lead to counterintuitive behaviours.
>
> The challenges posed by network asynchrony emphasizes the need for robust communication protocols and error-handling mechanisms in distributed system design. Developers must account for the unpredictable nature of message delivery to ensure the reliability and consistency of the system despite potential network irregularities.