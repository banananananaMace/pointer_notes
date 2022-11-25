#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) sizeof((a)) / sizeof((a)[0])
int *test()
{
	int a = 10;
	int *p = (int *)malloc(sizeof(int));
	p = &a;
	return p;
}

int my_strlen(char *s)
{
	int len = 0;
	while (*s++ != '\0') {
		len++;
	}
	return len;
}

int main(int argc, char *argv[])
{
	/* int arr[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4}; */
	/* char str[] = "hello world"; */
	/* printf("%ld\n", &arr[9] - &arr[0]); */
	/* printf("strlen = %d\n", my_strlen(str)); */

	/* printf("%p %p\n", arr, arr + 1); */
	/* printf("%p %p\n", &arr[0], &arr[0] + 1); // 地址-首元素的地址 */
	/* printf("%p %p\n", &arr, &arr + 1); // 1 &arr, &数组名表示取出的是整个数组的地址; */
	/* &arr + 1表示的是指向下一组数据的地址，4 * 10 */
	/* 2 sizeof(arr) 表示的是整个数组的大小； */

	// 二级指针
	/* int *p = arr; */
	/* int **pp = &p; */
	/* printf("%d\n", *(*pp + 8)); */

	// 指针数组 and 数组指针
	// 指针数组：int *p[10] 存放指针的数组，本质是一个数组，数组元素为int *
	/* int a = 1, b = 2, c =3; */
	/* int *p[] = {&a, &b, &c}; */
	/* printf("%d\n", *p[1]); */

	// 数组指针 int (*p)arr[10]  int arr[n][n]; int (*p)[n] = arr;
	// int arr[n]; int (*parr)[n] = &arr;
	/*
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int (*p)[3] = arr;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
	*/

	return 0;
}
