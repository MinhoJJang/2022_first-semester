# Quiz & Debate

## 1. Explain the following in Multiprocessor scheduling: Load balancing and Processor affinity

In per-core raedy queues, Load balancing is needed. using Migration, Move tasks from a busy processor to and idle processor. It's Load balancing.

Processor affinity is, when a thread has been running on one processor, the cache contents of that processor stores the memory accesses by that thread. But if Load balancing is operated, cache misses happen. So, Processor Affinity means trying to keep progress on same processor to avoid cache misses.

## 2. “A race condition results when several threads try to read the same data concurrently.” Is this statement true or false? Explain.

False!

Race condition is happen when threads want to read same data and write or modify it. But only reading same data can't cause race condition. Because reading the data is not the same meaning write or modify the data on shared memory.

## 3. Suppose that a producer produces one item, and concurrently, a consumer consumes one item. Given that the value of counteris three (3) before the two executions, can the final counter value after the executions be two (2)? Explain. [Midterm 2015]

T0: producer execute register1 = counter {register1 = 3}
T1: producer execute register1 = register1 + 1 {register1 = 4}
T2: consumer execute register2 = counter {register2 = 3}
T3: consumer execute register2 = register2 - 1 {register2 = 2}
T4: producer execute counter = register1 {counter = 4 }
T5: consumer execute counter = register2 {counter = 2}

## 4. Explain why Peterson’s solution can provide mutual exclusion and progress (deadlock free).

wants[] 와 not_turn 두가지 변수를 사용하여 mutual exclusion 과 progress 둘 다 만족시켰다.
