#include "../../include/cube.h"

static t_vec2	get_h_intercept(t_vec2 pos, double angle, t_frame *frame)
{
	t_vec2	h_intercept;
	double	a;

	h_intercept = (t_vec2){INFINITY,INFINITY};
	a = sin(angle);
	// //what side the player is looking to
	if (fabs(a) > 0.0000001)// if sin(angle) is close to zero the means the player is looking directly right or left
	{
		if (a > 0) //looking down
			h_intercept.y = (floor(pos.y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		else 
			h_intercept.y = floor(pos.y / TILE_SIZE) * TILE_SIZE - 0.00001; //-0.00001 is a trik for marjen
		h_intercept.x = pos.x + ((h_intercept.y - pos.y) / tan(angle));
	}
	// draw_circle(frame, h_intercept, 3, 0x0000ffff);
	return (h_intercept);
}

static t_vec2	get_v_intercept(t_vec2 pos, double angle, t_frame *frame)
{
	t_vec2	v_intercept;
	double	a;

	v_intercept = (t_vec2){INFINITY,INFINITY};
	a = cos(angle);
	if (fabs(a) > 0.0000001)
	{
		if (a > 0)//facing right
			v_intercept.x = (floor(pos.x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		else
			v_intercept.x = floor(pos.x / TILE_SIZE) * TILE_SIZE - 0.00001;
		v_intercept.y = pos.y + ((v_intercept.x - pos.x) * tan(angle));
	}
	// draw_circle(frame, v_intercept,3, 0x00ff000f);
	return (v_intercept);
}

static t_vec2	get_the_closest(t_ray *ray, t_vec2 pos, double angle, t_vec2 v, t_vec2 h)
{
	double	dv;
	double	dh;

	dv = INFINITY;
	dh = INFINITY;
	if (v.x != INFINITY)
		dv = (v.x - pos.x) / cos(angle);
	if (h.y != INFINITY)
		dh = (h.y - pos.y) / sin(angle);
	if (dv < dh)
		return (ray->side = VERTICAL, v);
	else
		return (ray->side = HORIZONTAL, h);
}

static int	is_wall(char **map, t_vec2 pos, t_ray *ray)
{
	int x, y;

	x = pos.x / TILE_SIZE;
	y = pos.y / TILE_SIZE;
	if (map[y][x] != '0')
		return (ray->type = map[y][x], 1);
	return (0);
}

t_ray	cast_ray(t_game *game, t_vec2 start, double angle)
{
	t_vec2	pos;
	t_vec2	h_intercept;
	t_vec2	v_intercept;
	t_vec2	closest;
	t_ray	ray;

	pos = start;

	while (1)
	{
		h_intercept = get_h_intercept(pos, angle, &game->frame);
		v_intercept = get_v_intercept(pos, angle, &game->frame);
		closest = get_the_closest(&ray, pos, angle, v_intercept, h_intercept);
		if (is_wall(game->map, closest, &ray))
			break;
		else
			pos = closest;
	}
	ray.hit_pos = closest;
	return (ray);
}