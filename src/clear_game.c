#include "../include/cub.h"

static void	clear_images(t_game *game)
{
	if(game->img)
		mlx_delete_image(game->mlx, game->img);
	if (*(game->texture + N))
		mlx_delete_image(game->mlx, *(game->texture + N));
	if (*(game->texture + S))
		mlx_delete_image(game->mlx, *(game->texture + S));
	if (*(game->texture + W))
		mlx_delete_image(game->mlx, *(game->texture + W));
	if (*(game->texture + E))
		mlx_delete_image(game->mlx, *(game->texture + E));
}

void	clear_game(t_game *game)
{
	// printf("=======================\n");
	free_map(game->map);
	clear_images(game);
	mlx_close_window(game->mlx);
	// mlx_terminate(game->mlx);
}