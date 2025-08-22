#include "../../include/cube.h"

void	draw_circle(t_frame *frame, t_vec2 pos, int radius, int color)
{
	int	i;
	int	j;
	t_vec2 distance;

	i = pos.x - radius;
	while (i < pos.x + radius)
	{
		j = pos.y - radius;
		while (j < pos.y + radius)
		{
			distance.x = pow(pos.x - i, 2);
			distance.y = pow(pos.y - j, 2);
			if (distance.x + distance.y <= pow(radius, 2))
				put_pixel(frame, (t_vec2){i, j}, color);
			j++;
		}
		i++;
	}
}