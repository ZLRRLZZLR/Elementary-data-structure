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
	int flag = 1;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - j; i++) {
			if (a[i] > a[i + 1]) {
				Swap(&a[i], &a[i + 1]);
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}

}

// 快速排序递归实现
//优化：三数取中
int GetMid(int* a, int left, int right) {
	int mid = (left + right) / 2;
	if (a[left] > a[mid]) {
		if (a[mid] > a[right]) {
			return mid;
		}
		else if (a[right] > a[left]) {
			return left;
		}
		else {
			return right;
		}
	}
	else {
		if (a[mid] < a[right]) {
			return mid;
		}
		else if (a[right] > a[left]) {
			return right;
		}
		else {
			return left;
		}
	}
}


// 快速排序hoare版本
void QuickSort1(int* a, int left, int right) {
	if (left >= right)
		return;
	//小区间优化
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//三数取中
	int tmp = GetMid(a,left,right);
	Swap(&a[left],&a[tmp]);

	int key = left;
	int begin = left;
	int end = right;
	while (begin < end) {
		while (begin < end && a[end] >= a[key]) {
			end--;
		}
		while (begin < end && a[begin] <= a[key]) {
			begin++;
		}
		Swap(&a[begin],&a[end]);
	}
	Swap(&a[key],&a[begin]);

	QuickSort1(a, left, begin - 1);
	QuickSort1(a, begin + 1, right);

}

// 快速排序挖坑法
void QuickSort2(int* a, int left, int right) {
	if (left >= right)
		return;
	//小区间优化
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//三数取中
	int tmp = GetMid(a, left, right);
	Swap(&a[left], &a[tmp]);

	int key = a[left];
	int begin = left;
	int end = right;
	while (begin < end) {
		while (begin < end && a[end] >= a[key]) {
			end--;
		}

		a[begin] = a[end];

		while (begin < end && a[begin] <= a[key]) {
			begin++;
		}

		a[end] = a[begin];
	}
	a[begin] = key;

	QuickSort2(a, left, begin - 1);
	QuickSort2(a, begin + 1, right);

}

// 快速排序前后指针法
void QuickSort3(int* a, int left, int right) {
	if (left >= right)
		return;

	//小区间优化
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//三数取中
	int tmp = GetMid(a, left, right);
	Swap(&a[left], &a[tmp]);

	int key = left;
	int prev = left;
	int cur = prev + 1;

 	while (cur <= right) {
		if (a[key] > a[cur] && ++prev != cur) {
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[key]);

	QuickSort3(a, left, prev - 1);
	QuickSort3(a, prev + 1, right);
}

// 快速排序优化之三路划分
void QuickSort4(int* a, int left, int right) {
	if (left >= right)
		return;
	//小区间优化
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//三数取中
	int tmp = GetMid(a, left, right);
	Swap(&a[left], &a[tmp]);


	int key = a[left];
	int begin = left;
	int end = right;
	int cur = left + 1;

	while (cur <= end) {
		if (a[cur] > key) {
			Swap(&a[cur], &a[right]);
		}
		else if (a[cur] < key) {
			Swap(&a[cur], &a[left]);
			left--;
			cur++;
		}
		else {
			cur++;
		}
	}

	QuickSort4(a, left, begin - 1);
	QuickSort4(a, end + 1, right);

}

// 快速排序优化之三路划分
void QuickSort5(int* a, int left, int right, int* depth, int defaultdepth) {
	if (left >= right)
		return;

	//小区间优化
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//自省
	if (*depth > defaultdepth) {
		HeapSort(a + left, right - left + 1);
		return;
	}

	(*depth)++;

	//三数取中
	int tmp = GetMid(a, left, right);
	Swap(&a[left], &a[tmp]);

	int key = left;
	int begin = left;
	int end = right;
	while (begin < end) {
		while (begin < end && a[end] >= a[key]) {
			end--;
		}
		while (begin < end && a[begin] <= a[key]) {
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}

	Swap(&a[key], &a[begin]);


	QuickSort5(a, left, begin - 1,  depth,  defaultdepth);
	QuickSort5(a, begin + 1, right, depth,  defaultdepth);

}

// 快速排序优化之自省排序
void introsort(int* a, int left, int right) {
	int log = 0;

	for (int i = 1; i < right - left + 1;i *= 2 ) {
		log++;
	}

	QuickSort5(a, left, right, 0 , log * 2);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right) {
	Stack s1;
	StackInit(&s1);
	StackPush(&s1, right);
	StackPush(&s1, left);

	while (!StackEmpty(&s1)) {
		int left = StackTop(&s1);
		StackPop(&s1);
		int right = StackTop(&s1);
		StackPop(&s1);

		//小区间优化
		if (right - left + 1 <= 10) {
			InsertSort(a + left, right - left + 1);
			return;
		}

		//三数取中
		int tmp = GetMid(a, left, right);
		Swap(&a[left], &a[tmp]);

		int key = left;
		int begin = left;
		int end = right;
		while (begin < end) {
			while (begin < end && a[end] >= a[key]) {
				end--;
			}
			while (begin < end && a[begin] <= a[key]) {
				begin++;
			}
			Swap(&a[begin], &a[end]);
		}
		Swap(&a[key], &a[begin]);
		if (right > key + 1) {
			StackPush(&s1, end);
			StackPush(&s1, key + 1);
		}
		if (left < key - 1) {
			StackPush(&s1, key - 1);
			StackPush(&s1, left);
		}

	}
	StackDestroy(&s1);

}

void _MergeSort(int* a, int* tmp, int left, int right) {
	if (left >= right)
		return ;
	int mid = (left + right) / 2;

	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;

	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}

	memcpy(a + left,tmp +left,sizeof(int) * (end2 - left + 1));

}

// 归并排序递归实现
void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);

	if (NULL == tmp) {
		perror("MergeSortNonR:malloc");
		exit(1);
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;

}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n) {

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (NULL == tmp) {
		perror("MergeSortNonR:malloc");
		exit(1);
	}

	int gap = 1;

	while (gap < n) {
		
		for (int i = 0; i < n; i += 2 * gap) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (begin2 >= n) {
				break;

			}

			if (end2 >= n) {
				end2 = n - 1;
			}

			int j = i;

			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[j++] = a[begin1++];
				}
				else {
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1) {
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2) {
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (2 * gap));

		}
		gap *= 2;
		}

	free(tmp);
	tmp = NULL;
}

// 计数排序
void CountSort(int* a, int n) {
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	int* tmp = (int*)calloc((max - min + 1),sizeof(int));
	if (tmp == NULL) {
		perror("calloc");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		tmp[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < n; ) {

		while (tmp[j]--) {
			a[i++] = j + min;
		}

		j++;

	}
	free(tmp);
	tmp = NULL;

}