#include "../include/cube.h"

void tmp_clear_img(t_frame *frame)
{
	draw_rect(frame, (t_vec2){0,0}, (t_vec2){WIDTH,HEIGHT}, 0);
}


#include <stdint.h>

// Convert HSV to RGB (0-1 floats -> 0xRRGGBB)
static uint32_t hsv_to_rgb(float h, float s, float v)
{
    float r, g, b;
    int i = (int)(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch (i % 6) {
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }

    return ((int)(r * 255) << 16) |
           ((int)(g * 255) << 8)  |
           ((int)(b * 255));
}

// Generates rainbow color by cycling hue
uint32_t rainbow_color(void)
{
    static float hue = 0.0f; // 0.0 -> 1.0
    hue += 0.1f;            // step size (change speed here)
    if (hue >= 1.0f)
        hue = 0.0f;

    return hsv_to_rgb(hue, 1.0f, 1.0f);
}

int update(void *t)
{
	t_game *game;

	game = (t_game *)t;
	tmp_clear_img(&game->frame);
	apply_input(game);
	// draw_map(game);
	// draw_player(game);

	game->color  = rainbow_color();


	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0,0);
	// mlx_put_image_to_window(game->mlx, game->win, game->texture, 0,0);
	return (0);
}