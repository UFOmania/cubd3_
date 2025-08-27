#include "../include/cub.h"

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	apply_inputs(&game->player, game->map);
	raycast(game);
}
