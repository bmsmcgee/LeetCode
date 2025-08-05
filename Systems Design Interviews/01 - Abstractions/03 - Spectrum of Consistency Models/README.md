# Spectrum of Consistency Models

## What is Consistency?

In distributed systems, consistency may mean many things. One is that each replica node has the same view of data at a given point in time. The other is that each read request gets the value of the recent write. These are not the only definitions of consistency, since there are many forms of consistency. Normally, **consistency models** provide us with abstractions to reason about the correctness of a distributed system doing concurrent data reads, writes, and mutations.

If we have to design or build an application in which we need a third-party storage system like S3 or Cassandra, we can look into the consistency guarentee provided by S3 to decide whether to use it or not. Let's explore different types of consistency.

The two ends of the consistency spectrum are:
  - _Strongest consistency_
  - _Weakest consistency_

There are consistency models that lie between these two ends, some of which are shown in the following illustration:

<img width="782" height="322" alt="image" src="https://github.com/user-attachments/assets/9bbbc836-4d80-4164-9e14-60e9b6802e74" />

There is a difference between consistency in _ACID_ properties and consistency in the _CAP Theorem_.

Database rules are at the heart of **ACID consistency**. If a schema specifies that a value must be unique, a consistent system will ensure that the value is unique throughout all actions. If a foreign key indicates that deleting one row will also delete associated rows, a consistent system ensures that the state can't contain related rows once the base row has been destroyed.

**CAP consistency** guarentees that, in a distributed system, every replica of the same logical value has the same precise value at all times. It's worth noting that this is a logical rather than a physical guarentee. Due to the speed of light, replicating numbers throughout a cluster may take some time. By preventing clients from accessing different values at separate nodes, the cluster can nevertheless give a logical picture.

## Eventual Consistency

**Eventual consistency** is the weakest consistency model. The applications that don't have strict ordering requirements and don't require reads to return the latest write choose this model. Eventual consistency ensures that all the replicas converge on a final value after a finite time and when no more writes are coming in. If new writes keep coming, replicas of an eventually consistent system might never reach the same state. Until the replicas converge, different replicas can return different values.

Initially, the value of $x$ is $2$.
<img width="938" height="510" alt="image" src="https://github.com/user-attachments/assets/a27aad4e-478f-467b-ba56-813fad07aa98" />

At time $T_{1}$, Alice sends a write request to update the value of $x$ to $10$.
<img width="940" height="511" alt="image" src="https://github.com/user-attachments/assets/fc19c636-f13a-4dfc-8a9b-5a19cdc4c6c7" />

The system saved the updated value of $x$.
<img width="938" height="511" alt="image" src="https://github.com/user-attachments/assets/21645dd2-eabf-46df-9b83-a49c74ef33f2" />

At time $T_{2}$, Alice and Bob read the value of $x$.
<img width="940" height="511" alt="image" src="https://github.com/user-attachments/assets/af7f4665-ac37-4aed-b240-dd8373cd150f" />

The system returns the same value to both read requests, but the value is old.
<img width="940" height="510" alt="image" src="https://github.com/user-attachments/assets/2ddea0a0-276e-42c7-81b5-ed77c57dbe18" />

At time $T_{3}$, system reaches the stable state and returns the latest value to both read requests.
<img width="940" height="512" alt="image" src="https://github.com/user-attachments/assets/8a697eed-26c0-4972-a103-4105c25c9d15" />

Eventual consistency ensures **High Availability**.

### Example

The **Domain Name System** is a highly available system that enables name lookups to a hundred million devices across the Internet. It uses an eventual consistency model and doesn't necessarily reflect the latest values.

  > **Note:** Cassandra is a highliy available NoSQL database that provides eventual consistency.

## Causal Consistency

**Causal consistency** works by categorizing operations into dependent and independent operations. **Dependent operations** are also called causally-related operations. Causal consistency preserves the order of the causally-related operations.

In the following illustration, process $P1$ writes a value $a$ at location $x$. For $P2$ to write the value $b$ at location $y$, it first needs to calculate $b$. Since $b=x+5$, the read operation on $x$ should be performed before writing $b$ on location $y$. That's why $read(x)a$ and $write(y)b$ are causally related.

<img width="510" height="270" alt="image" src="https://github.com/user-attachments/assets/f16ccc8c-afdc-4c55-84b2-1a20af9dba69" />

This model doesn't ensure ordering for the operations that are not causally related. These operations can be seen in different possible orders.

Causal consistency is weaker overall, but stronger than the eventual consistency model. It's used to prevent non-intuitive behaviours.

### Example

The causal consistency model is used in a commenting system. For example, for the replies to a comment on a Facebook post, we want to display comments after the comment it replies to. This is because there is a cause-and-effect relationship between a comment and its replies.

## Sequential Consistency

**Sequential consistency** is stronger than the causal consistency model. It preserves the ordering specified by each client's program. However, sequential consistency doesn't ensure that the writes are visible instantaneously or in the same order as they occurred according to some global clock.

### Example

In social networking applications, we usually don't care about the order in which some of our friends' posts appear. However, we still anticipate a single friend's posts to appear in the correct order in which they were created. Similarly, we expect our friends' comments in a post to display in the order that they were submitted. The sequential consistency model captures all of these qualities.

## Strict Consistency (a.k.a. Linearizability)

A **strict consistency** or **linearization** is the strongest consistency model. This model ensures that a read request from any replicas will get the latest write value. Once the client receives the acknowledgement that the write operation has been performed, other clients can read that value.

Linearizability is challenging to achieve in a distributed system. Some of the reasons for such challenges are variable network delays and failures. The following slides depict how variable network delays make it possible for different parties to see different values.

There are three users of a system consisting of three nodes (replicas), and each node initially has a value of $x$ that equals $2$.
<img width="939" height="511" alt="image" src="https://github.com/user-attachments/assets/b10bf689-c9a6-453e-9f58-4ac60518915d" />

Alice requests a write operation to change the value of $x$ to $10$.
<img width="940" height="511" alt="image" src="https://github.com/user-attachments/assets/52f9f507-1eaf-426e-b750-681c0a7055ba" />

Node A performs the write operation on $x$ and returns and acknowledgement back to Alice.
<img width="941" height="511" alt="image" src="https://github.com/user-attachments/assets/bb361f57-226a-4a99-bd11-27836ece0ca8" />

Node A forwards the write operation to the other nodes in the system.
<img width="940" height="511" alt="image" src="https://github.com/user-attachments/assets/ec41e8d7-b84e-4f2a-a58c-41a1219d088b" />

Node B receives the write operation and changes the value of $x$ to $10$.
<img width="940" height="512" alt="image" src="https://github.com/user-attachments/assets/7de00053-4800-46f3-b3d6-5e9d5ad4ddfe" />

John requests a read operation that is performed on Node B
<img width="942" height="512" alt="image" src="https://github.com/user-attachments/assets/4b813f93-6d07-4a33-b0ee-efd5bc60c781" />

Node B has the latest value of $x$ and returns it to John.
<img width="939" height="510" alt="image" src="https://github.com/user-attachments/assets/9d190711-6458-4331-962c-13f93c471ef8" />

After John, Bob requests a read operation on $x$, which is performed on Node C.
<img width="941" height="511" alt="image" src="https://github.com/user-attachments/assets/a683370a-0aac-4720-8da3-3e164cbff4ff" />

Node C has not yet received the write operation, so it returns the old value of $x=2$ to Bob.
<img width="941" height="512" alt="image" src="https://github.com/user-attachments/assets/c6a121a9-7858-4927-9d3a-7cfe0a062048" />

Usuallyt, synchronous replication is one of the ingredients for achieving strong consistency, though it in itself is not sufficient. We might need consensus algorithms such as Paxos and Raft to achieve strong consistency.

Linearizability affects the system's availability, which is why it's not always used. Applications with strong consistency requirements use techniques like **Quorum-Based Replication** to increase the system's availability.

### Example

Updating an account's password requires strict consistency. For example, if we suspect suspicious activity on our bank account, we immediately change our password so that no unauthorized users can access out account. If it were possible to access our account using an old password due to a lack of strict consistency, then changing passwords would be a useless security strategy.

  > **Note:** Google's Spanner database claims to be linearizable for many of its operations.

## Summary

Linearizable services appear to carry out transactions/operations in sequential, real-time order. They make it easier to create suitable applications on top of them by limiting the number of values that services can return to application processes.

Linearizable services have worse performance rates than services with weaker consistency in exchange for their strong assurances. Think about a read in a key-value store that returns the value written by a concurrent write. The read imposes no limits on future reads if the key-value store is weakly consistent.

Application programmers have to compromise performance and availability if they use services with a strong consistency models. The models may break the invariants built on top of them in exchange for increased performance.
