/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:09:31 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 21:51:44 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

int	is_over_gang(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->player.is_over_gang <= 0)
		return (0);
	game->player.is_over_gang--;
	return (1);
}

int	increamte_gnag_shoot(void *param)
{
	t_game	*game;
	int		time_;

	game = (t_game *)param;
	if (game->player.is_over_gang <= 0)
	{
		time_ = (int)mlx_get_time();
		if (time_ % 2 == 0)
		{
			game->player.is_over_gang = 10;
		}
	}
	return (1);
}

static void	process_mouse_rotation(t_game *game, int32_t xpos, int32_t ypos)
{
	static int	last_x = WIDTH / 2;
	double		delta_x;
	int			center_x;

	center_x = WIDTH / 2;
	game->ignore_next_mouse = true;
	mlx_get_mouse_pos(game->mlx, &xpos, &ypos);
	if (xpos < 0 || xpos > WIDTH || ypos < 0 || ypos > HEIGHT)
	{
		last_x = center_x;
		game->player.rotate_right_mouse = 0;
		return ;
	}
	delta_x = xpos - last_x;
	if (fabs(delta_x) <= 10)
	{
		game->player.rotate_right_mouse = 0;
		return ;
	}
	if (delta_x > 0)
		game->player.rotate_right_mouse = 1;
	else
		game->player.rotate_right_mouse = -1;
	mlx_set_mouse_pos(game->mlx, center_x, HEIGHT / 2);
	last_x = center_x;
}

void	catch_mouse_move(void *param)
{
	t_game	*game;
	int32_t	xpos;
	int32_t	ypos;

	game = param;
	mlx_get_mouse_pos(game->mlx, &xpos, &ypos);
	if (xpos < 0 || xpos > WIDTH || ypos < 0 || ypos > HEIGHT)
	{
		game->player.rotate_right_mouse = 0;
		return ;
	}
	if (game->ignore_next_mouse)
	{
		game->ignore_next_mouse = false;
		return ;
	}
	process_mouse_rotation(game, xpos, ypos);
}

void	catch_mouse_click(mouse_key_t button, action_t action, \
				modifier_key_t mods, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		game->_mouse_click = true;
	(void)mods;
}
