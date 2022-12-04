#include "slist.h"
#include <stdbool.h>
#include "stdlib.h"

void print_list(SL *sl)
{
	SL *cur  = sl;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void sl_list_insert_tail(SL **sl, int data)
{
	SL *new = (SL *)malloc(sizeof(SL));
	new->data = data;
	new->next = NULL;
	if (*sl == NULL) {
		*sl = new;
	} else {
		SL *cur = *sl;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = new;
	}
}

void sl_list_insert_head(SL **sl, int data)
{
	SL *new = (SL *)malloc(sizeof(SL));
	new->data = data;
	new->next = *sl;
	*sl = new;
}

void sl_list_delete_tail(SL **sl)
{
	if (*sl == NULL) {// 空链表
		return;
	} else if ((*sl)->next == NULL) {// 一个节点
		free(*sl);
		*sl = NULL;
	} else {// 多个节点
		SL *cur = *sl;
		while (cur->next->next != NULL) {
			cur = cur->next;
		}
		SL *temp = cur->next->next;
		free(temp);
		cur->next = NULL;
	}
}

void sl_list_delete_head(SL **sl)
{
	SL *cur = (*sl)->next;
	free(*sl);
	*sl = cur;
}

SL *sl_list_find(SL *sl, int data)
{
	SL *cur = sl;
	while (cur != NULL) {
		if (cur->data == data) {
			return cur;
		} else {
			cur = cur->next;
		}
	}
	return NULL;
}

void sl_list_insert(SL **sl, SL *pos, int data)
{
	if (pos == NULL) {
		printf("hello world\n");
		return;
	}

	SL *cur = *sl;
	while (cur != pos) {
		cur = cur->next;
	}
	SL *temp = (SL *)malloc(sizeof(SL));
	temp->data = data;
	temp->next = cur->next;
	cur->next = temp;
}

void sl_list_erase(SL **sl, SL *pos)
{
	SL *cur = *sl;
	while (cur->next != pos) {
		cur = cur->next;
	}
	cur->next = cur->next->next;
	free(pos);
}
