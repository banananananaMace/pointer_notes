#include <stdio.h>
#include "slist.h"

// 带头节点的双向链表
void test()
{
	SL *sl = list_init();
	for (int i = 0; i < 10; i++) {
		list_insert_head(sl, i);
	}
	print_list(sl);
	/* list_delete_head(sl); */
	/* print_list(sl); */
	/* list_delete_tail(sl); */
	/* print_list(sl); */
	SL *ret = find_node(sl, 4);
	list_insert(sl, ret, 100);
	print_list(sl);
	list_delete(sl, ret);
	print_list(sl);

}

int main()
{
	test();
	return 0;
}

