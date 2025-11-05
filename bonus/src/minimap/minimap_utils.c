

#include "../../../include/cub_bonus.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}



void ft_draw_player(t_game *game, int px, int py, int cell_size)
{  
	int dx;
	int psize;
	int dy;
	
	dx = 0;
	psize = cell_size / 2;
	dy = 0;
	while (dy < psize)
	{
		dx = 0;
		while (dx < psize)
		{
			mlx_put_pixel(game->img,
				px + dx + (cell_size - psize) / 2,
				py + dy + (cell_size - psize) / 2,
				ft_pixel(0, 0, 255, 255));
			dx++;
		}
		dy++;
	}
}

void ft_minimap_init(t_game *game, t_minimap *minimap)
{
   	minimap->_x_player = game->player.pos.x / TILE_SIZE;
   	minimap->_y_player = game->player.pos.y / TILE_SIZE;
	game->player.cell_x = minimap->_x_player;
	game->player.cell_y = minimap->_y_player;
	minimap->view      = 4;
	minimap->cell_size = 30;
	minimap->map_h     = game->minimap.map_h;
	minimap->map_w     = game->minimap.map_w;
	if (minimap->_y_player - minimap->view >= 0)
		minimap->y_start = minimap->_y_player - minimap->view;
	else
		minimap->y_start = 0;
	if (minimap->_y_player + minimap->view < minimap->map_h)
		minimap->y_end = minimap->_y_player + minimap->view;
	else
		minimap->y_end = minimap->map_h - 1;
	if (minimap->_x_player - minimap->view >= 0)
		minimap->x_start = minimap->_x_player - minimap->view;
	else
		minimap->x_start = 0;
	if (minimap->_x_player + minimap->view < minimap->map_w)
		minimap->x_end = minimap->_x_player + minimap->view;
	else
		minimap->x_end = minimap->map_w - 1;
}
