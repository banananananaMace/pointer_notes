#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "slist.h"

/*
 *----------------		-----------------		-----------------		-----------------
 *|prev|head|next| <---->	|prev|data1|next| <---->	|prev|data2|next| <---->	|prev|data3|next|
 *----------------		-----------------		-----------------		-----------------
 */
static SL *create_node(int data)
{
	SL *ret = (SL *)malloc(sizeof(SL));
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	return ret;
}

SL *list_init(void)
{
	SL *phead = create_node(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void list_insert_tail(SL *sl, int data)
{
	SL *tail = sl->prev;
	SL *new = create_node(data);
	tail->next = new;
	new->prev = tail;
	new->next = sl;
	sl->prev = new;
}

void print_list(SL *sl)
{
	SL *cur = sl->next;
	while (cur != sl) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void list_insert_head(SL *sl, int data)
{
	assert(sl != NULL);
	SL *new = create_node(data);
	SL *head = sl->next;

	sl->next = new;
	new->prev = sl;
	new->next = head;
	head->prev = new;
}

void list_delete_head(SL *sl)
{
	assert(sl != sl->next);
	SL *first = sl->next;
	SL *second = sl->next->next;
	sl->next = second;
	second->prev = sl;
	free(first);

	/* list_delete(sl->next); */
}

void list_delete_tail(SL *sl)
{
	assert(sl != sl->next);
	SL *last = sl->prev;
	SL *another = sl->prev->prev;
	sl->prev = another;
	another->next = sl;
	free(last);

	/* list_delete(sl->prev); */
}

//查找链表中值为data的节点
SL *find_node(SL *sl, int data)
{
	SL *cur = sl->next;
	while (cur != sl) {
		if (cur->data == data) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos结点之前插入data
void list_insert(SL *sl, SL *pos, int data)
{
	SL *new = create_node(data);
	SL *prev = pos->prev;
	new->next = pos;
	pos->prev = new;
	prev->next = new;
	new->prev = prev;
}

//删除链表中的pos节点
void list_delete(SL *sl, SL *pos)
{
	SL *prev = pos->prev;
	SL *next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

bool list_is_empty(SL *sl)
{
	return sl == sl->next;
}

int list_size(SL *sl)
{
	int cnt = 0;
	SL *cur = sl->next;
	while (cur != sl) {
		cnt++;
	}
	return cnt;
}

