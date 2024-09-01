#include"sort1.h"
//交换
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 插入排序
void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
			a[end + 1] = tmp;
		}
	}

}

// 希尔排序
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

// 选择排序
void SelectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	while(begin < end){
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++) {
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		Swap(&a[min], &a[begin]);
		if (a[max] < a[min])
			max = min;
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}


// 堆排序
void AdjustDwon(int* a, int n, int root) {
	int child = root * 2 + 1;
	while(child < n){

		if (child + 1 < n && a[child + 1] > a[child]) {
			child++;
		}

		if (a[root] < a[child]) {
			Swap(&a[root], &a[child]);
			root = child;
			child = root * 2 + 1;
		}

		else {
			break;
		}
	}

}
void HeapSort(int* a, int n) {
	int parent = (n - 1 - 1) / 2;
	while (parent >= 0) {
		AdjustDwon(a, n, parent);
		parent--;
	}

	int i = n - 1;
	while (i >= 0) {
		Swap(&a[0], &a[i]);
		AdjustDwon(a, i, 0);
		i--;
	}

}

// 冒泡排序
void BubbleSort(int* a, int n) {
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - j; i++) {
			if (a[i] > a[i + 1]) {
				Swap(&a[i], &a[i + 1]);
			}
		}
	}

}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);

// 快速排序挖坑法
int PartSort2(int* a, int left, int right);

// 快速排序前后指针法
int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);