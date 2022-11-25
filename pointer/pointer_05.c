#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
 * // 一维数组传参
 * void test(int arr[]) {} // OK
 * void test(int arr[10]) {} // OK
 * void test(int *arr) {} // OK
 * void test2(int *arr[10]) {}
 * void test2(int **arr) {}
 *
 * int main()
 * {
 * 	int arr[10] = {0};
 * 	int *arr2[10] = {0};
 * 	test(arr);
 * 	test2(arr2);
 * }
 */


/*
 * //二维数组传参
 * 		| void test(int arr[3][4]); // OK
 * 数组做形参	|
 * 		| void test(int arr[][4]); // OK
 *
 * 指针做形参	| void test(int (*p)[4]) // OK
 *
 * int main()
 * {
 * 	int arr[3][4] = {0};
 * 	test(arr);
 * }
 */

/*
 * 二级指针传参, 可以接收指针数组，二级指针，一级指针的地址；
 * void test(int **p)
 * {
 * 	return
 * }
 *
 * int main()
 * {
 * 	int a = 10;
 * 	int *p = &a;
 * 	int **pp = &p;
 * 	test(pp);
 * 	test(*p);
 * 	return 0;
 * }
 */

// 函数指针: 本质是指针，指向函数的指, int (*ptr_fun)(int, int)
static int add(int x, int y)
{
	return x + y;
}

static void print(char *str)
{
	printf("%s\n", str);
}

static char *my_strcpy(const char *src)
{
	assert(src != NULL);
	char *tmp = (char *)malloc(strlen(src) + 1);
	char *ret = (char *)malloc(strlen(src) + 1);
	ret = tmp;
	while ((*tmp++ = *src++) != '\0');
	// 注意不能直接返回tmp，因为tmp指针已经位于src[strlen(src)]之后的位置了；
	return ret;
}

static char *my_strcpy_correct(char *dst, const char *src)

{
	assert(dst != NULL && src != NULL);    //[2]
	char *ret = dst;  //[3]
	while ((*dst++=*src++)!='\0'); //[4]
	return ret;
}

int main()
{
	int (*ptr)(int, int) = add;
	/* printf("%d\n", ptr(1, 2)); */
	void (*ptr_str)(char *) = print;
	/* ptr_str("hello world\n"); */

	char arr[1200];
	char *(*ptr_func)(const char *)  = my_strcpy;
	char *(*ptr_func_cor)(char *, const char *)  = my_strcpy_correct;
	printf("ret = %s\n", ptr_func("xudefuxudefu"));
	printf("ret = %s, arr = %s\n", ptr_func_cor(arr, "xudefuxudefu"), arr);
	return 0;
}
