/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:19:59 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 11:57:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static void draw_pixel_to_game(t_game *game, int x, int y, uint32_t color)
{
	if (color & 0xFF)
		mlx_put_pixel(game->img, x + SPRITE_OFFSET_X, y + SPRITE_OFFSET_Y, color);
}

static void draw_sprite_row(t_game *game, mlx_image_t *sprite_sheet, int i)
{
	int j;
	uint32_t color;

	j = 0;
	while (j < (int)sprite_sheet->height)
	{
		if (i >= (int)sprite_sheet->width || j >= (int)sprite_sheet->height)
		{
			j++;
			continue;
		}
		color = get_pixel_color(sprite_sheet, i, j);
		draw_pixel_to_game(game, i, j, color);
		j++;
	}

}

static void draw_sprite_frame(t_game *game, mlx_image_t *sprite_sheet)
{
	int i;

	if (!game || !sprite_sheet)
		return;
	i = 0;
	while (i < (int)sprite_sheet->width)
	{
		draw_sprite_row(game, sprite_sheet, i);
		i++;
	}

}
void update_animation(t_anim *anim, float delta_time) 
{
    (void) anim; (void) delta_time;
    // anim->elapsed += delta_time;
    // if (anim->elapsed > anim->frame_time) 
    // {
    //     anim->current_frame = (anim->current_frame + 1) % anim->num_frames;
    //     anim->elapsed = 0;
    // }
}

void update_update(void *param)
{
	t_game *game;
    game = (t_game *)param;
    draw_sprite_frame(game, game->anim.image[game->last_time]);
}