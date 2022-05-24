#ifndef __SORT_H__
#define __SORT_H__

void printArr(int arr[], int n); // 정렬된것 보여주는 함수

// 무작위 배열 1~n 범위
void genRandom(int arr[], int n);

// 오름차순 배열
void genIncSorted(int arr[], int n);

// 내림차순 배열
void genDecSorted(int arr[], int n);

// 배열섞기
void shuffleArr(int arr[], int n);

// 정렬함수 성능 측정
typedef void fnSort(int arr[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle);

void BubbleSort(int arr[], int n); // 버블 정렬
void SelectionSort(int arr[], int n);
void InsertionSort(int arr[], int n);

#endif
