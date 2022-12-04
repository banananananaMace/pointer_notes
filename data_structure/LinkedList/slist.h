#pragma once
#include <stdio.h>

typedef struct SL_NODE {
	int data;
	struct SL_NODE *next;
} SL;

void print_list(SL *sl);
void sl_list_insert_tail(SL *sl, int data);
void sl_list_insert_head(SL *sl, int data);
