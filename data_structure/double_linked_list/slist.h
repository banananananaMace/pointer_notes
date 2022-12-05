#pragma once
#include <stdbool.h>

typedef struct Sl {
	struct Sl *next;
	struct Sl *prev;
	int data;
} SL;

SL *list_init(void);
void print_list(SL *sl);
void list_destroy(SL *sl);

void list_insert_tail(SL *sl, int data);
void list_insert_head(SL *sl, int data);
void list_delete_head(SL *sl);
void list_delete_tail(SL *sl);

SL *find_node(SL *sl, int data);
void list_insert(SL *sl, SL *pos, int data);
void list_delete(SL *sl, SL *pos);

bool list_is_empty(SL *sl);
int list_size(SL *sl);

