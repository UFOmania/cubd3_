#include "../../include/cube.h"


// static void get_facing_dir(t_game *game)
// {
// 	double	angle;

// 	angle = game->player.rot_angle;
// 	if (angle < M_PI / 4 && angle > 5 * M_PI / 4)
// 		game->player.right = 1;
// 	else
// 		game->player.right = -1;
// 	if (angle < M_PI && angle >= 0)
// 		game->player.up = -1;
// 	else
// 		game->player.up = 1;
// }
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
	// if(wall_h > HEIGHT)
	// 	wall_h = HEIGHT;

	double marjen = HEIGHT - wall_h;
	double down_m = marjen * 0.5;
	double top_m = marjen - down_m;
	(void)top_m;
	if (marjen < 0)
		marjen = 0;


	double step  = TILE_SIZE / wall_h;
	(void)step;
	double texPos = 0;
	
		double t = ((wall_h / 2) - (HEIGHT / 2));
		texPos = t * TILE_SIZE /wall_h;
		for(int y = marjen / 2 ; y < HEIGHT - (marjen / 2); y++)
		{
			int texY = ((y + t) * TILE_SIZE / wall_h);
			int color;
			if (ray.type == '1')
				color = get_pixel(game->s_texture.texture, (t_vec2){texX, texY});
				
			put_pixel(&game->frame, (t_vec2){x, y}, color);
		}


	// for(int i = 0; i < marjen / 2; i++)
	// 	put_pixel(&game->frame, (t_vec2){x, i}, game->color);//F0Ef7f

	// for(int i = HEIGHT; i > HEIGHT - down_m; i--)
	// 	put_pixel(&game->frame, (t_vec2){x, i},game->color);


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
	(void)step;
	i = 0;
	while (i < WIDTH)
	{
		ray = cast_ray(game, pos, angle);
		// draw_line(&game->frame, pos, hit_pos, 0x00ffaaaa);
		dist = distance(pos, ray.hit_pos) * cos(angle - game->player.rot_angle);
		// printf("player angle [%f] | ray angle [%f] | dist [%f] | player pos [%f , %f] | hit pos {%f , %f}\n", game->player.rot_angle, angle, dist,pos.x, pos.y, hit_pos.x, hit_pos.y);
		// exit(1);
		// draw_cealing();
		draw_strip(game, dist, ppd, i, ray);
		angle += step;
		i++;
	}
	
}