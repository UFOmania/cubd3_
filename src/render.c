#include "../include/cub.h"

static void	render_ceiling_floor(mlx_image_t *img, \
t_raycast_args *a, int end, int color)
{
	while (a->yOnScreen < end)
	{
		mlx_put_pixel(img, a->xOnScreen, a->yOnScreen, color);
		a->yOnScreen++;
	}
}

static void	render_walls(t_game *game, t_raycast_args *a)
{
	int			tex_pos_on_wall;
	int			color;
	int			side;
	mlx_image_t	*texture;

	texture = game->texture[a->ray.tex_hit_side];
	tex_pos_on_wall = ((a->wall_h - HEIGHT) / 2);
	while (a->yOnScreen < HEIGHT - (a->margen / 2))
	{
		a->tex_y = ((a->yOnScreen + tex_pos_on_wall) * \
		texture->height / a->wall_h);
		color = get_pixel_color(texture, a->tex_x, a->tex_y);
		mlx_put_pixel(game->img, a->xOnScreen, a->yOnScreen, color);
		a->yOnScreen++;
	}
}

void	do_render(t_game *game, t_raycast_args *a)
{
	a->yOnScreen = 0;
	render_ceiling_floor(game->img, a, a->margen / 2, game->ceiling_color);
	render_walls(game, a);
	render_ceiling_floor(game->img, a, HEIGHT, game->floor_color);
}
