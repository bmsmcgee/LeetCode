# Failure in the World of Distributed Systems

> Let's see why failures occur in distributed systems, and how we can detect them

We should understand that it is challenging to identify failure because of all the characteristics of a distributed system that the [Difficulties Designing Distributed Systems](../03%20-%20Difficulties%20Designing%20Distributed%20Systems/README.md) lesson described. One of them is the asynchronous nature of the network.

## One Reason for Failure

The asynchronous nature of the network in a distributed system can make it very hard for us to differentiate between a crashed node and a node that is just really slow to respond to requests.

## One Mechanism to Detect Failure

**Timeouts** is the main mechanism we can use to detect failures in distributed systems. Since an asynchronous network can infinitely delay messages, timeouts impose an artifical upper bound on these delays. As a result, we can assume that a node fails when it is slower than this bound. This is useful because otherwise, the assumption that the nodes are extremely slow would block the ystem that is waiting for the nodes that crashed.

However, a timeout does not represent an actual limit. Thus, it creates the following trade-off.

### Trade-Off for the Small Timeout Value

If we select a smaller value for the timeout, our system will waste less time waiting for the nodes that have crashed.

At the same time, the system might declare some nodes that have not crashed dead, while they are actually just a bit slower than expected. 

We set a small timeout value. If Node A is able to receive a response from Node B during this time duration, Node B is considered alive, otherwise dead.

IMAGE

Node A asks Node B about its status by sending an "Are you alive?" message.

IMAGE

Node B responds with the message, "I am alive".

IMAGE

Node A declares Node B as a dead node because it didn't receive a response during the timeout.

IMAGE

Since Node A's declaration/detection for Node B's status was incorrect, we call it a false positive, assuming that the dead node refers to a positive clas and the alive node refers to a negative class.

IMAGE

### Trade-Off for the Large Timeout Value

If we select a larger value for the timeout, the system will be more lenient with slow nodes.

At the same time, the system will be slower in identifying crased nodes, in some cases wasting time while waiting for them.

We set a large timeout value. If Node A receivers a response from Node B during this time duration, Node B is considered alive, otherwise dead.

IMAGE

Node A asks Node B about its status by sending an "Are you alive?" message.

IMAGE

Node B responds with the message, "I am alive!"

IMAGE

Node B crashed right after responding to Node A.

IMAGE

Node A considers Node B alive because it received the response from Node B before the timeout and wouldn't find that the node is crashed until the timeout duration completes.

IMAGE

Since Node A's declaration/detection for Node B's status was incorrect, we call it a false negative, assuming that the dead node refers to a positive class and the alive node refers to a negative class.

IMAGE

To detect Node B's failure, Node A is able to request again (after a long time) about the status of Node B.

IMAGE

This is a fundamental problem in the field of distributed systems.

## Failure Detector

A failure detector is the component of a node that we can use to identify other nodes that have failed.

This component is essential for various algorithms that need to make progress in the presence of failures. There has been extensive research about failure detectors.

### Properties that Categorize Failure Detectors

We can distinguis the different categories of failure detectors through two basic properties that reflect the trade-off:
  1. **Completeness** corresponds to the percentage of crashed nodes a failure detector successfully identifies in a certain period.
  2. **Accuracy** corresponds to the number of mistakes a failure detector makes in a certain period.

### A Perfect Failure Detector

A perfexct failure detector is the one with the strongest form of *completeness* and *accuracy*. That is, it is one that successfully detects every faulty process without ever assuming a node has crashed before it actually does.

As expected, it is impossible to build a perfect failure detector in purely asynchronous systems. Still, we can even use imperfect failure detectors to solve difficult problems. One such example is the problem of consensus.