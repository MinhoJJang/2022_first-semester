#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <time.h>	// clock .. 시간, 날짜 함수
#include "QuickSort.h"

// 배열 두개값 바꾸기
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// 배열 정렬 영역 쪼개기 (쪼갤 index 리턴)
int Partition(int arr[], int left, int right)
{

	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽! (값)
	int low = left + 1;	   // low 는 피벗 오른쪽에서 시작 (index)
	int high = right;	   // high 는 right 부터 시작 (index)

	//
	while (low <= high)
	{
		// low 우측 이동, pivot 보다 큰 것을 만날때까지
		while (arr[low] <= pivot && low <= high)
		{
			low++;
		}

		// high 좌측 이동, pivot 보다 작은 것을 만날때까지!
		while (arr[high] >= pivot && low >= (left + 1))
		{
			high--;
		}

		// low와 high가 멈추면
		if (low <= high) // low, high가 교차되지 않은 상태라면 Swap 진행
			Swap(arr, low, high);
	}

	// pivot과 high가 가리키는 대상교환
	Swap(arr, left, high);

	return high; // 옮겨진 피벗의 위치정보 리턴
}

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // pivot 정하고, 둘로쪼갬
		QuickSort(arr, left, pivot - 1);		 // pivot 왼쪽영역을 퀵정렬
		QuickSort(arr, pivot + 1, right);		 // pivot 오른쪽영역을퀵정렬
	}
}

void QuickSortMain(int arr[], int n)
{
	QuickSort(arr, 0, n - 1);
}