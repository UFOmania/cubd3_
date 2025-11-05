/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:40 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 21:48:47 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

void	handle_mouse_click(t_game *game, void *param)
{
	if (game->_mouse_click == true)
	{
		game->last_time++;
		if (game->last_time == 1)
		{
			if (is_over_gang(param))
				play_music_atck();
			else
				increamte_gnag_shoot(param);
		}
		if (game->last_time > 6)
		{
			game->last_time = 0;
			game->_mouse_click = false;
		}
	}
}

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_mouse_click(game, param);
	catch_mouse_move(param);
	apply_inputs(&game->player, game->map);
	raycast(game);
	ft_update_door_3d(game);
	ft_raycast_doors(game);
	ft_fill_map(game);
	update_animation(param);
}
