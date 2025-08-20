#include "../include/cube.h"



int main()
{
	t_game	game;

	if (init_game(&game) == R_FAIL)
		return (1);
	mlx_hook(game.win, 17, 0l, close_game, &game);
	mlx_hook(game.win,2, 0, key_press, &game);
	mlx_hook(game.win,3, 0, key_release, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}