# Types of Failures

> Let's see the four basic types of failures.

There are several different types of failures. The following illustration shows the most basic categories.

<img width="533" height="422" alt="image" src="https://github.com/user-attachments/assets/7fc23f41-d1db-4eae-a087-eb3ee2c8cd32" />

Let's see these failures one by one.

## Fail-Stop

A node halts and remains halted permanently. Other nodes can detect that the node has failed (i.e., by communicating with it).

## Crash

A node halts, but silently. So, other nodes may not be able to detect this state. They can only assume its failure when they are unable to communicate with it.

## Omission

A node fails to respond to incoming requests.

## Byzantine

A node exhibits arbitrary behaviour: it may transmit arbitrary messages at arbitrary times, take incorrect steps, or stop.

Byzantine failures occur when a node does not behave according to its specific protocol or algorithm. This usually happens when a malicious actor or a software bug compromises the node.

To cope with these failures, we need complex solutions. However, most companies deploy distributed systems in environments that they assume to be private and secure.

Fail-stop failures are the simplest and the most convenient ones from the perspective of someone that builds distributed systems. However, they are not very realistic. This is because there are many cases in real-life systems where it's not easy for us to identify whether another node crashes or not.
