/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:06:05 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 21:08:03 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static float	ft_get_player_x(t_game *game, t_minimap *minimap)
{
	return ((game->player.cell_x - minimap->x_start) \
	* minimap->cell_size + minimap->cell_size / 2);
}

static float	ft_get_player_y(t_game *game, t_minimap *minimap)
{
	return ((game->player.cell_y - minimap->y_start) \
	* minimap->cell_size + minimap->cell_size / 2);
}

static	int	ft_is_wall_hit(t_game *game, t_minimap *minimap, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / minimap->cell_size) + minimap->x_start;
	map_y = (int)(y / minimap->cell_size) + minimap->y_start;
	if (map_x < 0 || map_x >= minimap->map_w
		|| map_y < 0 || map_y >= minimap->map_h)
		return (1);
	if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == 'D')
		return (1);
	return (0);
}

static void	ft_draw_single_ray(t_game *game, t_minimap *minimap,
float ray_angle, float max_dist)
{
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;

	ray_x = ft_get_player_x(game, minimap);
	ray_y = ft_get_player_y(game, minimap);
	dx = cosf(ray_angle);
	dy = sinf(ray_angle);
	while (ray_x >= 0 && ray_y >= 0 && ray_x < max_dist && ray_y < max_dist)
	{
		if (ft_is_wall_hit(game, minimap, ray_x, ray_y))
			break ;
		mlx_put_pixel(game->img, (int)ray_x, (int)ray_y,
			ft_pixel(255, 255, 0, 255));
		ray_x += dx;
		ray_y += dy;
	}
}

void	ft_draw_rays_minimap(t_game *game, t_minimap *minimap)
{
	float	fov;
	int		i;
	float	start_angle;
	float	angle_step;
	float	max_dist;

	fov = 60.0f * (M_PI / 180.0f);
	start_angle = game->player.angle - fov / 2;
	angle_step = fov / 60.0f;
	max_dist = (minimap->x_end - minimap->x_start + 1)
		* minimap->cell_size;
	i = 0;
	while (i < 60)
	{
		ft_draw_single_ray(game, minimap, start_angle + i * \
			angle_step, max_dist);
		i++;
	}
}
