#include "../include/cube.h"

void tmp_clear_img(t_frame *frame)
{
	draw_rect(frame, (t_vec2){0,0}, (t_vec2){WIDTH,HEIGHT}, 0);
}


int update(void *t)
{
	t_game *game;

	game = (t_game *)t;
	tmp_clear_img(&game->frame);
	apply_input(game);
	// draw_map(game);
	// draw_player(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0,0);
	mlx_put_image_to_window(game->mlx, game->win, game->texture, 0,0);
	return (0);
}