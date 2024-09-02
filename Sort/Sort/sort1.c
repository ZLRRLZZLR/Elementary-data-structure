#include"sort1.h"
//����
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// ��������
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

// ϣ������
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

// ѡ������
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


// ������
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

// ð������
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

// ��������ݹ�ʵ��
//�Ż�������ȡ��
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
// ��������hoare�汾
void QuickSort1(int* a, int left, int right) {
	if (left >= right)
		return;
	//С�����Ż�
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//����ȡ��
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

// ���������ڿӷ�
void QuickSort2(int* a, int left, int right) {
	if (left >= right)
		return;
	//С�����Ż�
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//����ȡ��
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

// ��������ǰ��ָ�뷨
void QuickSort3(int* a, int left, int right) {
	if (left >= right)
		return;

	//С�����Ż�
	if (right - left + 1 <= 10) {
		InsertSort(a + left, right - left + 1);
		return;
	}

	//����ȡ��
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


// �������� �ǵݹ�ʵ��
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

		//С�����Ż�
		if (right - left + 1 <= 10) {
			InsertSort(a + left, right - left + 1);
			return;
		}

		//����ȡ��
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