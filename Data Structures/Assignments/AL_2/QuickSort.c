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
#define DATA_SIZE 50000

typedef double dataType;
typedef void fnSort(dataType arr[], int n);

void Swap(dataType arr[], int idx1, int idx2)
{
    dataType temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

// partition array, return the index of where to divide
int Partition(dataType arr[], int left, int right)
{
    dataType pivot = arr[left];
    int low = left + 1;
    int high = right;

    while (low <= high)
    {
        while (arr[low] <= pivot && low <= high)
        {
            low++;
        }
        while (arr[high] >= pivot && high >= (left + 1))
        {
            high--;
        }
        if (low <= high)
        {
            Swap(arr, low, high);
        }
    }
    Swap(arr, left, high);
    return high;
}

// QuickSort recursively
void QuickSort(dataType arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

void QuickSortMain(dataType arr[], int n)
{
    QuickSort(arr, 0, n - 1);
}

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
            fscanf(openFile, "%lf\n", &data);
            workArr[idx++] = data;
        }

        fclose(openFile);
    }

    printf("\nQuickSort\n");

    // printArr(workArr, DATA_SIZE);

    chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "Random Based Array - QuickSort");

    // printArr(workArr, DATA_SIZE);

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

    checkIfSortedWell(workArr, DATA_SIZE);

    return 0;
}