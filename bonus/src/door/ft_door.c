/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:08:29 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/09 10:30:49 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static void	calc_door_render_data(t_game *game, t_door_hit \
	*hit, t_door_render *r)
{
	r->column_height = (TILE_SIZE * game->ppd) / hit->distance;
	r->open_factor = 1.0f - hit->door->offset;
	r->visible_height = (int)(r->column_height * r->open_factor);
	r->shift_up = (int)(r->column_height * hit->door->offset / 2);
}

static void	draw_single_door_hit(t_game *game, t_door_hit *hit,
	int column, t_door_render *r)
{
	int	start;
	int	end;
	int	texture_x;

	start = (HEIGHT / 2) - (r->column_height / 2) - r->shift_up;
	end = start + r->visible_height;
	if (is_vertical_or_horizontal_door_hit(game->map,
			hit->ray_x, hit->ray_y) == VERTICAL)
		texture_x = (fmod(hit->ray_x, TILE_SIZE)
				* game->door_img->width) / TILE_SIZE;
	else
		texture_x = (fmod(hit->ray_y, TILE_SIZE)
				* game->door_img->width) / TILE_SIZE;
	game->door.column = column;
	draw_column(game, start, end, texture_x);
}

static void	process_draw_single_door_hit(t_game *game, \
	t_door_hit *hit, int column)
{
	t_door_render	r;

	calc_door_render_data(game, hit, &r);
	draw_single_door_hit(game, hit, column, &r);
}

static void	process_single_door_ray(t_game *game, \
			float start_angle, float fov_rad, int column)
{
	float		ray_angle;
	int			hit_count;
	t_door_hit	hits[(int)WIDTH];

	ray_angle = start_angle + (fov_rad / WIDTH) * column;
	hit_count = cast_ray_collect_doors(game, ray_angle, hits);
	while (--hit_count >= 0)
	{
		process_draw_single_door_hit(game, &hits[hit_count], column);
	}
}

void	ft_raycast_doors(t_game *game)
{
	float	fov_rad;
	float	start_angle;
	int		column;

	fov_rad = FOV * (M_PI / 180.0f);
	start_angle = game->player.angle - fov_rad / 2.0f;
	column = -1;
	while (++column < WIDTH)
		process_single_door_ray(game, start_angle, fov_rad, column);
}
