#include "../include/cub.h"

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

void	apply_inputs(t_player *player, char **map)
{
	t_vec2	new_pos;
	t_vec2	pos;
	double		angle;
	int		up;
	int		right;

	pos = player->pos;
	angle = player->angle;
	right = player->go_right;
	up = player->go_up;

	new_pos.x = pos.x + (((cos(angle) * up) + (cos(angle + (M_PI / 2)) * right)) * MOVE_SPEED);
	new_pos.y = pos.y + (((sin(angle) * up) + (sin(angle + (M_PI / 2)) * right)) * MOVE_SPEED);

	player->pos = check_for_collision(map, pos, new_pos, PLAYER_RADIUS);
	if (player->rotate_right)
	{
		player->angle += ROT_SPEED * (double)player->rotate_right;
		if (player->angle >= M_PI * 2)
			player->angle = 0;
		if (player->angle < 0)
			player->angle = (M_PI * 2) - fabs(player->angle);
	}
}

void input(mlx_key_data_t keydata, void* param)
{
	t_game *game;

	game = (t_game *)param;
	
	if(keydata.key == MLX_KEY_ESCAPE)
		close_game(param);

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player.go_up = 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->player.go_up = -1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->player.go_right = -1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->player.go_right = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->player.rotate_right = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->player.rotate_right = 1;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		game->player.go_up = 0;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		game->player.go_up = 0;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		game->player.go_right = 0;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		game->player.go_right = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->player.rotate_right = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game->player.rotate_right = 0;

}

void close_game( void *param)
{
	t_game *game;

	game = (t_game *)param;
	clear_game(game);
}
