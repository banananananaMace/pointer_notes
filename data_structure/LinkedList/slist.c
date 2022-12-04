#include "slist.h"
#include <stdbool.h>
#include "stdlib.h"

void print_list(SL *sl)
{
	SL *cur  = sl->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void sl_list_insert_tail(SL *sl, int data)
{
	SL *new = (SL *)malloc(sizeof(SL));
	new->data = data;
	new->next = NULL;
	SL *cur = sl;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = new;
}

void sl_list_insert_head(SL *sl, int data)
{
	SL *new = (SL *)malloc(sizeof(SL));
	new->data = data;
	new->next = sl->next;
	sl->next = new;
}
