
#include "common.h"

// 배열섞기
void shuffleArr(dataType arr[], int n)
{
    srand(time(NULL));
    if (n > 1)
    {
        for (int i = 0; i < n; i++)
        {
            // i 와 임의의 값 j와 swap
            int j = (i + rand()) % n;
            dataType temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}

dataType randomData()
{
    dataType data;
    if (checkDataType() == INT)
    {
        // data = rand() - RAND_MAX / 2; // integers
        data = rand(); // postive numbers
    }
    else if (checkDataType() == DOUBLE)
    {
        data = (((dataType)rand() / RAND_MAX) * 2 - 1) * 1000;
    }

    return data;
}

void dataInput(dataType arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        // arr[i] = randomData();

        arr[i] = (DATA_SIZE / 2 - i) / 1.125; // 내림차순

        // arr[i] = (i - DATA_SIZE / 2) / 1.125; // 오름차순
    }
}

// 무작위 배열 1~n 범위
void genRandom(dataType arr[], int n)
{
    dataInput(arr, n);
    // shuffleArr(arr, n);
}

int main()
{
    dataType srcArr[DATA_SIZE];
    genRandom(srcArr, DATA_SIZE);

    dataType workArr[DATA_SIZE];
    memcpy(workArr, srcArr, sizeof(dataType) * DATA_SIZE);

    FILE *fp = fopen(UnSortedFileName, "w");

    if (!fp)
    {
        perror("파일 열기 실패"); //에러 출력       
        return 0;                 //프로그램 종료   
    }

    for (int i = 0; i < DATA_SIZE; i++)
    {
        if (checkDataType() == INT)
        {
            fprintf(fp, "%d ", workArr[i]);
        }
        else if (checkDataType() == DOUBLE)
        {
            fprintf(fp, "%.3f ", workArr[i]);
        }
    }

    fclose(fp);

    return 0;
}
