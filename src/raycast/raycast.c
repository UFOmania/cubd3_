#include "../../include/cube.h"


static void get_facing_dir(t_game *game)
{
	double	angle;

	angle = game->player.rot_angle;
	if (angle < M_PI / 4 && angle > 5 * M_PI / 4)
		game->player.right = 1;
	else
		game->player.right = -1;
	if (angle < M_PI && angle >= 0)
		game->player.up = -1;
	else
		game->player.up = 1;
}
/*
cos(angle) > 0 → ray going right
cos(angle) < 0 → ray going left
sin(angle) > 0 → ray going down
sin(angle) < 0 → ray going up
*/

double get_hypontenuse(double angle, double adjacent)
{
	double	t;

	t = cos(angle);
	if (fabs(t) < 0.00001)
		return INFINITY;
	return (fabs(adjacent) / fabs(t));
}

/*
t_vec2 get_first_intercept2(t_game *game)
{
    t_vec2 pos = game->player.pos;
    t_vec2 v_first = {INFINITY, INFINITY};
    t_vec2 h_first = {INFINITY, INFINITY};
    double angle = game->player.rot_angle;

    // vertical intercept
    if (fabs(cos(angle)) > 1e-6) {
        if (cos(angle) > 0) // right
            v_first.x = floor(pos.x / 80) * 80 + 80;
        else                // left
            v_first.x = floor(pos.x / 80) * 80 - 0.0001;
        v_first.y = pos.y + (v_first.x - pos.x) * tan(angle);
    }

    // horizontal intercept
	if (fabs(sin(angle)) > 1e-6) {
		if (sin(angle) > 0) // down
			h_first.y = floor(pos.y / 80) * 80 + 80;
		else                // up
			h_first.y = floor(pos.y / 80) * 80 - 0.0001;
		h_first.x = pos.x + (h_first.y - pos.y) / tan(angle);
	}

    // compute distances (guarding INFINITY)
    double v_dist = (v_first.x != INFINITY) ? (v_first.x - pos.x) / cos(angle) : INFINITY;
    double h_dist = (h_first.y != INFINITY) ? (h_first.y - pos.y) / sin(angle) : INFINITY;

    if (v_dist < h_dist)
        return v_first;
    else
        return h_first;
}
*/

double deg_to_rad(double degrees)
{
    return degrees * (M_PI / 180.0);
}

static double	normilize_angle(double angle)
{
	if (angle >= 2 * M_PI)
		angle = fmod(angle, 2 * M_PI); // bring inside -2π .. 2π
    return angle;
}

void	draw_strip(t_game *game, double dist, double ppd, double x, t_ray ray)
{
	int texX;

	if (ray.side == HORIZONTAL)
		texX = ((int)ray.hit_pos.x % (int)TILE_SIZE);
	else if (ray.side == VERTICAL)
		texX = ((int)ray.hit_pos.y % (int)TILE_SIZE);


	if (dist == 0)
		return ;
	double wall_h = (TILE_SIZE * ppd) / dist;
	if (wall_h > HEIGHT*2)
		wall_h = HEIGHT*2 ;
	double marjen = HEIGHT - wall_h;
	double down_m = marjen * 0.2;
	double top_m = marjen - down_m;
	
	double step  = TILE_SIZE / wall_h;
	double texPos = 0;

	for(int y = top_m ; y < HEIGHT - down_m; y++)
	{
		int texY = ((int)texPos % (int)TILE_SIZE);
		texPos += step;
		int color;
		if (ray.type == '1')
			color = get_pixel(game->texture, (t_vec2){texX, texY});
		else if (ray.type == 'D')
			color = get_pixel(game->door, (t_vec2){texX, texY});

		put_pixel(&game->frame, (t_vec2){x, y}, color);
	}

	for(int i = 0; i < top_m; i++)
		put_pixel(&game->frame, (t_vec2){x, i}, 0x00BfAF4f);//F0Ef7f

	for(int i = HEIGHT; i > HEIGHT - down_m; i--)
		put_pixel(&game->frame, (t_vec2){x, i}, 0x00f0ef7f);


}


void	raycast(t_game *game)
{
	t_vec2	pos = game->player.pos;
	t_ray		ray;
	double	i;
	double	step;
	double	angle;
	double	dist;
	double ppd = WIDTH / (2 * tan(deg_to_rad(FOV / 2)));

	angle = normilize_angle(game->player.rot_angle - deg_to_rad(FOV / 2));
	// printf("player angle [%f] - deg_to_rad(%f) = [%f]\n", game->player.rot_angle, FOV / 2, deg_to_rad(FOV / 2));
	// exit(1);
	step = deg_to_rad(FOV / (double)WIDTH);
	i = 0;
	while (i < WIDTH)
	{
		ray = cast_ray(game, pos, angle);
		// draw_line(&game->frame, pos, hit_pos, 0x00ffaaaa);
		dist = distance(pos, ray.hit_pos) * cos(angle - game->player.rot_angle);
		// printf("player angle [%f] | ray angle [%f] | dist [%f] | player pos [%f , %f] | hit pos {%f , %f}\n", game->player.rot_angle, angle, dist,pos.x, pos.y, hit_pos.x, hit_pos.y);
		// exit(1);
		draw_strip(game, dist, ppd, i, ray);
		angle += step;
		i++;
	}
}