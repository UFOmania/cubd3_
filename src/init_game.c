#include "../include/cube.h"

static t_player init_player()
{
	t_player	p;

	p.mov_up = 0;
	p.mov_right = 0;
	p.rot_dir = 0;
	p.pos = (t_vec2){100, 100};
	p.dir = (t_vec2){-1, 0};
	p.plane = (t_vec2){0, 0.66};
	p.rot_angle = 0;
	return (p);
}

void load_texure(t_game *game)
{
	int	tmp;
	game->texture = mlx_xpm_file_to_image(game->mlx, "pris.xpm", &tmp, &tmp);
	game->door = mlx_xpm_file_to_image(game->mlx, "door.xpm", &tmp, &tmp);
}

int	init_game(t_game *game)
{
	// if (read_map(game) == R_FAIL)
	// 	return (R_FAIL);

	t_map_mg *map_mg;
	map_mg = malloc(sizeof(t_map_mg));
	if (!map_mg)
		return (display_error_message(ERR_MALLOC_FAILED, NULL));

	init_game_mg(map_mg);
	apply_map_ope("map.cub", map_mg);
	
	game->map = map_mg->maps;
	// game->map
	// exit(0);

	if ((game->mlx = mlx_init()) == NULL)
		return (R_FAIL);
	if ((game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "hello")) == NULL)
		return (R_FAIL);
	if ((game->frame.img = mlx_new_image(game->mlx, WIDTH, HEIGHT)) == NULL)
		return (R_FAIL);
	load_texure(game);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);
	game->player = init_player();
	return (R_SUCCESS);
}