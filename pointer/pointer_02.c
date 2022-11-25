#include <stdio.h>

// 野指针：访问未初始化的变量；数组越级访问导致; 访问已经初始化的指针；
// 避免野指针：使用指针时判空；定义时初始化；不初始化及时指向NULL；
// 指针运算：	+-整数表示前后移动几个变量；
//		指针相减表示两个指针间元素的个数；只有指向同一个内存空间的指针才能相减
//		指针的大小判断

// 指针与数组: 数组名表示首元素的地址；例外：	sizeof(arr) 表示整个数组的大小;
//						&arr: 去除整个数组的地址

// 二级指针：指向指针的指针（地址的地址）
// int a = 10;
// int *p = &a;
// int **pp = &p
// 假设a 的地址为0x100000;
// 则p 的值为0x100000; 假设p的指针为0x100008
// 则pp的值为0x100008;

//指针数组: int *p[n]本质是数组，数组元素为指针变量
//	1, int a, b, c; int *p[3] = {&a, &b, &c};
//	   printf("%d\n", *(p[i]));
//	2, int a[], b[], c[]; int *p = {a, b, c}

#define ARR_SIZE	10

// *str++表示先解引用再移动指针
int my_strlen(char *str)
{
	int len = 0;
	while (*str++ != '\0') {
		len++;
	}
	return len;
}

int main()
{
	int arr[ARR_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	/*
	int *p = arr;
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%p\n", p);
		p += 1;
	}
	printf("\n------------------\n");
	for (p = arr; p <= &arr[ARR_SIZE - 1]; p++) {
		printf("%p\n", p);
		*p++ = 0;
	}
	// printf("%ld\n", (p + 9) - (p + 2));
	printf("strlen = %d\n", my_strlen("hello world"));
	*/

	printf("%p %p\n", arr, arr + 1);
	printf("%p %p\n", &arr, &arr + 1);// 跳过了整个数组；差值为sizeof(arr);
	return 0;
}
