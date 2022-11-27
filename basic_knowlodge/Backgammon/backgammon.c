#include <stdio.h>
#include "play_game.h"

enum {
	EXIT,
	PLAY,
};

static void menu(void)
{
	printf("****************************\n");
	printf("***** options: 0, exit *****\n");
	printf("***** options: 1, play *****\n");
	printf("****************************\n");
	printf("please input the option: ");
}

static int get_input(void)
{
	int input = 0;
	scanf("%d", &input);
	return input;
}

void test(void)
{
	int input = 0;
	do {
		menu();
		input = get_input();
		switch (input) {
		case EXIT:
			printf("exit the game!\n");
			break;
		case PLAY:
			printf("game start!\n");
			play_the_game();
			break;
		default:
			printf("error input!\n");
			break;
		}
	} while (input != 0);
}

int main()
{
	test();
	return 0;
}
