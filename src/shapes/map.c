#include "../../include/cube.h"

void	draw_map(t_game *game)
{
	int size = WIDTH / 10;
	for(int i = 0;i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if (game->map[i][j] == '1')
				draw_rect(&game->frame, (t_vec2){j * size,i * size}, (t_vec2){size - 2,size - 2}, 0x00a1a1a1);
		}
	}
}