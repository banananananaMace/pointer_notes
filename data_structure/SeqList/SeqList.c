#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

/*
 * 静态线性表
 * void seq_list_init(SL *sl)
 * {
 * 	memset(sl->arr, 0, sizeof(element) * MAX_SIZE);
 * 	sl->size = 0;
 * }
 *
 * void seq_list_insert_tail(SL *sl, element data)
 * {
 * 	if (sl->size >= MAX_SIZE) {
 * 		printf("Error: not enough memory left\n");
 * 	} else {
 * 		sl->arr[sl->size] = data;
 * 		sl->size++;
 * 	}
 * }
*/

/* 动态线性表 */
void seq_list_init(SL *sl)
{
	sl->arr = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

static void seq_list_check_mem(SL *sl)
{
	if (sl->size == sl->capacity) {
		int new = (sl->capacity == 0 ? 4 : sl->capacity * 2);
		element *temp = realloc(sl->arr, new * sizeof(element));
		if (temp == NULL) {
			printf("realloc memory failed\n");
			exit(-1);
		}
		sl->arr = temp;
		sl->capacity = new;
	}
}

void seq_list_insert_tail(SL *sl, element data)
{
	seq_list_check_mem(sl);
	sl->arr[sl->size] = data;
	sl->size++;
}

void display_seq_list(SL *sl)
{
	for (int i = 0; i < sl->size; i++) {
		printf("%d ", sl->arr[i]);
	}
	putchar('\n');
}

void seq_list_insert_head(SL *sl, element data)
{
	seq_list_check_mem(sl);
	if (sl->size != 0) {
		int end = sl->size - 1;
		while (end >= 0) {
			sl->arr[end + 1] = sl->arr[end];
			end--;
		}
	}
	sl->arr[0] = data;
	sl->size++;
}

void seq_list_delete_tail(SL *sl)
{
	assert(sl->size > 0);
	sl->size--;
}

void seq_list_delete_head(SL *sl)
{
	assert(sl->size > 0);
	int begin = 1;
	while (begin < sl->size) {
		sl->arr[begin - 1] = sl->arr[begin];
		begin++;
	}
	sl->size--;
}

void seq_list_insert(SL *sl, int pos, element data)
{
	assert(pos < sl->size);
	seq_list_check_mem(sl);
	int end = sl->size - 1;
	while (end >= pos) {
		sl->arr[end + 1] = sl->arr[end];
		end--;
	}
	sl->arr[pos] = data;
	sl->size++;
}

void seq_list_delete(SL *sl, int pos)
{
	assert(pos > 0 && pos < sl->size);
	int start = pos + 1;
	while (start < sl->size) {
		sl->arr[start - 1] = sl->arr[start];
		start++;
	}
	sl->size--;
}

void seq_list_destroy(SL *sl)
{
	free(sl->arr);
	sl->arr = NULL;
	sl->size = 0;
}

int seq_list_find(SL *sl, element data)
{
	for (int i = 0; i < sl->size; i++) {
		if (sl->arr[i] == data) {
			return i;
		}
	}
	return -1;
}

void seq_list_modify(SL *sl, int pos, element data)
{
	assert(pos < sl->size);
	sl->arr[pos] = data;
}

