#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int start, int mid, int end) {
	int* output = (int*)malloc((end + 1) * sizeof(int));
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (array[i]<= array[j]){
		output[k] = array[i];
		i++;
		}
		else {
			output[k] = array[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int t = j; t <= end; t++) {
			output[k] = array[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			output[k] = array[t];
			k++;
		}
	}
	for (int t = start; t <= end; t++) {
		array[t] = output[t];
	}
	free(output);
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void mergeSort(int* array, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(array, start, mid);//좌측 정렬
		mergeSort(array, mid + 1, end);//우측 정렬
		merge(array, start, mid, end);
	}
}

int main() {

	printf("\nMerge Sort\n");
	//테스트용 어레이
	int array[8] = { 3,6,7,1,2,4,8,5 };
	int n = sizeof(array) / sizeof(array[0]);
	printf("before:");
	printArray(array, n);
	mergeSort(array, 0, 7);
   //chkTimeLap(mergeSort, workArr, DATA_SIZE);
   //checkIfSortedWell(workArr, DATA_SIZE);
	printf("result:");
	printArray(array, n);

	return 0;
}