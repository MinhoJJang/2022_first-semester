/*
=====================================================
author - 202033762 Jang Minho
HeapSort - Degree of performance

# Part 1

positive numbers
integers (including positives, 0, and negatives)
double precision numbers (e.g. -1000.000 < number < +1000.000)

> achieve Level 3

# Part 2

Category 2: HeapSort

# Part 3

Load the generated lists from files / Save the evaluation results as separate files.
The sorting correctness
The running time

# Part 4

//TODO

// If duplicate data is needed??? That means I have to change the data type everything..........

=====================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SUCCESS 1
#define FAIL 0
#define ROOTIDX 1
#define SUCCESS 1
#define FAIL 0
#define DATA_SIZE 50000
#define FNAME "Sorted.dat"

#define GET_PARENT_IDX(idx) ((idx) >> 1)
#define GET_LEFT_IDX(idx) ((idx) << 1)
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1)

#define COMP_ASC(d1, d2) ((d2) - (d1))
#define COMP_DESC(d1, d2) ((d1) - (d2))

typedef double dataType;
typedef int fnPriorityComp(dataType d1, dataType d2);
typedef void fnSort(dataType arr[], int n);
typedef struct _heap
{
    int numData;
    dataType *heapArr;
    fnPriorityComp *comp;
} Heap;
Heap *g_hp;

// return the highest priority child's index
int getHighPriority(Heap *ph, int idx)
{
    if (GET_LEFT_IDX(idx) > ph->numData)
    {
        return 0;
    }

    if (GET_LEFT_IDX(idx) == ph->numData)
    {
        return GET_LEFT_IDX(idx);
    }

    if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
    {
        idx = GET_RIGHT_IDX(idx);
    }
    else
    {
        idx = GET_LEFT_IDX(idx);
    }

    return idx;
}

void heap_init(Heap *ph, int len)
{
    ph->numData = 0;
    ph->heapArr = (dataType *)malloc(sizeof(dataType) * (len + 1)); // 1-based array
    g_hp = ph;
}

void heap_destroy(Heap *ph)
{
    free(ph->heapArr);
    memset(ph, 0, sizeof(Heap));
}

int heap_is_empty(Heap *ph)
{
    if (ph->numData == 0)
        return SUCCESS;
    return FAIL;
}

void heap_insert(Heap *ph, dataType data)
{
    int idx = ph->numData + 1;

    while (idx != 1)
    {
        if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
            idx = GET_PARENT_IDX(idx);
        }
        else
        {
            break;
        }
    }

    ph->heapArr[idx] = data;
    ph->numData++;
}

dataType heap_delete(Heap *ph)
{

    dataType rootData = ph->heapArr[ROOTIDX];
    dataType lastElem = ph->heapArr[ph->numData];

    int idx = ROOTIDX;
    int childIdx;

    while (childIdx = getHighPriority(ph, idx))
    {
        if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
        {
            break;
        }
        ph->heapArr[idx] = ph->heapArr[childIdx];
        idx = childIdx;
    }

    ph->heapArr[idx] = lastElem;
    ph->numData--;

    return rootData;
}

void HeapSort(dataType arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        heap_insert(g_hp, arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = heap_delete(g_hp);
    }
}

// 정렬함수 성능 측정
void chkTimeLap(fnSort sort, dataType arr[], int n, char *sortTitle)
{
    clock_t start, end;
    start = clock();
    sort(arr, n); // 정렬 수행
    end = clock();
    printf("%s (size: %d) Running time: %ld ms\n", sortTitle, n, end - start);
}

void printArr(dataType arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", arr[i]);
        printf("%.3f ", arr[i]);
    }
    printf("]\n");
}

void checkIfSortedWell(dataType arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("It's Not Sorted!\n");
            return;
        }
    }
    printf("Sorted Well! :)\n");
}

int main()
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
            fscanf(openFile, "%lf\n", &data);
            workArr[idx++] = data;
        }

        fclose(openFile);
    }

    printf("\nHeapSort\n");

    Heap hp;
    heap_init(&hp, DATA_SIZE);

    // printArr(workArr, DATA_SIZE);

    chkTimeLap(HeapSort, workArr, DATA_SIZE, "Random Based Array - HeapSort");

    // printArr(workArr, DATA_SIZE);
    checkIfSortedWell(workArr, DATA_SIZE);

    FILE *fp = fopen(FNAME, "w");

    if (!fp)
    {
        perror("File Open Fail");
        return 0;
    }

    for (int i = 0; i < DATA_SIZE; i++)
    {
        // fprintf(fp, "%d ", workArr[i]);
        fprintf(fp, "%.3f ", workArr[i]);
    }

    fclose(fp);

    heap_destroy(&hp);

    return 0;
}