#include <stdio.h>
#include "slist.h"

void test_slist()
{
	int i = 0;
	SL sl;
	while (i < 10) {
		sl_list_insert_tail(&sl, i);
		i++;
	}
	print_list(&sl);
}

int main(void)
{
	test_slist();
	return 0;
}

