#include"Hp.h"

void test4() {
	//CreateNDate();
	PrintTopK(10);
}


void test3(){
	int arr[10] = { 8,2,7,22,55,9,6,43,59,32 };

	HeapSort(arr,10);

}


void test2(){
	Heap p1;
	HeapInit(&p1);
	HeapPush(&p1, 6);
	printf("%d\n",HeapTop(&p1));
	HeapPush(&p1, 8);
	HeapPush(&p1, 2);
	HeapPush(&p1, 7);
	HeapPush(&p1, 9);
	printf("%d\n", HeapTop(&p1));
	printf("%d\n",HeapSize(&p1));
	HeapPush(&p1, 3);
	HeapPush(&p1, 1);
	printf("%d\n", HeapTop(&p1));

	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	HeapDestory(&p1);
}

void test1() {
	Heap p1;
	HeapInit(&p1);
	HeapPush(&p1, 6);

	HeapPush(&p1, 8);
	HeapPush(&p1, 2);
	HeapPush(&p1, 7);
	HeapPush(&p1, 9);
	HeapPush(&p1, 3);
	HeapPush(&p1, 1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	//HeapPop(&p1);
	HeapDestory(&p1);
}



int main(){
	//test1();
	/*test2();*/
	/*test3();*/
	test4();
	return 0;
}