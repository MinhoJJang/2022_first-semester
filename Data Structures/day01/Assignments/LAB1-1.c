#include <stdio.h>

/*
0304 Data Structures 과제 LAB 1-1
202033762 장민호

조건
1. 스택 최대크기 10
2. 구현할 function: push(int), pop(), stack_full(), stack_empty()
3. 함수 호출 시 포인터 사용하지 않기
4. scanf, printf는 반드시 main에서만 사용
5. push 하기 전 stack_full 검사
6. pop 하기 전 stack_empty 검사
*/

#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

int topIndex = -1; // Stack의 Top에 위치한 데이터의 index값. 초기에는 아무것도 없으므로 -1이다. 
int stack[MAXSIZE];

void push(int num) {
	topIndex++; 
	stack[topIndex] = num;
}

int pop() {
	int top = stack[topIndex];
	topIndex--;
	return top;
}

int stack_full() {
	if (topIndex == MAXSIZE-1) {
		return TRUE;
	}
	return FALSE;
}

int stack_empty() {
	if (topIndex < 0) {
		return TRUE;
	}
	return FALSE;
}

int main() {

	int testNum = 10;

	// Case 1 : 최대한 push 후 끝까지 pop 하는 경우

	printf("Case 1 : 최대한 push 후 끝까지 pop 하는 경우\n");

	while (1) {
		if (stack_full() == TRUE) {
			printf("스택이 가득 찼습니다. pop()을 이용하여 스택을 비우고 실행해 주세요\n");
			break;
		}
		else {
			push(testNum);
			printf("push() 성공 : %d\n", testNum);
			testNum += 10;
		}
	}

	while (1) {
		if (stack_empty() == TRUE) {
			printf("스택이 비었습니다. push(int)를 통해 스택에 데이터를 넣고 실행해 주세요\n");
			break;
		}
		else {
			printf("pop() 한 데이터 값: %d\n",pop());
		}
	}

	// Case 2 : 처음부터 pop 을 시도하는 경우 

	printf("\n");
	printf("Case 2 : 처음부터 pop 을 시도하는 경우\n\n");

	if (stack_empty() == TRUE) {
		printf("스택이 비었습니다. push(int)를 통해 스택에 데이터를 넣고 실행해 주세요\n");
	}
	else {
		printf("pop() 한 데이터 값: %d\n", pop());
	}
	
	return 0;
}