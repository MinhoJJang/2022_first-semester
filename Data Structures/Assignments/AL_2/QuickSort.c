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
#include "common.h"

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

int main()
{
    printf("\nQuickSort\n");

    fileOpen();
    // ============== QuickSort Start ===============
    chkTimeLap(QuickSortMain, workArr, DATA_SIZE, arrayType);
    // ============== QuickSort End ===============
    fileClose();

    return 0;
}