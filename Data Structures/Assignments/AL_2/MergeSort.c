#include "common.h"

void merge(dataType *array, int start, int mid, int end)
{
	dataType *output = (dataType *)malloc((end + 1) * sizeof(dataType));
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}

	if (i > mid)
	{
		for (int t = j; t <= end; t++)
		{
			output[k] = array[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= mid; t++)
		{
			output[k] = array[t];
			k++;
		}
	}
	for (int t = start; t <= end; t++)
	{
		array[t] = output[t];
	}
	free(output);
}

void mergeSort(dataType array[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(array, start, mid);	//좌측 정렬
		mergeSort(array, mid + 1, end); //우측 정렬
		merge(array, start, mid, end);
	}
}

void MergeSortMain(dataType arr[], int n)
{
	mergeSort(arr, 0, n - 1);
}

int main()
{
	printf("\nMerge Sort\n");

	fileOpen();
	// ============== MergeSort Start ===============
	chkTimeLap(MergeSortMain, workArr, DATA_SIZE, arrayType);
	// ============== MergeSort End ===============
	fileClose();

	return 0;
}