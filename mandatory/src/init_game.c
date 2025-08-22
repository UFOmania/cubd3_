#include "../include/cube.h"

void	init_player_info(t_player *p, t_map_mg *map)
{
	p->pos.x = (map->player_pos[1] * (int)TILE_SIZE) + (int)(TILE_SIZE / 2);
	p->pos.y = (map->player_pos[0] * (int)TILE_SIZE) + (int)(TILE_SIZE / 2);
	if (map->player_seen == 'E')
		p->rot_angle = 0;
	else if (map->player_seen == 'S')
		p->rot_angle = M_PI / 2;
	else if (map->player_seen == 'W')
		p->rot_angle = M_PI;
	else if (map->player_seen == 'N')
		p->rot_angle = 3 * M_PI / 2;
	p->mov_right= 0;
	p->mov_up = 0;
	p->rot_dir = 0;
}

int	analyze_map(t_game *game, char *map_name)
{
	t_map_mg	*map_mg;

	map_mg = malloc(sizeof(t_map_mg));
	if (!map_mg)
		return (display_error_input_malloc(ERR_MALLOC_FAILED, R_FAIL));

	if (init_map_mg(map_mg))
		return (fprintf(stderr, "Error processing map\n"), R_FAIL);
	if (apply_map_ope(map_name, map_mg))
		return (fprintf(stderr, "Error processing map\n"), R_FAIL);
	init_player_info(&game->player, map_mg);
	if (load_texture(game, map_mg) == R_FAIL)
		return (R_FAIL);
	game->map = map_mg->maps;
	return (R_SUCCESS);
}

int load_texture(t_game *game, t_map_mg *mg)
{
	game->n_texture.texture = mlx_xpm_file_to_image(game->mlx, mg->north,
								&game->n_texture.width, &game->n_texture.height);
	game->s_texture.texture = mlx_xpm_file_to_image(game->mlx, mg->south,
								&game->s_texture.width, &game->s_texture.height);
	game->w_texture.texture = mlx_xpm_file_to_image(game->mlx, mg->west,
								&game->w_texture.width, &game->w_texture.height);
	game->e_texture.texture = mlx_xpm_file_to_image(game->mlx, mg->east,
								&game->e_texture.width, &game->e_texture.height);

	if (!game->n_texture.texture || !game->s_texture.texture ||
		!game->w_texture.texture || !game->e_texture.texture)
		{
			printf("error: problem with textures\n");
			return (R_FAIL);
		} // failure
	return (R_SUCCESS); // success
}

int	init_game(t_game *game, char *map_name)
{

	if ((game->mlx = mlx_init()) == NULL)
		return (R_FAIL);
	if ((game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d")) == NULL)
		return (R_FAIL);
	if ((game->frame.img = mlx_new_image(game->mlx, WIDTH, HEIGHT)) == NULL)
		return (R_FAIL);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);
	if (analyze_map(game, map_name) == R_FAIL)
		return (R_FAIL);

	return (R_SUCCESS);
}