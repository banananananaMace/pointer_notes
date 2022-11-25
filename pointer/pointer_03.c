#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
// 数组传参时会被退化为指针, 传参时传入的为数组的首地址；
void test(int arr[])
{
	size_t size = sizeof(arr) / sizeof(arr[0]);
	printf("%s, %ld\n", __func__, size);
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 1, 1, 1, 1,1};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	printf("%s, %ld\n", __func__, size);
	test(arr);
}
*/


/*
// 字符指针
int main(void)
{
	char ch = 'c';
	char *pch = &ch;

	char arr[] = "okdjfklsj";
	char *parr = arr;

	const char *p = "abcdef";// 表示的是将常量字符串的首地址a的地址存入p;
			   // ---------------------
			   // |abc................| p指向a
			   // ---------------------
	*p = 'W'; // error!常量字符串无法被修改！
}
*/


/*
int main(void)
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	const char *p1 = "abcdef";
	const char *p2 = "abcdef";

	if (arr1 == arr2) {
		printf("hehe\n");
	} else {
		printf("haha\n");
	}

	if (p1 == p2) {
		printf("hehe\n");
	} else {
		printf("haha\n");
	}
	printf("%p %p %p %p\n", arr1, arr2, p1, p2);
	return 0;
}
*/

/*
// 指针数组, 本质是一个数组，数组中的元素为指针变量；
int main(void)
{
	int arr1[] = {1, 2, 3, 4, 5, 6};
	int arr2[] = {2, 3, 4, 5, 6, 7};
	int arr3[] = {3, 4, 5, 6, 7, 8};

	int *p[] = {arr1, arr2, arr3};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", *(p[i] + j));
		}
		printf("\n");
	}
	return 0;
}
*/
