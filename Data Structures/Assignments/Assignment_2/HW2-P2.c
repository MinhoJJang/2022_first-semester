#include <stdio.h>

/*
HW2-P2 과제
202033762 장민호

Circular Queue
-> 5 elements
-> Test the program using sequence of page 8-9
*/

/*
구현해야할 함수 정보

1. Queue_empty
-> front == rear == 0
-> 0인 경우 (Empty)

2. Queue_full
-> If front == rear+1, Queue full

3. enqueue
queue[rear] = input_num;

4. dequeue
return_num = queue[front];

*/

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAIL 0

#define Q_SIZE 5

int front = 0;
int rear = 0;
int next_rear;
int queue[Q_SIZE + 1] = {0};
int return_item;
int new_item;

int queue_empty()
{
    if (front == rear)
    {
        // front == rear 이고, front == 0일 경우 빈 큐임
        if (front == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int queue_full()
{
    // front == next_rear 일 때, 큐가 꽉 차있으므로 enqueue 불가능.
    next_rear = (rear % Q_SIZE) + 1;
    if (front == next_rear)
    {
        return TRUE;
    }
    return FALSE;
}

int enqueue(int new_item)
{

    // next_rear 을 만들어둔다.
    next_rear = (rear % Q_SIZE) + 1;

    // 큐가 full 인지 검사한다. full 일 경우 enqueue 불가하다.
    if (queue_full())
    {
        printf("circular queue overflow\n");
        return FAIL;
    }
    // 큐가 full이 아닐 경우, 큐가 empty 상태인지 아닌지 구분한다.
    else
    {
        if (queue_empty())
        {
            front = 1;
        }
        rear = next_rear;
        queue[rear] = new_item;
        printf("enqueue된 데이터 : %d\n", new_item);
    }
    return SUCCESS;
}

int dequeue()
{
    // 큐가 비었는지 검사한다. 비었으면 dequeue 실패
    if (queue_empty())
    {
        printf("circular queue underflow\n");
        return FAIL;
    }
    // 큐가 비지 않았을 경우, 일단 front의 값을 가져온다. 이후, front과 rear 값의 관계를 구하고 그 관계에 따라 분기를 나눈다.
    else
    {
        return_item = queue[front];
        queue[front] = 0;

        // front == rear 이지만 front != 0이면 front 위치의 값을 저장하고 front = rear = 0 을 해주어 빈 큐로 만들어준다.
        if (front == rear)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            front = (front % Q_SIZE) + 1;
        }

        printf("dequeue한 데이터 : %d\n", return_item);
        return SUCCESS;
    }
}

int main()
{
    enqueue(10);
    enqueue(50);
    enqueue(30);
    enqueue(70);
    dequeue();
    enqueue(100);
    enqueue(40);
    enqueue(140);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}