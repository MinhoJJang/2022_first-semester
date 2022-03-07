#include <stdio.h>

/*
0304 Data Structures 과제 LAB 1-2
202033762 장민호

조건
1. Queue 최대크기 10
2. 구현할 function: enqueue(int), dequeue(), queue_full(), queue_empty()
3. 함수 호출 시 포인터 사용하지 않기
4. scanf, printf는 main에서만 사용
5. enqueue 하기 전 queue_full 검사
6. dequeue 하기 전 queue_empty 검사
7. non-Circular queue
*/

#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

int front = -1; 
int rear = -1;
int queue[MAXSIZE];

// Queue의 첫 input 시 rear과 front를 모두 0으로 만들어주는 과정 필요함 
// 만약 front가 rear보다 클 경우 Queue에는 데이터가 없음
// 만약 front와 rear가 모두 -1일 경우 Queue에는 데이터가 없음
// rear가 MAXSIZE-1이 되었을 때 queue_full() == YES 상태임. 

void enqueue(int num) {

	if (queue_full() == FALSE) {
		if (front == -1 && rear == -1) {
			front=0;
		}
		rear++;
		queue[rear] = num;
		printf("Queue에 들어간 데이터 : %d\n", queue[rear]);
	}
	else {
		printf("큐가 포화 상태입니다\n");
	}
}

int dequeue() {

	if (queue_empty() == FALSE) {
		int frontData = queue[front];
		front++;
		printf("Queue에서 꺼낸 데이터 : %d\n", frontData);
		return frontData;
	}
	else {
		printf("큐가 비었습니다\n");
	}
}

int queue_full(){
	if (rear == MAXSIZE - 1) {
		return TRUE;
	}
	return FALSE;
}

int queue_empty() {
	if (front == -1 && rear == -1) {
		return TRUE;
	}
	else if (front > rear) {
		return TRUE;
	}
	return FALSE;
}

int main() {

	enqueue(10);
	enqueue(20);
	dequeue();
	dequeue();
	dequeue();
	dequeue();

	printf("\nCase 1 : 끝까지 enqueue 할 경우\n");

	for (int num = 0; ; num += 10) {
		if (queue_full() == FALSE) {
			enqueue(num);
			printf("현재 rear의 위치 : %d\n", rear);
			printf("현재 front의 위치 : %d\n\n", front);
		}
		else {
			printf("큐가 포화 상태입니다\n");
			break;
		}
	}

	printf("\nCase 2 : 끝까지 dequeue 할 경우\n");

	while (1) {
		if (queue_empty() == FALSE) {
			dequeue();
			printf("현재 rear의 위치 : %d\n", rear);
			printf("현재 front의 위치 : %d\n\n", front);
		}
		else {
			printf("큐가 비었습니다\n");
			break;
		}
	}

	printf("\nCase 3 : 현재 상태에서 enqueue 할 경우\n");

	enqueue(100);

	return 0;
}