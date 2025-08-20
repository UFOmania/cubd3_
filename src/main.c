#include "../include/cube.h"


int main(int argc, char *argv[])
{
	//atexit(f);
	t_game	game;
	t_map_mg *map_mg =NULL;
	
	
	if (argc != 2)
		return (display_error_arg(ERR_EXPECTED_ONE_ARG));
	if (is_valid_arg(argv[1]))
		return (display_error_arg(ERR_INVALID_ARGUMENT));
		
	map_mg = malloc(sizeof(t_map_mg));
	if (!map_mg)
		return (display_error_input_malloc(ERR_MALLOC_FAILED, NULL));

	
	if (init_map_mg(map_mg))
		return fprintf(stderr, "Error processing map\n"), 1;
	if (apply_map_ope(argv[1], map_mg))
		return fprintf(stderr, "Error processing map\n"), 1;
	
	game.map = map_mg->maps;

	if (init_game(&game) == R_FAIL)
		return (1);
	//prin_deb(map_mg);
	mlx_hook(game.win, 17, 0l, close_game, &game);
	mlx_hook(game.win,2, 0, key_press, &game);
	mlx_hook(game.win,3, 0, key_release, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return 0;
}



