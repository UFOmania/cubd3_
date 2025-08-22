#include "../include/cube.h"

// static void draw_projection_plain(t_game *game)
// {
// 	t_vec2	dir;
// 	t_vec2	start;
// 	t_vec2	end;
// 	double	angle;

// 	angle = game->player.rot_angle + (M_PI / 2);
// 	dir = game->player.dir;
// 	start.x = dir.x + cos(angle) * 30;
// 	start.y = dir.y + sin(angle) * 30;
// 	end.x = dir.x + cos(angle) * -30;
// 	end.y = dir.y + sin(angle) * -30;
// 	draw_line(&game->frame, start, end, 0x006bb22a);
// }

void draw_player(t_game *game)
{
	t_vec2 dir;

	dir.x = game->player.pos.x + (cos(game->player.rot_angle) * 30);
	dir.y = game->player.pos.y + (sin(game->player.rot_angle) * 30);
	game->player.dir = dir;
	// draw_projection_plain(game);
	// raycast(game);
	draw_line(&game->frame, game->player.pos, game->player.dir, 0x00ff4444);
	draw_circle(&game->frame, game->player.pos, 5, 0x0088e883);
}