#include "../include/cub.h"

unsigned int get_pixel_color(mlx_image_t *img, uint32_t x, uint32_t y)
{
    if (!img || x >= img->width || y >= img->height)
        return 0;

    size_t i = (y * img->width + x) * 4;
    uint8_t r = img->pixels[i + 0];
    uint8_t g = img->pixels[i + 1];
    uint8_t b = img->pixels[i + 2];
    uint8_t a = img->pixels[i + 3];

    return (r << 24) | (g << 16) | (b << 8) | a;
}       

void	draw_strip(t_game *game, double dist, double ppd, double x, t_ray ray)
{
	int		texX;
	int		texY;
	double	wall_h;
	double	margen;
	double	texPos;
	int		y;

	if (ray.side == HORIZONTAL)
		texX = ((int)ray.hit_pos.x % (int)TILE_SIZE) * game->texture[ray.tex_hit_side]->width / TILE_SIZE;
	else if (ray.side == VERTICAL)
		texX = ((int)ray.hit_pos.y % (int)TILE_SIZE) * game->texture[ray.tex_hit_side]->width / TILE_SIZE;

	wall_h = (TILE_SIZE * ppd) / dist;

	margen = 0;
	if (wall_h < HEIGHT)
		margen = HEIGHT - wall_h;

	texPos = ((wall_h - HEIGHT ) / 2);
	y = 0;
	while (y < margen / 2)
	{
		mlx_put_pixel(game->img, x, y, game->ceiling_color);
		y++;
	}

	while (y < HEIGHT - (margen / 2))
	{
		texY = ((y + texPos) * game->texture[ray.tex_hit_side]->height / wall_h);
		mlx_put_pixel(game->img, x, y, get_pixel_color(game->texture[ray.tex_hit_side], texX, texY));
		y++;
	}

	while (y < HEIGHT)
	{
		mlx_put_pixel(game->img, x, y, game->floor_color);
		y++;
	}
}

void raycast(t_game *game)
{
    double  ray_angle;
    double  step;
    double  fov;
    t_ray   ray;
    int     x;

    fov = deg_to_rad(FOV);
    ray_angle = game->player.angle - (fov / 2);
    step = fov / WIDTH;

    x = -1;
    while (++x < WIDTH)
    {
        ray = cast_ray(game, game->player.pos, ray_angle);
		// printf("%d\n", ray.tex_hit_side);

        ray.len = distance(game->player.pos, ray.hit_pos) * cos(ray_angle - game->player.angle);

        draw_strip(game,ray.len, game->ppd, x, ray);

        ray_angle = normilize_angle(ray_angle + step);
    }
}
