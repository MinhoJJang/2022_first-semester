#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
=====================================================
QuickSort - Degree of performance

# Part 1

positive numbers
integers (including positives, 0, and negatives)
double precision numbers (e.g. -1000.000 < number < +1000.000)

> achieve Level 3

# Part 2

Category 2: QuickSort

# Part 3

Load the generated lists from files / Save the evaluation results as separate files.
The sorting correctness
The running time

# Part 4

//TODO

=====================================================
*/
#define FNAME "Sorted.dat"
#define DATA_SIZE 50
typedef double dataType;
typedef void fnSort(dataType arr[], int n);

// 배열 두개값 바꾸기
void Swap(dataType arr[], int idx1, int idx2)
{
    dataType temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

// 배열 정렬 영역 쪼개기 (쪼갤 index 리턴)
int Partition(dataType arr[], int left, int right)
{

    dataType pivot = arr[left]; // 피벗의 위치는 가장 왼쪽! (값)
    int low = left + 1;         // low 는 피벗 오른쪽에서 시작 (index)
    int high = right;           // high 는 right 부터 시작 (index)

    //
    while (low <= high)
    {
        // low 우측 이동, pivot 보다 큰 것을 만날때까지
        while (arr[low] <= pivot && low <= high)
        {
            low++;
        }

        // high 좌측 이동, pivot 보다 작은 것을 만날때까지!
        while (arr[high] >= pivot && high >= (left + 1))
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
void QuickSort(dataType arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right); // pivot 정하고, 둘로쪼갬
        QuickSort(arr, left, pivot - 1);         // pivot 왼쪽영역을 퀵정렬
        QuickSort(arr, pivot + 1, right);        // pivot 오른쪽영역을퀵정렬
    }
}

void QuickSortMain(dataType arr[], int n)
{
    QuickSort(arr, 0, n - 1);
}

// 정렬함수 성능 측정
void chkTimeLap(fnSort sort, dataType arr[], int n, char *sortTitle)
{
    clock_t start, end;
    start = clock();

    sort(arr, n); // 정렬 수행

    end = clock();

    printf("%s (size: %d) 수행결과: %ld ms\n", sortTitle, n, end - start);
}

void printArr(dataType arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        // 1. 배열이 int 타입일 경우
        // printf("%d ", arr[i]);

        // 2. 배열이 double 타입일 경우
        printf("%.3f ", arr[i]);
    }
    printf("]\n");
}

// 정렬되었는지 확인하는 함수
void checkIfSortedWell(dataType arr[], int n)
{
    // 오름차순 정렬이라고 가정할 때, 앞의 값이 바로 뒤의 값보다 항상 작아야 한다.
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("It's Not Sorted!\n");
            return;
        }
    }
    printf("It's Sorted Well! :)\n");
}

int main(int argc, char *argv[])
{
    FILE *openFile = fopen("unSorted.dat", "r");
    dataType workArr[DATA_SIZE];
    int idx = 0;
    if (openFile == 0)
    {
        printf("Could not open file\n");
    }
    else
    {
        dataType data;
        while (!feof(openFile))
        {
            //공백으로 분리된 파일 읽기
            fscanf(openFile, "%lf\n", &data);
            workArr[idx++] = data;
        }

        fclose(openFile);
    }

    printf("\nQuickSort\n");

    // printArr(workArr, DATA_SIZE);

    chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬 랜덤");

    printArr(workArr, DATA_SIZE);

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

    checkIfSortedWell(workArr, DATA_SIZE);

    return 0;
}