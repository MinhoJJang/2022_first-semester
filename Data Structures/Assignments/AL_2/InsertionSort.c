#include "common.h"

// n개의 데이터 중에서 앞에서부터 i개 만큼을 정렬한다. 정렬 방식은 버블정렬과 비슷하나 뒤에서부터 정렬시작한다는 점, 정렬된 순간부터 break된다는 점에서 차이가 있음.
void InsertionSort(dataType arr[], int n)
{
    int i, j;
    dataType insData;
    for (i = 1; i < n; i++)
    {
        insData = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (insData < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = insData; // <<이동>> 1사이클당 1번
    }
}

int main()
{
    printf("\nInsertionSort\n");

    fileOpen();
    // ============== InsertionSort Start ===============
    chkTimeLap(InsertionSort, workArr, DATA_SIZE, arrayType);
    // ============== InsertionSort End ===============
    fileClose();

    return 0;
}
