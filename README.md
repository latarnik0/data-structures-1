# Dynamic Array vs Linked List in C++

## Overview

Implementation of Dynamic Array and Linked List from scratch in **C++**.

## Functionality 
* **Adding elements to the front, back and to the given index** 
* **Removing elements from the front, back and from given index**
* **Searching an element of given index**

## Computational complexity analisys

Below are tables with the measurement results of individual operations in *nanoseconds*. The results in the tables are the average operation time over 100 trials of N samples.

### Adding elements
| Operation | N | Dynamic Array | Singly Linked List | Doubly Linked List |
| :--- | :--- | :--- | :--- | :--- |
| **Front** | 10 | 70 | 80 | 10 |
| | 100 | 330 | 40 | 100 |
| | 1000 | 2040 | 30 | 100 |
| | 10000 | 20030 | 160 | 70 |
| **End** | 10 | 40 | 80 | 80 |
| | 100 | 30 | 310 | 260 |
| | 1000 | 40 | 3330 | 3410 |
| | 10000 | 80 | 43790 | 44000 |
| **At index** | 10 | 20 | 90 | 110 |
| | 100 | 110 | 130 | 210 |
| | 1000 | 910 | 1720 | 1380 |
| | 10000 | 8640 | 24620 | 22140 |

### Removing elements
| Operation | N | Dynamic Array | Singly Linked List | Doubly Linked List |
| :--- | :--- | :--- | :--- | :--- |
| **Front** | 10 | 60 | 30 | 50 |
| | 100 | 270 | 80 | 50 |
| | 1000 | 1980 | 270 | 90 |
| | 10000 | 18340 | 780 | 50 |
| **End** | 10 | 20 | 70 | 80 |
| | 100 | 50 | 270 | 250 |
| | 1000 | 30 | 3080 | 3440 |
| | 10000 | 30 | 39990 | 43680 |
| **From index** | 10 | 80 | 50 | 60 |
| | 100 | 80 | 180 | 190 |
| | 1000 | 970 | 1780 | 1500 |
| | 10000 | 9350 | 24990 | 24140 |

### Access to the element of given index
| N | Dynamic Array | Singly Linked List | Doubly Linked List |
| :--- | :--- | :--- | :--- |
| 10 | 40 | 40 | 10 |
| 100 | 40 | 220 | 170 |
| 1000 | 60 | 1830 | 1450 |
| 10000 | 60 | 25840 | 23390 |

### Time Complexity of all operations

| N | Dynamic Array | Singly Linked List | Doubly Linked List |
| :--- | :--- | :--- | :--- |
| **Adding at the front** | *O(N)* | ***O(1)*** | ***O(1)*** |
| **Adding at the end** | ***O(1)*** | *O(N)* | *O(N)* |
| **Adding at the given index** | *O(N)* | *O(N)* | *O(N)* |
| **Removing from the front** | *O(N)* | ***O(1)*** | ***O(1)*** |
| **Removing at the end** | ***O(1)*** | *O(N)* | *O(N)* |
| **Removing from the given index** | *O(N)* | *O(N)* | *O(N)* |
| **Access** | ***O(1)*** | *O(N)* | *O(N)* |