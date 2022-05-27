#include "common.h"

// n개의 데이터 중에서 앞에서부터 i개 만큼을 정렬한다. 정렬 방식은 버블정렬과 비슷하나 뒤에서부터 정렬시작한다는 점, 정렬된 순간부터 break된다는 점에서 차이가 있음.
void InsertionSort(int arr[], int n)
{
    int i, j;
    int insData; // 데이터 임시 보관소

    for (i = 1; i < n; i++)
    {

        insData = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (insData < arr[j])
            {                        // 비교
                arr[j + 1] = arr[j]; // <<이동>>
                                     // 바로 바로 값 바꿔주어야함
                                     // P.S. 그냥 위치를 찾는게 더 빠르지 않을까? 값을 바꾸는것보다..?
                                     // 어차피 위치를 찾아도 자리이동해야하네..
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = insData; // <<이동>> 1사이클당 1번
    }
}