#include "../../include/cube.h"

void put_pixel(t_frame *frame, t_vec2 pos, int color)
{
	char	*dst;

	if (pos.x >= 0 && pos.x < WIDTH && pos.y >= 0 && pos.y < HEIGHT) //dont access the data outside the image address
	{
		dst = frame->addr + (int)(pos.y * frame->line_length ) + (int)(pos.x * (frame->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

unsigned int get_pixel(void *texture, t_vec2 pos)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;
	void	*addr = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	if (pos.x >= 0 && pos.x < WIDTH && pos.y >= 0 && pos.y < HEIGHT) //dont access the data outside the image address
	{
		dst = addr + (int)(pos.y * size_line ) + (int)(pos.x * (bpp / 8));
		return (*(unsigned int*)dst);
	}
	return (0);
}
