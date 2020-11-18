//bsort函数的使用(用于整形)，而冒泡法只能用于整形，而qsort可以用于任何型
#include<stdio.h>
#include<stdlib.h>
//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*))
//int compar (const void* p1, const void* p2);

int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);//因为p1为void*指针所以强制转换为int*，指针类型不同访问的空间不一样
}
void test1()
{
	int i = 0;
	int arr[] = { 2,3,5,6,7,1,4,9,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]),int_cmp );
	for (i = 0; i < sz; i++)
		printf("%d ",arr[i]);
}
int main()
{
	//int arr[] = {2,3,5,6,7,1,4,9,8,0};
	test1();
	return 0;
}