/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:08:44 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 11:57:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

#define DOOR_SPEED 0.2f
#define TRIGGER_DISTANCE 200

static void	ft_update_door_state(t_door *door, float px, float py)
{
	float	dx;
	float	dy;
	float	distance;

	dx = door->x * TILE_SIZE + TILE_SIZE / 2;
	dy = door->y * TILE_SIZE + TILE_SIZE / 2;
	distance = sqrtf((dx - px) * (dx - px) + (dy - py) * (dy - py));
	if (distance < TRIGGER_DISTANCE)
		door->offset += DOOR_SPEED;
	else
		door->offset -= DOOR_SPEED;
	if (door->offset < 0.0f)
		door->offset = 0.0f;
	if (door->offset > 1.0f)
		door->offset = 1.0f;
}

void	ft_update_door_3d(t_game *game)
{
	t_door	*temp;
	float	px;
	float	py;

	temp = game->ptrdoor;
	while (temp)
	{
		px = game->player.pos.x + PLAYER_SIZE / 2;
		py = game->player.pos.y + PLAYER_SIZE / 2;
		ft_update_door_state(temp, px, py);
		temp = temp->next;
	}
}
