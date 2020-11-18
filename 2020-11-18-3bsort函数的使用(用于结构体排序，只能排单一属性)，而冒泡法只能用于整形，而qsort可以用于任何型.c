//bsort函数的使用(用于结构体排序，只能排单一属性)，而冒泡法只能用于整形，而qsort可以用于任何型
#include<stdio.h>
#include<stdlib.h>
//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*))
//int compar (const void* p1, const void* p2);

struct stu//结构体自定义初始化
{
	char name[20];
	int age;
};
int struct_cmp(const void* p1, const void* p2)//此函数返回类型只能为int
{
	return ((struct stu*)p1)->age- ((struct stu*)p2)->age;//因为p1为void*指针所以强制转换为float*，指针类型不同访问的空间不一样,
}
void test3()
{
	int i = 0;
	struct stu s[3] = { {"zhagnsan",20},{"lisi",10},{"atian",28} };
	struct stu* p = NULL;
	p = &s;
	int sz = sizeof(s) / sizeof(s[0]);
	//printf("%d",sz);printf可以用于调式
	//printf("%d\n",sizeof(arr[0]));
	qsort(s, sz, sizeof(s[0]), struct_cmp);
	for (i = 0; i < sz; i++)
		printf("%d ", s[i].age);//为什么用是s[i]->age会报错，因为->前面要为指针，需要定义s为结构体指针，然后就可以用->
}
int main()
{
	//int arr[] = {2,3,5,6,7,1,4,9,8,0};
	test3();
	return 0;
}