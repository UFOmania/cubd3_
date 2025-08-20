#include "../include/cube.h"



int close_game(void *t) //free the game properly
{
	t_game *game;

	game = (t_game *)t;
	exit(0);
}