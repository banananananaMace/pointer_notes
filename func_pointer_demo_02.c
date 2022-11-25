#include <stdio.h>

typedef int (*method_1)();
typedef int (*method_2)(int, int);
typedef int (*method_3)(int a, int b);

typedef struct {
	method_1 add;
	method_1 sub;
	method_1 mod;
}func;

int add(int a, int b, int c)
{
	return a + b + c;
}

int sub(int a, int b)
{
	return a - b;
}

int mod(int a, int b)
{
	return a % b;
}

int main(int argc, char *argv[])
{
	func tmp = {add, sub, mod};
	int ret = tmp.add(1, 2, 3);
	printf("ret = %d\n", ret);
}
