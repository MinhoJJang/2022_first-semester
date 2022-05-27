#include "common.h"

// 1번을 2번~n번까지 훑으면서 제일 작은 수와 위치를 바꿈. 그래서 '선택'정렬임. 제일 작은 수를 '선택'하니까
void SelectionSort(dataType arr[], int n)
{
    int i, j;
    dataType temp;

    for (i = 0; i < n - 1; i++)
    {
        int index = i;

        for (j = i + 1; j < n; j++)
        {

            if (arr[index] > arr[j])
            {
                index = j;
            }
        }

        if (index != i)
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

int main()
{
    fileOpen();

    // ============== SelectionSort Start ===============
    printf("\nSelectionSort\n");
    chkTimeLap(SelectionSort, workArr, DATA_SIZE, "Random Based Array - SelectionSort");
    checkIfSortedWell(workArr, DATA_SIZE);
    // ============== SelectionSort End ===============

    fileClose();
    return 0;
}