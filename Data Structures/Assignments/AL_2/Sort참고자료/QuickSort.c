#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <time.h>	// clock .. �ð�, ��¥ �Լ�
#include "QuickSort.h"

// �迭 �ΰ��� �ٲٱ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// �迭 ���� ���� �ɰ��� (�ɰ� index ����)
int Partition(int arr[], int left, int right)
{

	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ����! (��)
	int low = left + 1;	   // low �� �ǹ� �����ʿ��� ���� (index)
	int high = right;	   // high �� right ���� ���� (index)

	//
	while (low <= high)
	{
		// low ���� �̵�, pivot ���� ū ���� ����������
		while (arr[low] <= pivot && low <= high)
		{
			low++;
		}

		// high ���� �̵�, pivot ���� ���� ���� ����������!
		while (arr[high] >= pivot && low >= (left + 1))
		{
			high--;
		}

		// low�� high�� ���߸�
		if (low <= high) // low, high�� �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);
	}

	// pivot�� high�� ����Ű�� ���ȯ
	Swap(arr, left, high);

	return high; // �Ű��� �ǹ��� ��ġ���� ����
}

// ��������� ������ ����
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // pivot ���ϰ�, �ѷ��ɰ�
		QuickSort(arr, left, pivot - 1);		 // pivot ���ʿ����� ������
		QuickSort(arr, pivot + 1, right);		 // pivot �����ʿ�����������
	}
}

void QuickSortMain(int arr[], int n)
{
	QuickSort(arr, 0, n - 1);
}