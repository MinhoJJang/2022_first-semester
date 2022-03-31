#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *pNext;
} Node;

typedef struct _queue
{
    Node *pFront;
    Node *pRear;
} ListQueue;

typedef ListQueue Queue;

// 큐 초기화
void queue_init(Queue *pq)
{
    pq->pFront = NULL;
    pq->pRear = NULL;
}

// 큐가 비어있는지?
int queue_empty(Queue *pq)
{
    if (pq->pFront == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

// 큐가 꽉 찰 일이 없으므로 False
int queue_full()
{
    return FALSE;
}

// enqueue, 데이터 추가 (rear 에 추가)
int enqueue(Queue *pq, Data data)
{
    // 새로운 노드 생성
    Node *pNewNode = (Node *)malloc(sizeof(Node));
    pNewNode->pNext = NULL;
    pNewNode->data = data;

    // 큐가 비어있을때와 그렇지 않을때 구분
    if (queue_empty(pq))
    {
        pq->pFront = pNewNode;
        pq->pRear = pNewNode;
        // 비어있을 경우 front 와 rear 가 같은 값을 가리킴
    }
    else
    {
        pq->pRear->pNext = pNewNode;
        pq->pRear = pNewNode;
        // rear가 가장 나중의 데이터이므로 나중의 데이터의 뒤에 새로운 노드를 집어넣고, rear를 새로운 노드로 지정
    }
    printf("enqeue 된 데이터 : %d\n", pq->pRear->data);
    return SUCCESS;
}

// dequeue, 데이터 꺼내기 (front 에서 추출)
int dequeue(Queue *pq, Data *pData)
// dequeue의 경우 맨 처음 들어온 값, 즉 front가 제일 먼저 나간다.
{
    // 1. 데이터가 큐에 없을 경우
    if (queue_empty(pq))
    {
        printf("Queue EMPTY!\n");
        return FAIL;
    }

    // 2. 데이터가 큐에 있을 경우
    if (pData != NULL) // 포인터 pData에 값이 있으면
    {
        *pData = pq->pFront->data; // front 의 데이터 추출

        Node *deleteNode = pq->pFront;  // 삭제할 노드를 기억해야 한다. queue의 front에 있는 값을 node형 포인터 deleteNode에 담는다.
        pq->pFront = pq->pFront->pNext; // front 는 다음 노드로 이동

        free(deleteNode);
    }

    return SUCCESS;
}

int main()
{
    // Queue 생성 및 초기화
    Queue q;
    Data data;
    queue_init(&q);

    dequeue(&q, &data);

    // enqueue
    enqueue(&q, 1); // front <-- [1] <-- rear
    enqueue(&q, 2); // front <-- [1 2] <-- rear
    enqueue(&q, 3); // front <-- [1 2 3] <-- rear
    enqueue(&q, 4); // front <-- [1 2 3 4] <-- rear
    enqueue(&q, 5); // front <-- [1 2 3 4 5] <-- rear

    dequeue(&q, &data);
    printf("deq --> %d\n", data); // 1
    dequeue(&q, &data);
    printf("deq --> %d\n", data); // 2
    dequeue(&q, &data);
    printf("deq --> %d\n", data); // 3
    dequeue(&q, &data);
    printf("deq --> %d\n", data); // 4
    dequeue(&q, &data);
    printf("deq --> %d\n", data); // 5
    dequeue(&q, &data);

    return 0;
}