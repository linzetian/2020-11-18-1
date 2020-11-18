//bsort函数的使用(用于浮点型)，而冒泡法只能用于整形，而qsort可以用于任何型
#include<stdio.h>
#include<stdlib.h>
//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*))
//int compar (const void* p1, const void* p2);

int int_cmp(const void* p1, const void* p2)//此函数返回类型只能为int
{
	return (int)(*(float*)p1 - *(float*)p2);//因为p1为void*指针所以强制转换为float*，指针类型不同访问的空间不一样,最后float要转换为int
}
void test2()
{
	int i = 0;
	float arr[] = { 2.0,3.0,5.0,6.0,7.0,1.0,4.0,9.0,8.0,10.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d",sz);printf可以用于调式
	//printf("%d\n",sizeof(arr[0]));
	qsort(arr, sz, sizeof(arr[0]), int_cmp);
	for (i = 0; i < sz; i++)
		printf("%3.1f ", arr[i]);
}
int main()
{
	//int arr[] = {2,3,5,6,7,1,4,9,8,0};
	test2();
	return 0;
}