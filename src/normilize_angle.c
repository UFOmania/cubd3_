#include "../include/cub.h"

double	normilize_angle(double angle)
{
	if (angle >= 2 * M_PI)
		angle = fmod(angle, 2 * M_PI);
	return (angle);
}
