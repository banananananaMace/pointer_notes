#include <stdio.h>
#include "slist.h"

void test_slist()
{
	int i = 0;
	SL *sl = NULL;
	while (i < 10) {
		sl_list_insert_tail(&sl, i);
		i++;
	}
	print_list(sl);
	SL *temp = sl_list_find(sl, 9);
	sl_list_insert(&sl, temp, 100);
	print_list(sl);
	sl_list_erase(&sl, temp);
	print_list(sl);
}

int main(void)
{
	test_slist();
	return 0;
}

