#include "../../include/cube.h"

void	draw_map(t_game *game)
{
	int size = 256;
	for(int i = 0;i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			if (game->map[i][j] == '1')
				draw_rect(&game->frame, (t_vec2){j * size,i * size}, (t_vec2){size - 2,size - 2}, 0x00a1a1a1);
		}
	}
}