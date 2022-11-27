#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "play_game.h"

static void init_the_board(int (*arr)[BOARD_COR], int row, int cor)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cor; j++) {
			*(*(arr + i) + j) = ' ';
		}
	}
}

static void display_the_board(int (*arr)[BOARD_COR], int row, int cor)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cor; j++) {
			printf(" %c ", *(*(arr + i) + j));
			if (j < cor - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < cor; j++) {
				printf("---");
				if (j < row - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

static void player_move(int (*arr)[BOARD_COR], int row, int cor)
{
	int x, y;
	printf("player input the position:> ");
	while (1) {
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row) {
			if (arr[x - 1][y - 1] == ' ') {
				arr[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("position occupied, try again> ");
			}
		} else {
			printf("invalid position, try again> ");
		}
	}
}

static void computer_move(int (*arr)[BOARD_COR], int row, int cor)
{
	printf("computer input the position: >");
	srand((unsigned int)time(NULL));
	while (1) {
		int x = rand() % row;
		int y = rand() % cor;
		/* printf("debug info: %d %d\n", x, y); */
		if (arr[x][y] == ' ') {
			arr[x][y] = '#';
			break;
		}
	}
}

static bool arr_is_same(int *arr, int size, int num)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] != num) {
			return false;
		}
	}
	return true;
}

static bool arr_is_full(int (*arr)[BOARD_COR], int row, int cor)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cor; j++) {
			if (arr[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

static char game_result(int (*arr)[BOARD_COR], int row, int cor)
{
	for (int i = 0; i < row; i++) {
		if (arr_is_same(arr[i], cor, '*')) {
			return '*';
		} else if (arr_is_same(arr[i], cor, '#')) {
			return '#';
		}
	}
	if (arr_is_full(arr, row, cor) == false) {
		return 'C';
	} else {
		return 'D';
	}
}

void play_the_game()
{
	int board[BOARD_ROW][BOARD_COR];
	init_the_board(board, BOARD_ROW, BOARD_COR);
	while (1) {
		player_move(board, BOARD_ROW, BOARD_COR);
		printf("\n");
		display_the_board(board, BOARD_ROW, BOARD_COR);
		char ret = game_result(board, BOARD_ROW, BOARD_COR);
		if (ret == '*') {
			printf("player wins!\n");
			break;
		} else if (ret == '#') {
			printf("computer wins!\n");
			break;
		} else if (ret == 'D') {
			printf("game over!\n");
			break;
		} else {
			;
		}

		computer_move(board, BOARD_ROW, BOARD_ROW);
		printf("\n");
		display_the_board(board, BOARD_ROW, BOARD_COR);
		ret = game_result(board, BOARD_ROW, BOARD_COR);
		if (ret == '*') {
			printf("player wins!\n");
			break;
		} else if (ret == '#') {
			printf("computer wins!\n");
			break;
		} else if (ret == 'D') {
			printf("game over!\n");
			break;
		} else {
			;
		}

	}
	return;
}
