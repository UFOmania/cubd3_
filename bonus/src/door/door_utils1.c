/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:20:08 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/09 10:38:55 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static bool	is_hit_exist_door(t_door_hit *hits, int hit_count, t_door *temp)
{
	int	i;

	i = 0;
	while (i < hit_count)
	{
		if (hits[i].door == temp)
			return (true);
		i++;
	}
	return (false);
}

static void	fill_door_hit_data(t_game *game, t_door_hit *hit, t_door *door)
{
	hit->door = door;
	game->ray.distance = distance(game->player.pos, \
		(t_vec2){game->ray.ray_x, game->ray.ray_y})
		* cosf(game->player.angle - game->ray.ray_angle);
	hit->distance = game->ray.distance;
	hit->orientation = check_door_orientation(game->map, \
		game->ray.map_x, game->ray.map_y);
	hit->ray_x = game->ray.ray_x;
	hit->ray_y = game->ray.ray_y;
}

static bool	process_door_hit(t_game *game, t_door_hit *hits, int *hit_count)
{
	t_door	*temp;

	if (!hit_door(game->map, game->ray.map_x, game->ray.map_y))
		return (false);
	temp = get_target_door(game, game->ray.map_x, game->ray.map_y);
	if (!temp)
		return (true);
	if (!is_hit_exist_door(hits, *hit_count, temp))
	{
		fill_door_hit_data(game, &hits[*hit_count], temp);
		(*hit_count)++;
	}
	return (false);
}

static bool	is_out_of_bounds(t_game *game, int map_x, int map_y)
{
	if (map_y < 0 || map_x < 0)
		return (true);
	if (map_y >= game->minimap.map_h || map_x >= game->minimap.map_w)
		return (true);
	if (game->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

int	cast_ray_collect_doors(t_game *game, float ray_angle, t_door_hit *hits)
{
	int		hit_count;
	int		map_x;
	int		map_y;

	game->ray.ray_x = game->player.pos.x;
	game->ray.ray_y = game->player.pos.y;
	game->ray.d_x = cosf(ray_angle);
	game->ray.d_y = sinf(ray_angle);
	game->ray.ray_angle = ray_angle;
	(1) && (hit_count = 0, game->ray.distance = 0.0f);
	while (hit_count < MAX_DOOR_HITS)
	{
		map_x = (int)(game->ray.ray_x / TILE_SIZE);
		map_y = (int)(game->ray.ray_y / TILE_SIZE);
		game->ray.map_x = map_x;
		game->ray.map_y = map_y;
		if (is_out_of_bounds(game, map_x, map_y))
			break ;
		if (process_door_hit(game, hits, &hit_count))
			break ;
		game->ray.ray_x += game->ray.d_x;
		game->ray.ray_y += game->ray.d_y;
	}
	return (hit_count);
}
