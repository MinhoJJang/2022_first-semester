#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

// �迭 �ΰ��� �ٲٱ�
void Swap(int arr[], int idx1, int idx2);

// �迭 ���� ���� �ɰ��� (�ɰ� index ����)
int Partition(int arr[], int left, int right);

// ��������� ������ ����
void QuickSort(int arr[], int left, int right);

// ���� üũ�� �Լ�
void QuickSortMain(int arr[], int n);




#endif
