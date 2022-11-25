#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
typedef void (* ptr)(int) //函数指针，指向的函数入参为int,返回值为void
ptr func(int a, ptr func) // 函数的入参是一个函数指针，返回值也为函数指针；
			  //
char *my_memcpy(char *dest, const char *src);
char *(*ptr)(char *, const char *) = my_memcpy; //ptr为函数指针；
char *(*ptr_arr[4])(char *, const char*) = {my_memcpy, my_memcpy, my_memcpy, my_memcpy}; //函数指针数组，本质是一个数组，数组的每一个元素都是一个指针，指针指向的函数入参为char， 返回值为char*
*/

/*
// 函数指针数组的使用
#define OPERATION_NUM	4
static void menu(void)
{
	printf("******************************\n");
	printf("************1, add************\n");
	printf("************2, sub************\n");
	printf("************3, mul************\n");
	printf("************4, div************\n");
	printf("******************************\n");
	printf("***please choose the option***\n");
}

static int my_add(int a, int b)
{
	return a + b;
}

static int my_sub(int a, int b)
{
	return a - b;
}

static int my_mul(int a, int b)
{
	return a * b;
}

static int my_div(int a, int b)
{
	if (b != 0) {
		return a / b;
	} else {
		exit(-1);
	}
}

// 回调函数：可以通过函数指针来调用的函数
// example02
static void calc(int (*pfunc)(int, int))
{
	int param_0, param_1;
	printf("please input the num: \n");
	scanf("%d %d", &param_0, &param_1);
	printf("result is %d\n", pfunc(param_0, param_1));
}

int main(void)
{
	int input = 0;
	int (*pfunc[OPERATION_NUM + 1])(int, int) = {0, my_add, my_sub, my_mul, my_div};
	do {
		menu();
		scanf("%d", &input);
		if (input >= 1 && input <= OPERATION_NUM) {
			calc(pfunc[input]);// pfunc[input](param_0, param_1);
		} else {
			exit(-1);
		}

	} while(1);
}
*/

/*
// 回调函数：可以通过函数指针来调用的函数
// example01, qsort
static int cmp(const void *p1, const void *p2)
{
	return strcmp(*(char **)p1, *(char **)p2);
}

int main()
{
	char *str[] = {
		"hello worlc",
		"hello world",
		"hello worle",
		"hello worla",
		"hello worlb",
		"hello worlf",
	};
	qsort(str, 6, sizeof(char *), cmp);
	for (int i = 0; i < 6; i++) {
		printf("%s\n", *(str + i));
	}
}
*/

//
static int my_mul(int a, int b)
{
	return a * b;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int (*ptr)[6] = &arr;//ptr 指向数组的指针
	int (*pfunc[3])(int, int) = {my_mul, my_mul, my_mul}; //pfunc为函数指针数组，
}
