#include "../include/cube.h"






int main(int argc, char *argv[])
{
	//atexit(f);
	t_game	game;
	
	
	if (argc != 2)
		return (display_error_arg(ERR_EXPECTED_ONE_ARG));
	if (is_valid_arg(argv[1]))
		return (display_error_arg(ERR_INVALID_ARGUMENT));

	if (init_game(&game, argv[1]) == R_FAIL)
		return (1);

	//prin_deb(map_mg);
	// return 0;
	mlx_hook(game.win, 17, 0l, close_game, &game);
	mlx_hook(game.win,2, 0, key_press, &game);
	mlx_hook(game.win,3, 0, key_release, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return 0;
}



