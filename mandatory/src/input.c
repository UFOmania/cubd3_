#include "../include/cube.h"

int	key_press(int key_code, void *t)
{
	t_game	*game;

	game = (t_game *)t;
	if (key_code == 53)
		close_game(t);
	else if (key_code == 13)
		game->player.mov_up = 1;
	else if (key_code == 1)
		game->player.mov_up = -1;
	else if (key_code == 2)
		game->player.mov_right = 1;
	else if (key_code == 0)
		game->player.mov_right = -1;
	else if (key_code == 123)
		game->player.rot_dir = -1;
	else if (key_code == 124)
		game->player.rot_dir = 1;
	return 0;
}
int	key_release(int key_code, void *t)
{
	t_game	*game;

	game = (t_game *)t;
	if (key_code == 13)
		game->player.mov_up = 0;
	else if (key_code == 1)
		game->player.mov_up = 0;
	else if (key_code == 2)
		game->player.mov_right = 0;
	else if (key_code == 0)
		game->player.mov_right = 0;
	else if (key_code == 123)
		game->player.rot_dir = 0;
	else if (key_code == 124)
		game->player.rot_dir = 0;
		return 0;
}


// static t_vec2 check_for_collision(char **map, t_vec2 player_pos, t_vec2 new_pos)
// {
// 	t_vec2	final_pos;

// 	final_pos = new_pos;

// 	int r = 50;
// 	double lenX = fmod(new_pos.x, TILE_SIZE);

// 	if (lenX > TILE_SIZE / 2)
// 	{
// 		//x collision
// 		if (map[(int)(player_pos.y / TILE_SIZE)][(int)((new_pos.x + r + 0.1) / TILE_SIZE)] == '1')
// 			final_pos.x = player_pos.x;
// 	}
// 	else
// 	{
// 		if (map[(int)(player_pos.y / TILE_SIZE)][(int)((new_pos.x - r - 0.1) / TILE_SIZE)] == '1')
// 			final_pos.x = player_pos.x;
// 	}

// 	double lenY = fmod(new_pos.y, TILE_SIZE);

// 	if (lenY < TILE_SIZE / 2)
// 	{

// 		//y collision
// 		if (map[(int)((new_pos.y - r - 0.1) / TILE_SIZE)][(int)(player_pos.x / TILE_SIZE)] == '1')
// 			final_pos.y = player_pos.y;
// 	}
// 	else
// 	{
// 		if (map[(int)((new_pos.y + r + 0.1) / TILE_SIZE)][(int)(player_pos.x / TILE_SIZE)] == '1')
// 			final_pos.y = player_pos.y;
// 	}
// 	return (final_pos);
// }


static int is_wall(char **map, double x, double y)
{
    int tile_x = (int)(x / TILE_SIZE);
    int tile_y = (int)(y / TILE_SIZE);

    if (tile_x < 0 || tile_y < 0)
        return 1; // out of bounds = wall
    return (map[tile_y][tile_x] == '1');
}

static t_vec2 check_for_collision(char **map, t_vec2 player_pos, t_vec2 new_pos, int r) //understand this in the future
{
    t_vec2 final_pos = player_pos;

    // --- Try moving in X ---
    if (!is_wall(map, new_pos.x + r, player_pos.y) &&
        !is_wall(map, new_pos.x - r, player_pos.y) &&
        !is_wall(map, new_pos.x,     player_pos.y + r) &&
        !is_wall(map, new_pos.x,     player_pos.y - r))
    {
        final_pos.x = new_pos.x;
    }

    // --- Try moving in Y ---
    if (!is_wall(map, player_pos.x,     new_pos.y + r) &&
        !is_wall(map, player_pos.x,     new_pos.y - r) &&
        !is_wall(map, player_pos.x + r, new_pos.y) &&
        !is_wall(map, player_pos.x - r, new_pos.y))
    {
        final_pos.y = new_pos.y;
    }

    return final_pos;
}



int apply_input(t_game *game)
{
	t_vec2	new_pos;
	t_vec2	pos;
	double	angle;
	int		up;
	int		right;

	angle = game->player.rot_angle;
	pos = game->player.pos;
	up = game->player.mov_up;
	right = game->player.mov_right;

	new_pos.x = pos.x + (((cos(angle) * up) + (cos(angle + M_PI / 2) * right)) * MOVE_SPEED);
	new_pos.y = pos.y + (((sin(angle) * up) + (sin(angle + M_PI / 2) * right)) * MOVE_SPEED);
	
	
	game->player.pos = check_for_collision(game->map, pos, new_pos, PLAYER_RADIUS);
	if (game->player.rot_dir)
	{
		game->player.rot_angle += ROT_SPEED * game->player.rot_dir;
		if (game->player.rot_angle >= M_PI * 2)
			game->player.rot_angle = 0;
		if (game->player.rot_angle < 0)
			game->player.rot_angle = (M_PI * 2) - fabs(game->player.rot_angle);
	}
	return (0);
}