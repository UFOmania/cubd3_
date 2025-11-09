/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:50:51 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/09 10:41:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static void	lanch_engine(t_game *game)
{
	mlx_close_hook(game->mlx, close_game, game);
	mlx_key_hook(game->mlx, input, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_mouse_hook(game->mlx, catch_mouse_click, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	if (ac != 2)
		return (display_error_arg(ERR_EXPECTED_ONE_ARG));
	if (is_valid_arg(av[1]))
		return (display_error_arg(ERR_INVALID_ARGUMENT));
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!game.mlx)
		return (mlx_strerror(mlx_errno), EXIT_FAILURE);
	if (init_game(&game, av[1]) == R_FAIL)
		return (1);
	game.last_time = 0;
	game.ignore_next_mouse = false;
	game.has_touched_mouse = false;
	lanch_engine(&game);
}
