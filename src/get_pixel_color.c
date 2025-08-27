#include "../include/cub.h"

unsigned int	get_pixel_color(mlx_image_t *img, uint32_t x, uint32_t y)
{
	unsigned long	i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;

	if (!img || x >= img->width || y >= img->height)
		return (0);
	i = (y * img->width + x) * 4;
	r = img->pixels[i + 0];
	g = img->pixels[i + 1];
	b = img->pixels[i + 2];
	a = img->pixels[i + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
