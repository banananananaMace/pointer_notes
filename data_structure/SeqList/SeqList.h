#pragma once

typedef int element;
#define MAX_SIZE 9

/*
 * 静态
 * typedef struct seqlist {
 * 	element arr[MAX_SIZE];
 * 	int size;
 * } SL;
 */

// 动态顺序表
typedef struct seqlist {
    element *arr;
    int size;
    int capacity; //有效数据的个数
} SL;

void seq_list_init(SL *sl);
void display_seq_list(SL *sl);
void seq_list_insert_tail(SL *sl, element data);
void seq_list_insert_head(SL *sl, element data);
// void seq_list_delete_tail(SL *sl, element data);
// void seq_list_delete_head(SL *sl, element data);
