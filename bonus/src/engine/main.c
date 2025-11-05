 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:23 by massrayb          #+#    #+#             */
/*   Updated: 2025/08/30 15:54:32 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

void	lanch_engine(t_game *game)
{

   // ft_fill_map(game);//todo ask for it
 //  play_music();
	mlx_close_hook(game->mlx, close_game, game);
	mlx_key_hook(game->mlx, input, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_mouse_hook(game->mlx, catch_mouse_click, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop(game->mlx);

}
void f()
{
	system("leaks cub3D_bonus");
	//system("lsof -c ./cub3D"); //todo check fds leaks ghda
}   

int	main(int ac, char **av)
{
	atexit(f);
	t_game	game;
	game = (t_game){0};
  
	if (ac != 2)
		return (display_error_arg(ERR_EXPECTED_ONE_ARG));
	if (is_valid_arg(av[1]))
		return (display_error_arg(ERR_INVALID_ARGUMENT));
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!game.mlx)
		return (mlx_strerror(mlx_errno), EXIT_FAILURE);
	if (init_game(&game, av[1]) == R_FAIL) // todo the mlx win if the map mg falied should free mlx
		return (1);
	game.last_time =0;
	game.ignore_next_mouse = false;
	game.has_touched_mouse= false;

	lanch_engine(&game);
}
