#include <stdio.h>
#include <stdlib.h>				// malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h>				//strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <time.h>				// clock .. 시간, 날짜 함수
#pragma warning(disable : 4996) // scnaf() 등 전통 c함수중 버퍼문제.
#pragma warning(disable : 4477) // unsigned <--> signed 관련 warning 무시

#define SUCCESS 1
#define FAIL 0
#define ROOTIDX 1
#define SUCCESS 1
#define FAIL 0
#define DATA_SIZE 50
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
Heap *g_hp;
// -----------------------------------------
// 노드 인덱스 계산 매크로 (성능 향상)
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx/2 우측으로 shift동작
// 함수호출이 아니라 해당 함수를 그냥 대입시킴. 시간적 이득
#define GET_LEFT_IDX(idx) ((idx) << 1)		  // idx*2 = 좌측으로 1칸
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // 상수연산자가 비트연산자보다 우선순위가 크므로 괄호 묶어주기

// 비교함수 대신 매크로 (성능 up)
#define COMP_ASC(d1, d2) ((d2) - (d1))	// 오름차순
#define COMP_DESC(d1, d2) ((d1) - (d2)) // 내림차순

// idx의 자식들 중 우선순위가 높은 자식의 index값 리턴 --> delete 에 사용
int getHighPriority(Heap *ph, int idx)
{
	// 자식노드가 없다면 0리턴
	if (GET_LEFT_IDX(idx) > ph->numData)
		return 0;

	// 자식노드가 1개라면 (왼쪽 노드가 유일)
	if (GET_LEFT_IDX(idx) == ph->numData)
		return GET_LEFT_IDX(idx);

	// 우선순위
	if (COMP_DESC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
	{
		idx = GET_RIGHT_IDX(idx);
	}
	else
	{
		idx = GET_LEFT_IDX(idx);
	}

	/*if (ph->heapArr[getLeftIdx(idx)] >= ph->heapArr[getRightIdx(idx)]) {
		idx = getLeftIdx(idx);
	}
	else {
		idx = getRightIdx(idx);
	} */
	//라고 해도 되지만 우리는 comp함수가 있으니 그걸 쓰자

	return idx;
}

// 힙 초기화
void heap_init(Heap *ph, int len)
{
	ph->numData = 0; // 데이터(노드)개수 0
	ph->heapArr = (int *)malloc(sizeof(int) * (len + 1));
	// complete binary tree의 배열은 1번부터 시작하므로 0번은 값이 없다. 그래서 len+1만큼의 size가 필요함. 이러한 배열을 1-based 배열이라고 부름

	g_hp = ph; // 힙정렬에 필요
}

void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// 힙이 비어있는지?
int heap_is_empty(Heap *ph)
{
	if (ph->numData == 0)
		return SUCCESS;
	return FAIL;
}

// 힙에 데이터 추가 insert
void heap_insert(Heap *ph, HData data)
{

	// 새로 insert되는 데이터는 맨 끝에서 시작
	int idx = ph->numData + 1;
	// ph->numData 는 현재있는 노드개수이므로 새로 들어가는 값인 idx는 노드개수+1번째에 들어가야한다.
	// 또한 배열 인덱스는 배열이 0부터 시작하는 것과는 다르게 1부터 시작한다. 그래야 부모자식의 인덱스값이 서로 연관성을 갖게되어 계산이 편리하기 때문

	// 아래 while 문 수행하면서 새로 INSERT된 data가 위치할 idx를 결정 (값을 결정하는게 아님. 값의 위치를 결정하는것)
	while (idx != 1) // root (최상위) 에 도달할때 까지
	{
		// 부모와 우선순위 비교
		if (COMP_DESC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) // 부모보다 우선순위가 높다면
		{
			// 부모를 끌어내리기
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// idx 를 부모의 idx로 이동
			idx = GET_PARENT_IDX(idx);
		}
		// 새로 넣은 값의 번호가 idx임
		else // 부모보다 우선순위가 낮거나 같다.. 여기서 while 멈춰야함
		{
			break;
		}
	}

	// idx가 결정된 그곳이 새로 INSERT된 data가 들어갈 위치
	ph->heapArr[idx] = data;
	ph->numData++;
}

// 힙에 데이터 빼기 delete. 삭제는 root에서 발생
HData heap_delete(Heap *ph)
{
	// root값 없애기
	HData rootData = ph->heapArr[ROOTIDX]; // 인덱스 1번이 루트 노드, 이를 제거하고 리턴

	// 마지막 노드가 자리잡을 위치 idx 를 결정해야 한다 .
	// idx가 결정될때까지 마지막 노드의 data는 보관해 놓는다.

	HData lastElem = ph->heapArr[ph->numData];
	// 마지막노드의 값을 저장해놓기

	int idx = ROOTIDX; // 마지막 노드가 일단 root 자리에 오게 된다.
	int childIdx;

	while (childIdx = getHighPriority(ph, idx))
	// 저 대입연산자 자체가 결과값이 있음. 대입한 값 자체가 결과값임.
	// 0일경우 false 이므로 while을 타지 않는다. 즉, getHighPriority 함수가 return 0; 을 하는 경우는 자식노드가 없을 경우이므로, if문에서 break 되지 않는다면 자식노드가 없을 때까지 수행한다는 의미이다. 1번 idx, 즉 ROOTIDX부터 차근차근 내려가면서 조건에 맞는 값이 존재하는 idx를 찾는다.
	{
		if (COMP_DESC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[idx] = ph->heapArr[childIdx];

		idx = childIdx;
	}

	ph->heapArr[idx] = lastElem;
	// ph->heapArr[ph->numData] = NULL;
	ph->numData--;

	return rootData;
}

void HeapSort(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		heap_insert(g_hp, arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = heap_delete(g_hp);
	}
	// 그냥 insert하고 그대로 delete하면 arr에 정렬된 순서대로 데이터가 들어올것임.
}

// 배열섞기
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			// i 와 임의의 i 오른쪽의 j 번째와 swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}
typedef void fnSort(int arr[], int n);

// 정렬함수 성능 측정
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle)
{
	clock_t start, end;
	start = clock();

	sort(arr, n); // 정렬 수행

	end = clock();

	printf("%s (size: %d) 수행결과: %ld ms\n", szTitle, n, end - start);
}

void printArr(int arr[], int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

// 오름차순 배열
void genIncSorted(int arr[], int n)
{

	for (int i = 0; i < n; i++)
		arr[i] = i - DATA_SIZE / 2;
}

// 내림차순 배열
void genDecSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = n - i;
}

// 무작위 배열 1~n 범위
void genRandom(int arr[], int n)
{
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}

int main()
{
	printf("\nHeapSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// workArr에 srcArr의 데이터를 집어넣고 그만큼의 메모리를 할당

		Heap hp;
		heap_init(&hp, DATA_SIZE);

		printArr(workArr, DATA_SIZE); // 정렬전

		chkTimeLap(HeapSort, workArr, DATA_SIZE, "힙정렬");

		printArr(workArr, DATA_SIZE); // 정렬후

		heap_destroy(&hp);
	}
	return 0;
}