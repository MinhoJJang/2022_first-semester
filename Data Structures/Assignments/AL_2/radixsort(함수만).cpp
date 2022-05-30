#include "common.h"

int getMax(int array[], int n) {
	int max = array[0];
	for (int i = 0; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

void countSort(int array[], int size, int place) {
	int* output = (int*)malloc(sizeof(int) * (size + 1));
	int max = (array[0] / place) % 10;

	for (int i = 1; i < size; i++) {
		if (((array[i] / place) % 10) > max) {
			max = array[i];
		}
	}

	int* count = (int*)malloc(sizeof(int) * (max + 1));

	for (int i = 0; i < max; ++i) {
		count[i] = 0;
	}

	//calculate count of element
	for (int i = 0; i < size; i++) {
		count[(array[i] / place) % 10]++;
	}
	//calculate cumulative count
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	//place the elments in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++) {
		array[i] = output[i];
	}
}
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}
void radixSort(int array[], int size) {
	int m = getMax(array, size);
	int count = 1;
	for (int place = 1; m / place > 0; place *= 10) {
		countSort(array, size, place);
		printf("pass %d: ", count);
		printArray(array, size);
		count++;
	}
}

int main() {
	printf("\nRadix Sort\n");
	fileOpen();
	radixSort(workArr, DATA_SIZE);
	printf("\nresult:");
	printArray(workArr,  DATA_SIZE);
	fileClose();
}