#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

// 배열 두개값 바꾸기
void Swap(int arr[], int idx1, int idx2);

// 배열 정렬 영역 쪼개기 (쪼갤 index 리턴)
int Partition(int arr[], int left, int right);

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right);

// 성능 체크용 함수
void QuickSortMain(int arr[], int n);




#endif
