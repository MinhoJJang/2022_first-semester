#ifndef __HEAP_H__
#define __HEAP_H__

//#define HEAP_LEN

#define SUCCESS 1
#define FAIL 0
/* Heap의 데이터*/

typedef int HData;

typedef int fnPriorityComp(HData d1, HData d2);
// 두 데이터를 비교해 어떤 것이 크거나 같은지 알아내는 함수-의 타입을 정의한것임..
// d1의 우선순위가 높다면 0보다 큰 값 리턴
// d2의 우선순위가 높다면 0보다 작은 값 리턴
// d1 = d2면 0리턴

typedef struct _heap
{
	int numData;		  // 담고있는 데이터개수
	HData *heapArr;		  // 동적메모리로 구현
	fnPriorityComp *comp; // 우선순위 비교함수
						  // 함수타입 포인터 comp
} Heap;

/* Heap의 동작*/

// 힙 초기화
// void heap_init(Heap *ph, fnPriorityComp pc);
void heap_init(Heap *ph, int len); // 힙초기화
void heap_destroy(Heap *ph);

// 힙이 비어있는지?
int heap_is_empty(Heap *ph);

// 힙에 데이터 추가 insert
void heap_insert(Heap *ph, HData data);

// 힙에 데이터 빼기 delete
HData heap_delete(Heap *ph);

// 힙정렬
Heap *g_hp;
void HeapSort(int arr[], int n);

#endif
