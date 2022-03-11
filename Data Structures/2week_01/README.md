# 2week_01

* 숙제 제출할 때 컴파일 후 에러 없다는 컴파일 결과를 제출해야 함
* VSC에서 코드 정리 : Ctrl + K + F

## Circular Queue 

> 실습코드 

[C에서 bool타입 사용하는 법](https://karupro.tistory.com/15)

```c
#include <stdio.h>
#include <stdbool.h> // bool을 사용하기 위해 헤드 추가 

#define Q_SIZE 8

struct CIRCULAR_QUEUE
{
    int arr[Q_SIZE];// array to store queue elements
    int capacity;   // maximum number of elements
    int front;      // point to the front element in the queue
    int rear;       // point to the last element in the queue
    int count;      // the current number of elements
} Queue = { {0,}, Q_SIZE, 0, Q_SIZE -1, 0 };

bool q_isEmpty() {
    return (Queue.count == 0);
}
bool q_isFull() {
    return (Queue.count == Queue.capacity);
}

void enqueue(int x) {

if (q_isFull()) // check for queue overflow
{
    printf("Queue is Full\n");
    return;
}

    Queue.rear = (Queue.rear + 1) % Queue.capacity;
    Queue.arr[Queue.rear] = x;
    Queue.count++;

    printf("%d is inserted into Q[%d]\n", x, Queue.rear);

}

int dequeue() {

if (q_isEmpty()) // check for queue underflow

{
    printf("Queue is Empty\n");
    return 0;
}
    int x = Queue.arr[Queue.front];
    printf("%d is removed from Q[%d]\n", x, Queue.front);
    Queue.front = (Queue.front + 1) % Queue.capacity;
    Queue.count--;
    return x;
}

int main()
{
    int val;
    enqueue(1); // Q[0] <- 1
    enqueue(2); // Q[1] <- 2
    enqueue(3); // Q[2] <- 3
    val = dequeue(); // 1 <- Q[0]
    enqueue(4); // Q[0] <- 4
    val = dequeue(); // 2 <- Q[1]
    val = dequeue(); // 3 <- Q[2]
    val = dequeue(); // 4 <- Q[0]
    if (q_isEmpty()) // q is empty now
    {
        printf("The queue is empty\n");
    }
    else {
        printf("The queue is not empty\n");
    }
    return 0;
}
```

> 실행결과 
```bash
mhj@mhj-IdeaPad:~/gitRepo/2022_first-semester$ cd "/home/mhj/gitRepo/2022_first-semester/Data Structures/2week_01"
mhj@mhj-IdeaPad:~/gitRepo/2022_first-semester/Data Structures/2week_01$ ./"circularQueue" 
1 is inserted into Q[0]
2 is inserted into Q[1]
3 is inserted into Q[2]
1 is removed from Q[0]
4 is inserted into Q[3]
2 is removed from Q[1]
3 is removed from Q[2]
4 is removed from Q[3]
The queue is empty
```