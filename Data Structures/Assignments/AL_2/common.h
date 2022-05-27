#ifndef __COMMON_H__

#define __COMMON_H__
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define UnSortedFileName "unSorted.dat"
#define SortingFileName "Sorted.dat"
#define DATA_SIZE 50000
typedef double dataType;
typedef void fnSort(dataType arr[], int n);
dataType workArr[DATA_SIZE];

// Time Check Function
void chkTimeLap(fnSort sort, dataType arr[], int n, char *sortTitle)
{
    clock_t start, end;
    start = clock();
    sort(arr, n);
    end = clock();
    printf("%s (size: %d) Running Time: %ld ms\n", sortTitle, n, end - start);
}

void printArr(dataType arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        // 1. if dataType is int
        // printf("%d ", arr[i]);

        // 2. if dataType is double
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

void fileOpen()
{
    FILE *openFile = fopen("unSorted.dat", "r");
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
            // fscanf(openFile, "%d\n", &data);
            workArr[idx++] = data;
        }

        fclose(openFile);
    }
}

void fileClose()
{
    FILE *fp = fopen(SortingFileName, "w");

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
}

#endif