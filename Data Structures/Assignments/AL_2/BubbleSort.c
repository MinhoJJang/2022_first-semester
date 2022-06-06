#include "common.h"

// 단순하게 1번2번, 2번3번, 3번4번 이렇게 비교하여 n-1번n번 까지 정렬하는게 1사이클. 그렇게 사이클을 반복한다.
void BubbleSort(dataType arr[], int n) // 버블 정렬
{
    int i, j;
    dataType temp;

    // cycle 회전 횟수
    for (i = 0; i < n - 1; i++)
    {
        // 비교횟수
        for (j = 0; j < (n - i) - 1; j++)
        {
            // 1. 인접한 두개 비교
            if (arr[j] > arr[j + 1]) // 2. 크기가 반대라면.. <<비교>>
            {
                temp = arr[j];       // <<이동>> 한 사이클당 최대 (n-i)-1번 발생 (그냥 위 for문의 j최대치만큼 발생한다는 소리)
                arr[j] = arr[j + 1]; // <<이동>>
                arr[j + 1] = temp;   // <<이동>>
            }
        }
    }
}

int main()
{
    printf("\nBubbleSort\n");

    fileOpen();
    // ============== BubbleSort Start ===============
    chkTimeLap(BubbleSort, workArr, DATA_SIZE, arrayType);
    // ============== BubbleSort End ===============
    fileClose();

    return 0;
}