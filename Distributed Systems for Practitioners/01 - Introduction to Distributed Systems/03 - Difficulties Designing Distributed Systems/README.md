# Difficulties Designing Distributed Systems

> Let's see what makes distributed systems hard to design.

## Why Distributed Systems are Hard to Design

In general, distributed systems are hard to design, build, and reason about. This increases the risk of error.

It's worth questioning this: why are distributed systems so hard to design? The answer to this question will help us eliminate our blind spots, and provide guidance on some aspects we should pay attention to.

> **Why are distributed systems so hard to design?**
>
> Designing distributed systems is challenging due to network asynchrony, partial failures, and concurrency. Network unpredictability leads to delays and out-of-order message delivery. Handling partial failures complicates ensuring atomicity across system components. Concurrency introduces complexities as computations can interfere, creating unexpected behaviours. 

## Properties that Make Distributed Systems Challenging

The following illustration shows the main properties that make distributed systems challenging to reason about.

<img width="554" height="319" alt="image" src="https://github.com/user-attachments/assets/d183b362-53ed-497f-b2e1-1214b6a9f34c" />

Let's look at each property.

### Network Asynchrony

**Network asynchrony** is a property of communication networks that cannot provide strong guarentees around delivering events (e.g., a maximum amount of time a message requires for delivery). This can create a lot of counter-intuitive behaviours that are not present in non-distributed systems. This contrasts to memory operations that provide much [stricter guarentees](https://en.wikipedia.org/wiki/CAS_latency). For instance, messages might take extremely long to deliver in a distributed system. They may even deliver out of order &mdash; or not at all.

<img width="428" height="225" alt="image" src="https://github.com/user-attachments/assets/b5c42d67-b843-4a1a-adee-cc0a2a1a8ca7" />

### Partial Failures

**Partial failures** are the cases where only some components of a distributed system fail. This behaviour can contrast with certain kinds of applications a single server deploys. These applications work under the assumption that either everything is working fine, or there has been a server crash. It introduces significant complexity when it requires atomicity across components in a distributed system. Thus, we must ensure that we either apply an operation to all the nodes of a system, or to none of them.

<img width="417" height="368" alt="image" src="https://github.com/user-attachments/assets/06e024f4-d076-42bf-a3c4-c4cea31e64ad" />

### Concurrency

**Concurrency** is the execution of multiple computations at the same time, and potentially on the same piece of data. These computations interleave with each other. This introduces additional complexity since these computations can interfere with each other and create unexpected behaviours. This is, again, in contrast to simplistic applications with no concurrency, where the program runs in the order the sequence of commands in the source code defined.

<img width="404" height="270" alt="image" src="https://github.com/user-attachments/assets/d0710146-573a-4d6b-935b-a09766b445af" />

Network asynchrony, partial failures, and concurrency are the major contributors to complexity in the field of distributed systems. So, we should keep them in mind when we build distributed systems in real life. Doing so would help us anticipate edge cases and handle them appropriately.

> **What role does concurrency play in the challenges associated with designing distributed systems?**
>
> Concurrency introduces several challenges in the design of distributed systems:
>   1. **Interleaved Execution:** Concurrent computations can execute interleaved, making it challenging to predict the order of execution and leading to unexpected outcomes.
>   2. **Race Conditions:** Concurrent processes competing for shared resources may result in race conditions, where the final state depends on the timing of execution, leading to inconsistencies.
>   3. **Deadlocks:** Concurrent processes may contend for multiple resources, creating situations where each process is waiting for the other to release a resource, causing a deadlock.

