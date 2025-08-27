#include "../include/cub.h"

void	lanch_engine(t_game *game)
{
	mlx_close_hook(game->mlx, close_game, game);
	mlx_key_hook(game->mlx, input, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}

void	f(void)
{
	system("leaks -q cub");
}

int	main(int ac, char **av)
{
	t_game	game;

	atexit(f);
	game = (t_game){0};
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 0);
	if (!game.mlx)
		return (mlx_strerror(mlx_errno), EXIT_FAILURE);
	if (ac != 2)
		return (display_error_arg(ERR_EXPECTED_ONE_ARG));
	if (is_valid_arg(av[1]))
		return (display_error_arg(ERR_INVALID_ARGUMENT));
	if (init_game(&game, av[1]) == R_FAIL)
		return (1);
	lanch_engine(&game);
}
