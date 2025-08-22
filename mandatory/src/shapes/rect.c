#include "../../include/cube.h"

void draw_rect(t_frame *frame, t_vec2 start, t_vec2 size, int color)
{
	int	i;
	int	j;

	i = start.x;
	while (i < start.x + size.x)
	{
		j = start.y;
		while (j < start.y + size.y)
		{
			put_pixel(frame, (t_vec2){i, j}, color);
			j++;
		}
		i++;
	}
}