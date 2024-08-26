//#include"Heap.h"
//
//
////堆的初始化
//void HeapInit(HP* php)
//{
//	assert(php);
//	php->_a = NULL;
//	php->_capacity = php->_size = 0;
//
//}
//
//// 堆的销毁
//void HeapDestory(HP* hp)
//{
//
//	assert(hp);
//	free(hp->_a);
//	hp->_a = NULL;
//	hp->_capacity = hp->_size = 0;
//
//}
//
////交换
//void Swap(HPDataType* a, HPDataType* b)
//{
//	HPDataType temp = *a;
//	*a = *b;
//	*b = temp;
//
//}
//
////向上调整算法
//void AdjustUp(HPDataType* a, int child)
//{
//	assert(a);
//
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//
//		else
//		{
//
//			break;
//
//		}
//	}
//}
//
//// 堆的插入
//void HeapPush(HP* hp, HPDataType x)
//{
//	assert(hp);
//	if (hp->_capacity == hp->_size)
//	{
//		int newcapacity = hp->_capacity == 0 ? 4 : 2 * hp->_capacity;
//		HPDataType* newnode = (HPDataType*)realloc(hp->_a, newcapacity * sizeof(HPDataType));
//
//		if (NULL == newnode)
//		{
//			perror("StackInit:realloc");
//			exit(1);
//		}
//		hp->_a = newnode;
//		hp->_capacity = newcapacity;
//	}
//
//	hp->_a[hp->_size] = x;
//	hp->_size++;
//	AdjustUp(hp->_a, hp->_size - 1);
//
//}
//
////向下调整算法
//void AdjustDown(HPDataType* a, int n, int parent)
//{
//	assert(a);
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if(child + 1 < n && a[child] < a[child + 1])
//		{
//			child = child + 1;
//		}
//		if(a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//} 
//
//// 堆的删除
//void HeapPop(HP* hp)
//{
//	assert(hp);
//	assert(hp->_size > 0);
//	Swap(&hp->_a[0],&hp->_a[hp->_size - 1]);
//
//	hp->_size--;
//
//	AdjustDown(hp->_a, hp->_size, 0);
//
//}
//
//// 取堆顶的数据
//HPDataType HeapTop(HP* hp)
//{
//	assert(hp);
//	assert(hp->_size > 0);
//
//	return hp->_a[0];
//}
//
//// 堆的数据个数
//int HeapSize(HP* hp)
//{
//	assert(hp);
//	return hp->_size;
//}
//
//// 堆的判空
//int HeapEmpty(HP* hp)
//{
//
//	assert(hp);
//	return hp->_size == 0;
//
//}
//
//// 对数组进行堆排序
//void HeapSort(int* a, int n)
//{
//	//for(int i = 1;i < n;i++)
//	//{
//	//	AdjustUp(a, i);
//	//}
//
//	for(int i = (n - 2) / 2;i >= 0;i--)
//	{
//
//		AdjustDown(a,n,i);
//
//	}
//
//	int end = n - 1;
//	while(end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}