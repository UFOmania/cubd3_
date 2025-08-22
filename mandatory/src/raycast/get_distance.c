#include "../../include/cube.h"

double distance(t_vec2 a, t_vec2 b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return (sqrt(dx * dx + dy * dy));
}