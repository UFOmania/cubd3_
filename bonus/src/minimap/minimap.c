/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:09:24 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 21:13:51 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static	void	draw_rect(t_game *game, t_minimap *minimap, \
				uint32_t color, int cell_size)
{
	int	dy;
	int	dx;
	int	start_y;
	int	start_x;

	dy = 0;
	start_y = minimap->draw_y;
	start_x = minimap->draw_x;
	while (dy < cell_size)
	{
		dx = 0;
		while (dx < cell_size)
		{
			if (!game->img)
			{
				print_error("❌ ERROR: game->img is NULL before drawing!");
				return ;
			}
			mlx_put_pixel(game->img, start_x + dx, start_y + dy, color);
			dx++;
		}
		dy++;
	}
}

static	void	ft_draw_cell(t_game *game, t_minimap *minimap, int cell_size)
{
	uint32_t	color;
	char		c;

	c = minimap->c;
	color = 0;
	if (c == '1')
		color = ft_pixel(0, 0, 0, 255);
	else if (c == '0')
		color = ft_pixel(255, 255, 255, 255);
	else if (c == 'D')
		color = ft_pixel(255, 0, 255, 255);
	else
		color = ft_pixel(255, 255, 255, 255);
	draw_rect(game, minimap, color, cell_size);
}

void	ft_draw_minimap_cells(t_game *game, t_minimap *minimap)
{
	char	**map;
	int		y;
	int		x;
	int		draw_y_idx;
	int		draw_x_idx;

	map = game->map;
	y = minimap->y_start;
	draw_y_idx = 0;
	while (y <= minimap->y_end)
	{
		x = minimap->x_start;
		draw_x_idx = 0;
		while (x <= minimap->x_end)
		{
			minimap->draw_x = draw_x_idx * minimap->cell_size;
			minimap->draw_y = draw_y_idx * minimap->cell_size;
			minimap->c = map[y][x];
			ft_draw_cell(game, minimap, minimap->cell_size);
			x++;
			draw_x_idx++;
		}
		y++;
		draw_y_idx++;
	}
}

void	ft_draw_minimap_player(t_game *game, t_minimap *minimap)
{
	ft_draw_player(game,
		(minimap->_x_player - minimap->x_start) * minimap->cell_size,
		(minimap->_y_player - minimap->y_start) * minimap->cell_size,
		minimap->cell_size);
}

void	ft_fill_map(t_game *game)
{
	t_minimap	minimap;

	ft_minimap_init(game, &minimap);
	ft_draw_minimap_cells(game, &minimap);
	ft_draw_minimap_player(game, &minimap);
	ft_draw_rays_minimap(game, &minimap);
}
