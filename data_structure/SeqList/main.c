#include <stdio.h>
#include "SeqList.h"

static void test_seq_fun()
{
	SL sl;
	seq_list_init(&sl);
	for (int i = 0; i < MAX_SIZE; i++) {
		seq_list_insert_head(&sl, i);
		/* seq_list_insert_tail(&sl, i); */
	}
	display_seq_list(&sl);
}

int main()
{
	test_seq_fun();
	return 0;
}
