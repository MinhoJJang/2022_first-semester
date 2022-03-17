#include <stdio.h>
#include <stdlib.h>   
#pragma warning(disable:4996)

/* 
0304 Data Structures 과제 LAB 1-1
202033762 장민호

조건
1. 스택 최대크기 10
2. 구현할 function: push, pop, stack_full, stack_empty
3. 함수 호출 시 포인터 사용하지 않기
4. scanf, printf는 반드시 main에서만 사용
5. push 하기 전 stack_full 검사
6. pop 하기 전 stack_empty 검사 
*/

#define SUCCESS 1
#define FAIL 0
#define MAXSIZE 10

typedef int Data; // int 타입 데이터. 언제든 타입은 바뀔 수 있으므로 Data를 typedef으로 선언해주었다.

typedef struct _node {
	Data data; 
	struct _node *pNext; // Stack에 새로운 데이터가 들어올 시, 기존에 있었던 Top데이터를 가리킨다.  
} Node;

typedef struct _stack {
	Node *pTop; // Stack의 가장 Top쪽에 있는 Node를 가리키는 포인터
	int numdata; // 스택에 들어있는 수의 총 개수 
} Stack;


void stack_init(Stack *pStack) {
	pStack->pTop = NULL; // 스택 처음 생성시 아무것도 없으므로 NULL
	pStack->numdata = 0; // 데이터가 아무것도 없으므로 0
}

int stack_push(Stack *pStack, Data data) {

	if (stack_full(pStack) == SUCCESS) {
		return FAIL;
	}

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;
	pStack->numdata++;

	return SUCCESS;
}

int stack_pop(Stack *pStack, Data *pData) {

	if (stack_empty(pStack) == SUCCESS) {
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;

	*pData = pStack->pTop->data;
	pStack->pTop = pStack->pTop->pNext;

	free(pCurrent);
	pStack->numdata--;

	return SUCCESS;
}

int stack_empty(Stack *pStack) {
	if (pStack->pTop == NULL) {
		return SUCCESS;
	}
	else {
		return FAIL;
	}
}

int stack_full(Stack *pStack) {

	if (pStack->numdata == MAXSIZE) {
		return SUCCESS;
	}
	else {
		return FAIL;
	}
}

int main() {

	Stack stack;
	Data data;

	stack_init(&stack);

	for (int num = 0; num < MAXSIZE+1; num++) {
		if (stack_full(&stack) == SUCCESS) {
			printf("더이상 스택에 데이터를 넣을 수 없습니다!\n");
			printf("현재 스택에 들어있는 데이터 개수: %d개\n", stack.numdata);
			break;
		}
		stack_push(&stack, num);
		printf("스택에 들어간 데이터: %d\n", stack.pTop->data);
	}

	printf("\n");

	for (int i = 0; i < MAXSIZE + 1; i++) {
		if (stack_empty(&stack) == SUCCESS) {
			printf("더이상 스택에서 데이터를 꺼낼 수 없습니다!\n");
			printf("현재 스택에 들어있는 데이터 개수: %d개\n", stack.numdata);
			break;
		}
		stack_pop(&stack, &data);
		printf("스택에서 꺼낸 데이터: %d\n", data);
	}

	return 0;
}