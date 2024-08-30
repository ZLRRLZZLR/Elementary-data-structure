#include"Hp.h"

//����
void Swap(HPDataType* a, HPDataType* b) {
	assert(a && b);
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//�ѵĳ�ʼ��
void HeapInit(Heap* php){
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;

}

// �ѵ�����
void HeapDestory(Heap* hp){
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

//���ϵ���
void AdjustUp(HPDataType*arr,int child){
	assert(arr);
	int parent = (child - 1) / 2;
	while(child > 0){
		if (arr[parent] > arr[child]) {
			Swap(&arr[parent],&arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

//���µ���
void AdjustDown(HPDataType* arr, int size, int parent) {
	int child = parent * 2 + 1;

	while (child < size) {

		if (child + 1 < size && arr[child + 1] < arr[child]) {
			child++;
		}

		if (arr[parent] > arr[child]) {
			Swap(&arr[parent],&arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		else {
			break;
		}
	}

}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x){
	assert(hp);
	if(hp->_size == hp->_capacity){
		HPDataType newcapacity = hp->_capacity == 0 ? 4 : 2 * hp->_capacity;
		
		hp->_a = (HPDataType*)realloc(hp->_a, newcapacity * sizeof(int));
		if (NULL == hp->_a) {
			perror("HeapPush realloc");
			exit(1);
		}
		hp->_capacity = newcapacity;
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	AdjustUp(hp->_a,hp->_size - 1);

}

// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->_a);

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0);

}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp){
	assert(hp);
	assert(hp->_size);

	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp) {
	assert(hp);

	return hp->_size == 0;
}

// ��������ж�����
void HeapSort(int* a, int n) {
	////���Ͻ���
	//for (int i = 1; i < n; i++) {
	//	AdjustUp(a , i);
	//}

	//���½���
	for (int i = (n - 1 - 1) / 2; i >= 0;i--) {
		AdjustDown(a, n , i);
	}


	while (n > 1) {
		Swap(&a[0], &a[n - 1]);
		n--;
		AdjustDown(a, n, 0);

	}
}

void CreateNDate()
{
	// ������
	int n = 10000;
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k) {
	HPDataType* arr = (HPDataType*)malloc(sizeof(HPDataType) * k);
	const char* file = "data.txt";
	FILE* fout = fopen(file,"r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}


	for (int i = 0; i < k; i++) {
		fscanf(fout, "%d", &arr[i]);
		AdjustUp(arr, i);
	}

	int a = 0 ;
	while (fscanf(fout, "%d", &a) > 0) {
		if(a > arr[0]){
			Swap(&a,&arr[0]);
			AdjustDown(arr, k, 0);
		}

	}

	for(int i = 0;i < k;i++){
		printf("%d ",arr[i]);
	}

	fclose(fout);
}