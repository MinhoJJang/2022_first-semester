#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <time.h>	// clock .. �ð�, ��¥ �Լ�

#include "Sort.h"

void printArr(int arr[], int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

// ������ �迭 1~n ����
void genRandom(int arr[], int n)
{
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}

// �������� �迭
void genIncSorted(int arr[], int n)
{

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
}

// �������� �迭
void genDecSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = n - i;
}

// �迭����
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			// i �� ������ i �������� j ��°�� swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

// �����Լ� ���� ����
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle)
{
	clock_t start, end;
	start = clock();

	sort(arr, n); // ���� ����

	end = clock();

	printf("%s (size: %d) ������: %ld ms\n", szTitle, n, end - start);
}

// �ܼ��ϰ� 1��2��, 2��3��, 3��4�� �̷��� ���Ͽ� n-1��n�� ���� �����ϴ°� 1����Ŭ. �׷��� ����Ŭ�� �ݺ��Ѵ�.
void BubbleSort(int arr[], int n) // ���� ����
{
	int i, j;
	int temp;

	// cycle ȸ�� Ƚ��
	for (i = 0; i < n - 1; i++)
	{

		// ��Ƚ��
		for (j = 0; j < (n - i) - 1; j++)
		{

			// 1. ������ �ΰ� ��
			if (arr[j] > arr[j + 1]) // 2. ũ�Ⱑ �ݴ���.. <<��>>
			{
				temp = arr[j];		 // <<�̵�>> �� ����Ŭ�� �ִ� (n-i)-1�� �߻� (�׳� �� for���� j�ִ�ġ��ŭ �߻��Ѵٴ� �Ҹ���)
				arr[j] = arr[j + 1]; // <<�̵�>>
				arr[j + 1] = temp;	 // <<�̵�>>
			}
		}
	}
}

// 1���� 2��~n������ �����鼭 ���� ���� ���� ��ġ�� �ٲ�. �׷��� '����'������. ���� ���� ���� '����'�ϴϱ�
void SelectionSort(int arr[], int n)
{

	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) // �� ����Ŭ Ƚ�� = n- 1��
	{
		int index = i;

		for (j = i + 1; j < n; j++)
		// �� arr[i] �� arr[i+1]~arr[n-1]����
		{
			if (arr[index] > arr[j])
			{
				// arr[index]������ '��' �������� ã�ƾ��ϴϱ� if ���ǽ��� ������ ���� �� �´�. ���� ó���� arr[i] > arr[j] ��� �Ἥ ������ �����.
				//<<��>>
				index = j;
			}
		}

		if (index != i)
		{
			temp = arr[i];		 // <<�̵�>> 1����Ŭ�� ���ƾ� 1��.
			arr[i] = arr[index]; // <<�̵�>>
			arr[index] = temp;	 // <<�̵�>>
		}
	}
}

// n���� ������ �߿��� �տ������� i�� ��ŭ�� �����Ѵ�. ���� ����� �������İ� ����ϳ� �ڿ������� ���Ľ����Ѵٴ� ��, ���ĵ� �������� break�ȴٴ� ������ ���̰� ����.
void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData; // ������ �ӽ� ������

	for (i = 1; i < n; i++)
	{

		insData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (insData < arr[j])
			{						 // ��
				arr[j + 1] = arr[j]; // <<�̵�>>
									 // �ٷ� �ٷ� �� �ٲ��־����
									 // P.S. �׳� ��ġ�� ã�°� �� ������ ������? ���� �ٲٴ°ͺ���..?
									 // ������ ��ġ�� ã�Ƶ� �ڸ��̵��ؾ��ϳ�..
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = insData; // <<�̵�>> 1����Ŭ�� 1��
	}
}