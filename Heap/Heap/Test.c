//#include"Heap.h"
//
//void test1()
//{
//	HP p;
//	int a[10] = { 8,9,5,3,2,7,6,4,10,1 };
//	HeapInit(&p);
//
//	for(int i = 0;i < 10;i++)
//	{
//		HeapPush(&p, a[i]);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p._a[i]);
//	}
//	HeapPop(&p);
//	HeapTop(&p);
//	printf("%d ",HeapSize(&p));
//	printf("%d",HeapEmpty(&p));
//	HeapDestory(&p);
//}
//void test2()
//{
//	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
//	HeapSort(a,sizeof(a) / sizeof(int));
//}
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}