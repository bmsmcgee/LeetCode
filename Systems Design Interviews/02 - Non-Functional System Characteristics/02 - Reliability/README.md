# Reliability

## What is Reliability?

**Reliability** is the probability that the service will perform its functions for a specified time. It measures how the service performs under carying operating conditions.

We often use **Mean Time Between Failures (MTBF)** and **Mean Time To Repair (MTTR)** as metrics to measure reliability.

$$MTBF=\frac{Total\space Elapsed\space Time - Sum\space of\space Downtime}{Total\space Number\space of\space Failures}$$

$$MTTR=\frac{Total\space Maintenance\space Time}{Total\space Number\space of\space Repairs}$$

(We strive for a higher MTBF value and a lower MTTR value.)

Reliability and availability are often confused, but they measure different aspects of system performance. While reliability focuses on how consistently a service operates without failure, availability considers how often it is accessible when needed. Understanding both is crucial because even a highly reliable system can have low availability if downtime or repairs take too long. Let's explore how these two concepts are interconnected:

## Reliability and Availability

Reliability and availability are two important metrics to measure compliance of service to agreed-upon _Service Levell Objectives (SLO)_.

The measurement of availability is driven by time loss, whereas the frequency and impact of failures drive the measure of reliability. Availability and reliability are essential because they enable the stakeholders to assess the health of the service.

Reliability ($R$) and availability ($A$) are two distinct concepts, but they are related. Mathematically, $A$ is a function of $R$. This means that the value of $R$ can change independantly, and the value of $A$ depends on $R$. Therefore, it's possible to have situations where we have:
  - low $A$, low $R$
  - low $A$, high $R$
  - high $A$, low $R$
  - high $A$, high $R$ (desireable)

<img width="364" height="331" alt="image" src="https://github.com/user-attachments/assets/451298bf-fe8a-4bc5-a173-a2693010dd15" />

### What is the Difference Between Reliability and Availability?

**Reliability** measures how well a system performs its intended operations (functional requirements). We use averages for that (Mean Time To Failure, Mean Time To Repair, etc.)

**Availability** measures the percentage of time a system accepts requests and responds to clients.
