#pragma once
#include <stdio.h>

typedef struct SL_NODE {
	int data;
	struct SL_NODE *next;
} SL;

// 会改变链表的元素传入二级指针,否则传入一级指针
void print_list(SL *sl);
void sl_list_insert_tail(SL **sl, int data);
void sl_list_insert_head(SL **sl, int data);

void sl_list_delete_tail(SL **sl);
void sl_list_delete_head(SL **sl);

SL *sl_list_find(SL *sl, int data);
void sl_list_insert(SL **sl, SL *pos, int data);
void sl_list_erase(SL **sl, SL *pos);
