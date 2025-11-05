/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:54:11 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 11:57:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

int	check_door_orientation(char **map, int x, int y)
{
	if (y <= 0 || x <= 0)
		return (0);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
		return (1);
	if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
		return (2);
	return (0);
}

int	hit_door(char **map, int map_x, int map_y)
{
	if (map_y < 0 || map_x < 0)
		return (0);
	return (map[map_y][map_x] == 'D');
}

void	draw_column(t_game *game, int screen_x, int start, int end, int tex_x)
{
	int	texture_y;
	int	y;
	int	color;

	y = start;
	while (y < end)
	{
		if (y < 0 || y >= HEIGHT)
		{
			y++;
			continue ;
		}
		texture_y = (y - start) * game->door_img->height / (end - start);
		color = get_pixel_color(game->door_img, tex_x, texture_y);
		mlx_put_pixel(game->img, screen_x, y, color);
		y++;
	}
}

int	is_vertical_or_horizontal_door_hit(char **map, float door_x, float door_y)
{
	int	x;
	int	y;

	y = door_x / TILE_SIZE;
	x = door_y / TILE_SIZE;
	if (map[x][y - 1] == '1' && map[x][y + 1] == '1')
		return (VERTICAL);
	return (HORIZONTAL);
}

t_door	*get_target_door(t_game *game, int map_x, int map_y)
{
	t_door	*temp;

	temp = game->ptrdoor;
	while (temp && (temp->x != map_x || temp->y != map_y))
		temp = temp->next;
	if (!temp)
		return (NULL);
	return (temp);
}
