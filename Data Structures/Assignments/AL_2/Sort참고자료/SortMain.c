#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <time.h>	// clock .. �ð�, ��¥ �Լ�
//#pragma warning(disable : 4996) // scnaf() �� ���� c�Լ��� ���۹���.
//#pragma warning(disable : 4477) // unsigned <--> signed ���� warning ����

#define DATA_SIZE 100
#include "Sort.h"
#include "HeapSort.h"
#include "QuickSort.h"

int main()
{
	int length;

	// printf("BubbleSort ����\n");
	//{
	//	int data[] = { 3, 2, 7, 5, 1 };
	//	length = sizeof(data) / sizeof(int);
	//	BubbleSort(data, length); // {1,2,3,5,7}
	//	printArr(data, length);
	// }
	//{
	//	int data[] = { 11,3,28,43,9,4 };
	//	length = sizeof(data) / sizeof(int);
	//	BubbleSort(data, length); //
	//	printArr(data, length);
	// }

	// printf("\n");
	// printf("SelectionSort ����\n");
	//{
	//	int data[] = { 1,5,10,2,9 };
	//	int length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, length);
	//	printArr(data, length);
	// }
	//{
	//	int data[] = { 11,3,28,43,9,4 };
	//	length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, length); //
	//	printArr(data, length);
	// }

	// printf("\n");
	// printf("InsertionSort ����\n");
	//{
	//	int data[] = { 1,5,10,2,9 };
	//	int length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, length);
	//	printArr(data, length);
	// }
	//{
	//	int data[] = { 11,3,28,43,9,4 };
	//	length = sizeof(data) / sizeof(int);
	//	InsertionSort(data, length); //
	//	printArr(data, length);
	// }

	//// ��������!!
	//{
	//	int data[] = { 1,2,3,4,5,6,7,8,9 };
	//	for (int i = 0; i < 5; i++) {

	//		shuffleArr(data, 9);
	//		printArr(data, 9 );
	//	}
	//}

	{	// ����� �Լ� ���� Ȯ��
		/*int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);
		printArr(srcArr, DATA_SIZE);
		genIncSorted(srcArr, DATA_SIZE);
		printArr(srcArr, DATA_SIZE);
		genDecSorted(srcArr, DATA_SIZE);
		printArr(srcArr, DATA_SIZE);*/
		// ����� �����ϴ��� Ȯ��
	}

	// ----------------------------------------
	/*printf("\nTime Complexity\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE); // ���� ����
		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int)*DATA_SIZE);
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int)*DATA_SIZE);
		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int)*DATA_SIZE);
		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	}*/

	//-----------------------------------------------------
	/*printf("\nWORST vs. BEST case\n");
	int srcArr[DATA_SIZE];
	//genRandom(srcArr, DATA_SIZE);  // 1. ����
	genIncSorted(srcArr, DATA_SIZE);  // 2. �������� �̹� ���ĵ� �迭
	//genDecSorted(srcArr, DATA_SIZE);  // 3. ��������, �����ĵ� �迭
	int workArr[DATA_SIZE];

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "���ÿ�����");

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "���Կ�����");

	������ (size: 20000) ������: 834 ms
	���÷��� (size: 20000) ������: 378 ms
	���Է��� (size: 20000) ������: 174 ms

	������� (size: 20000) ������: 439 ms
	���ÿ��� (size: 20000) ������: 387 ms
	���Կ��� (size: 20000) ������: 0 ms

	�������� (size: 20000) ������: 607 ms
	���ÿ����� (size: 20000) ������: 346 ms
	���Կ����� (size: 20000) ������: 396 ms
*/

	//---------------------------------------------
	printf("\nHeapSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// workArr�� srcArr�� �����͸� ����ְ� �׸�ŭ�� �޸𸮸� �Ҵ�

		Heap hp;
		heap_init(&hp, DATA_SIZE);

		printArr(workArr, DATA_SIZE); // ������

		chkTimeLap(HeapSort, workArr, DATA_SIZE, "������");

		printArr(workArr, DATA_SIZE); // ������

		heap_destroy(&hp);
	}

	/*printf("\nQuickSort ���� Ȯ��\n");

	{
		int arr[] = { 3,2,4,1,7,6,5 };
		int len = sizeof(arr) / sizeof(int);

		printArr(arr, len); // ������ ��

		QuickSort(arr, 0, len-1);

		printArr(arr, len);
	}*/

	// printf("\nQuickSort\n");
	//{
	//	int srcArr[DATA_SIZE];
	//	int srcArr1[DATA_SIZE];
	//	genRandom(srcArr, DATA_SIZE);
	//	genIncSorted(srcArr1, DATA_SIZE);  // 2. �������� �̹� ���ĵ� �迭
	//     //genDecSorted(srcArr, DATA_SIZE);  // 3. ��������, �����ĵ� �迭

	//	int workArr[DATA_SIZE];
	//	int workArr1[DATA_SIZE];
	//	memcpy(workArr, srcArr, sizeof(int)*DATA_SIZE);

	//	chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������ ����");

	//	//QuickSort�� worst case
	//	memcpy(workArr1, srcArr1, sizeof(int)*DATA_SIZE);

	//	//������ 3000�������� �׽�Ʈ
	//	chkTimeLap(QuickSortMain, workArr1, DATA_SIZE, "������ ��������");
	//	// ���α׷��� ����. ���� �޸𸮸��� ä�������⶧����..
	//}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	return 0;
}