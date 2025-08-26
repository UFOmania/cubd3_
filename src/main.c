#include "../include/cub.h"

void lanch_engine(t_game *game)
{
	mlx_close_hook(game->mlx, close_game, game);
	mlx_key_hook(game->mlx, input, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}


void print_map(char **map)
{
    int i = 0;

    while (map[i] != NULL)
    {
        printf("%s\n", map[i]);
        i++;
    }
}

void f(){system("leaks -q cub");}

int main(int ac, char **av)
{
	// atexit(f);
	t_game game;


	game.mlx = mlx_init(WIDTH, HEIGHT, "new cub", 0);  
	if (!game.mlx)
		return (mlx_strerror(mlx_errno), EXIT_FAILURE);
	if (ac != 2)
		return (display_error_arg(ERR_EXPECTED_ONE_ARG));
	if (is_valid_arg(av[1]))
		return (display_error_arg(ERR_INVALID_ARGUMENT));
	if (init_game(&game, av[1]) == R_FAIL)
		return (printf("please cleear the game !!!!!!!\n"), 1);
	lanch_engine(&game);
}
