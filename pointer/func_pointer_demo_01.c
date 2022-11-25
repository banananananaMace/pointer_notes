#include <stdio.h>

/*
 * int (*add)(int a, int b); ---> Operation add;
 * int (*add) 表示函数指针；
 */
typedef int (*Operation)(int a, int b);

/*
 * Pointer 表示数据类型；用pointer定义变量
 * 指针： 指针的类型为int *
 */
typedef int * (*Pointer)(int a, int b);

struct ptr_func {
	int result;
	Operation add;
	int (*sub)(int a, int b);
	int (*mult)(int a, int b);
};

static int add(int a, int b)
{
	return a + b;
}

static int sub(int a, int b)
{
	return a - b;
}

static int mult(int a, int b)
{
	return a * b;
}

static int max(int a, int b)
{
	return a > b ? a : b;
}

static int min(int a, int b)
{
	return a < b ? a : b;
}

static int *get_value(int a, int b)
{
	int *ret = &a;
	return ret;
}

int main(int argc, char *argv[])
{
	Operation func;
	int a = 10, b = 5;
	func = max;
	printf("max = %d\n", (*func)(a, b));
	func = min;
	printf("min = %d\n", func(a, b));
	struct ptr_func pfn = {.result = 0, add, sub, mult};
	pfn.result = pfn.add(a, b);
	printf("a + b = %d\n", pfn.result);
	pfn.result = pfn.sub(a, b);
	printf("a - b = %d\n", pfn.result);
	pfn.result = pfn.mult(a, b);
	printf("a * b = %d\n", pfn.result);
	int *p = get_value(a, b);
	printf("p = %d\n", *p);
	return 0;
}
