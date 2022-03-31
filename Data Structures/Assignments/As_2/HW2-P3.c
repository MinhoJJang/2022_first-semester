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

typedef struct _listStack
{
    Node *pTop;
} ListStack;

typedef ListStack Stack;

// 스택 초기화
void stack_init(Stack *pStack)
{
    pStack->pTop = NULL;
}

// 스택이 비었는지 확인
int stack_empty(Stack *pStack)
{
    if (pStack->pTop == NULL)
        return SUCCESS;

    return FAIL;
}

// malloc 방식으로 데이터가 들어올 때마다 메모리에 할당하는 방식의 스택은 full 되지 않는다고 보면 된다. 그러므로 반드시 False 리턴
int stack_full()
{
    return FALSE;
}

// push : top에 데이터 추가
int stack_push(Stack *pStack, Data data)
{
    if (stack_full())
    {
        return FAIL;
    }

    // 새로운 노드 생성
    Node *pNewNode = (Node *)malloc(sizeof(Node));
    memset(pNewNode, 0, sizeof(Node));

    pNewNode->data = data;

    // 노드를 스택에 추가 (리스트 맨 앞에 insert)
    pNewNode->pNext = pStack->pTop;
    pStack->pTop = pNewNode;

    return SUCCESS;
}

// pop : top의 데이터 꺼내기
int stack_pop(Stack *pStack, Data *pData)
{

    if (stack_empty(pStack))
    {
        printf("Empty Stack\n");
        return FAIL;
    }

    Node *pCurrent = pStack->pTop; // 삭제할 노드 기억

    if (pData != NULL)
        *pData = pStack->pTop->data; //데이터 꺼내기

    pStack->pTop = pStack->pTop->pNext; // top 이동

    free(pCurrent); // pop 된 노드 제거

    return SUCCESS;
}

int main()
{

    Stack stack;
    Data data;

    stack_init(&stack);

    // 데이터 push
    stack_push(&stack, 1); // 1
    stack_push(&stack, 2); // 2 - 1
    stack_push(&stack, 3); // 3 - 2 - 1
    stack_push(&stack, 4); // 4 - 3 - 2 - 1
    stack_push(&stack, 5); // 5 - 4 - 3 - 2 - 1
                           // top

    //데이터 pop
    stack_pop(&stack, &data);
    printf("pop--> %d\n", data); // 5
    stack_pop(&stack, &data);
    printf("pop--> %d\n", data); // 4
    stack_pop(&stack, &data);
    printf("pop--> %d\n", data); // 3
    stack_pop(&stack, &data);
    printf("pop--> %d\n", data); // 2
    stack_pop(&stack, &data);
    printf("pop--> %d\n", data); // 1
    stack_pop(&stack, &data);    // Empty Stack
}