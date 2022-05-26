#include <stdio.h>
#include <stdlib.h>

#define FNAME "unSorted.dat"
typedef double dataType;
#define DATA_SIZE 50000

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

// dataType가 Double인 경우만 사용
double randomDouble()
{

    double a = (((double)rand() / RAND_MAX) * 2 - 1) * 1000;
    return a;
}

// 오름차순 배열
// double타입의 경우 그냥 삽입부터 랜덤임
void genIncSorted(dataType arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        // 1. 배열이 int 타입일 경우
        // arr[i] = i - DATA_SIZE / 2;

        // 2. 배열이 double 타입일 경우

        // arr[i] = randomDouble();

        // arr[i] = (DATA_SIZE / 2 - i) / 2.125; // 내림차순

        arr[i] = (i - (DATA_SIZE / 2)) / 2.125; // 오름차순
    }
}

// 무작위 배열 1~n 범위
void genRandom(dataType arr[], int n)
{
    genIncSorted(arr, n);
    shuffleArr(arr, n);
}

int main()
{
    dataType srcArr[DATA_SIZE];
    genRandom(srcArr, DATA_SIZE);

    dataType workArr[DATA_SIZE];
    memcpy(workArr, srcArr, sizeof(dataType) * DATA_SIZE);

    FILE *fp = fopen(FNAME, "w");

    if (!fp)
    {
        perror("파일 열기 실패"); //에러 출력       
        return 0;                 //프로그램 종료   
    }

    for (int i = 0; i < DATA_SIZE; i++)
    {
        // fprintf(fp, "%d ", workArr[i]);
        fprintf(fp, "%.3f ", workArr[i]);
    }

    fclose(fp);

    return 0;
}