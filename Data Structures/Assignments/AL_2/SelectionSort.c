#include "common.h"

// 1번을 2번~n번까지 훑으면서 제일 작은 수와 위치를 바꿈. 그래서 '선택'정렬임. 제일 작은 수를 '선택'하니까
void SelectionSort(int arr[], int n)
{

    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++) // 비교 사이클 횟수 = n- 1번
    {
        int index = i;

        for (j = i + 1; j < n; j++)
        // 비교 arr[i] 와 arr[i+1]~arr[n-1]까지
        {
            if (arr[index] > arr[j])
            {
                // arr[index]값보다 '더' 작은값을 찾아야하니까 if 조건식을 저렇게 쓰는 게 맞다. 나는 처음에 arr[i] > arr[j] 라고 써서 오류가 생겼다.
                //<<비교>>
                index = j;
            }
        }

        if (index != i)
        {
            temp = arr[i];       // <<이동>> 1사이클당 많아야 1번.
            arr[i] = arr[index]; // <<이동>>
            arr[index] = temp;   // <<이동>>
        }
    }
}