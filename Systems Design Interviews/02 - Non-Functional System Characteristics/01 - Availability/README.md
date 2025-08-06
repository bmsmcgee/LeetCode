# Availability

## What is Availability?

**Availability** is the percentage of time that some service or infrastructure is accessible to clients and is operated upon under normal conditions. For example, if a service has 100% availability, it means that the said service functions and responds as intended (operates normally) all the time.

## Measuring Availability

Mathematically, availability, $A$, is a ratio. The higher the $A$ value, the better. We can also write this up as a formula:

$$A=\frac{(Total\space Time - Amount\space Of\space Time\space Service\space Was\space Down)}{Total\space Time}\times 100\\%$$

We measure availability as a number of nines. The following table shows how much downtime is permitted when we're using a given number of nines.

## The Nines of Availability

Availability Percentage versus Service Downtime

| **Availability %**  | **Downtime per Year** | **Downtime per Month** | **Downtime per Week** |
| :-----------------: | :-------------------: | :--------------------: | :-------------------: |
| 90% (1 Nine)        | 36.5 Days             | 72 Hours               | 16.8 Hours            |
| 99% (2 Nines)       | 3.65 Days             | 7.20 Hours             | 1.68 Hours            |
| 99.5% (2 Nines)     | 1.83 Days             | 3.60 Hours             | 50.4 Minutes          |
| 99.9% (3 Nines)     | 8.76 Hours            | 43.8 Minutes           | 10.1 Minutes          |
| 99.99% (4 Nines)    | 52.56 Minutes         | 4.32 Minutes           | 1.01 Minutes          |
| 99.999% (5 Nines)   | 5.26 Minutes          | 25.9 Seconds           | 6.05 Seconds          |
| 99.9999% (6 Nines)  | 31.5 Seconds          | 2.59 Seconds           | 0.605 Seconds         |
| 99.99999% (7 Nines) | 3.15 Seconds          | 0.259 Seconds          | 0.0605 Seconds        |

## Availability and Service Providers

Each service provider may start measuring availability at different points in time. Some cloud providers start measuring it when they first offer the service, while some measure it for specific clients when they start using the service. Some providers might not reduce their reported availability numbers if their service was not down for all the clients. The planned downtimes are excluded. Downtime due to cyberattacks might not be incorporated into the calculation of availability. Therefore, we should carefully understand how a specific provider calculates their availability numbers.
