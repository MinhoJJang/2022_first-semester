#ifndef __COMMON_H__

#define __COMMON_H__
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define type(x) _Generic((x), int        \
                         : "int", double \
                         : "double")
#define INT 0
#define DOUBLE 1
#define SAME 0
#define UnSortedFileName "unSorted.dat"
#define SortedFileName "Sorted.dat"

// ========유동적 데이터값========
#define DATA_SIZE 3000
#define NUMBER_OF_DATA 100
typedef int dataType;
// ===============================

typedef void fnSort(dataType arr[], int n);
dataType workArr[DATA_SIZE];
dataType typeCheck;

int checkDataType()
{
    if (strcmp(type(typeCheck), "int") == SAME)
    {
        return INT;
    }
    else if (strcmp(type(typeCheck), "double") == SAME)
    {
        return DOUBLE;
    }
}

// Time Check Function
void chkTimeLap(fnSort sort, dataType arr[], int n, char *sortTitle)
{
    long avg_time = 0;
    dataType base[DATA_SIZE];
    memcpy(base, arr, sizeof(dataType) * DATA_SIZE);
    for (int i = 0; i < NUMBER_OF_DATA; i++)
    {
        memcpy(arr, base, sizeof(dataType) * DATA_SIZE);
        clock_t start, end;
        start = clock();
        sort(arr, n);
        end = clock();
        avg_time += (end - start);
        // printf("(size: %d) Running Time: %ld ms\n", n, end - start);
    }
    avg_time /= NUMBER_OF_DATA;
    printf("%s (size: %d) %d data - Average Time: %ld ms\n", sortTitle, n, NUMBER_OF_DATA, avg_time);
}

// void printArr(dataType arr[], int n)
// {
//     printf("[ ");
//     for (int i = 0; i < n; i++)
//     {
//         if (checkDataType() == INT)
//         {
//             printf("%d ", arr[i]);
//         }
//         else if (checkDataType() == DOUBLE)
//         {
//             printf("%.3f ", arr[i]);
//         }
//     }
//     printf("]\n");
// }

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

            if (checkDataType() == INT)
            {
                fscanf(openFile, "%d\n", &data);
            }
            else if (checkDataType() == DOUBLE)
            {
                fscanf(openFile, "%lf\n", &data);
            }
            workArr[idx++] = data;
        }

        fclose(openFile);
    }
}

void fileClose()
{
    FILE *fp = fopen(SortedFileName, "w");

    if (!fp)
    {
        perror("File Open Fail");
        return 0;
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
}

#endif