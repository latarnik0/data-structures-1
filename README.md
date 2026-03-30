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

#### Dynamic Array Summary
The measurements are correct and are direct result of the architecture of these structures. A dynamic array is a contiguous block in RAM. It contains a variable that stores the number of elements `size` in the array, so adding and removing from the end has a constant computational complexity of ***O(1)*** because the location of the operation is known in advance.
The same applies to reading a given element. The processor uses simple arithmetic to quickly determine the address of the value we want to access.
When it comes to adding/removing from the beginning or to a given index, the computational complexity is linear
***O(N)*** because the processor must physically move all elements in the array up to the specified index
and only then insert or remove the value. In the case of deletion, the processor must "patch the hole" created
by removing the element, also by moving the elements.
#### Linked Lists Summary
In the case of linked lists, the data is not stored as a contiguous block in memory; it is dscattered through memory and uses pointers. It's impossible to mathematically calculate the address of the nth element. Adding and removing from the beginning of a list has a constant computational time of ***O(1)*** because we have access to the `head` variable. When adding or removing from the end or from a given index, we must traverse the entire list to the nth index to perform the read, add, or remove operation. This is where singly and doubly linked lists differ. If we already have the index of the element we want to remove, we can't perform this operation in a singly linked list with O(1) complexity because in a singly linked list, the list only looks forward, and to reconnect pointers after removal, we must traverse the list again to find the previous element. In a doubly linked list, this problem is eliminated because, by definition, it has a pointer to its previous neighbor `prev`.