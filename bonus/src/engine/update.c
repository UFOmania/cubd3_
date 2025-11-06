/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:40 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/06 16:11:44 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

void	handle_mouse_click(t_game *game)
{
	if (game->_mouse_click == true)
	{
		game->last_time++;
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
	handle_mouse_click(game);
	catch_mouse_move(param);
	apply_inputs(&game->player, game->map);
	raycast(game);
	ft_update_door_3d(game);
	ft_raycast_doors(game);
	ft_fill_map(game);
	update_animation(param);
}
