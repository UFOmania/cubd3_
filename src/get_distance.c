#include "../include/cub.h"

double	distance(t_vec2 a, t_vec2 b)
{
	double	dx;
	double	dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
	return (sqrt(dx * dx + dy * dy));
}
