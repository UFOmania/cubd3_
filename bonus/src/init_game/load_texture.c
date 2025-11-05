/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:17 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 14:38:39 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

mlx_image_t	*load_texture(t_game *game, char *src)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(src);
	if (tex == NULL)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);
	return (img);
}

int	load_textures(t_game *game, t_map_mg *mg)
{
	game->door_img = load_texture(game, "bonus/animations 1/door.png");
	*(game->texture + S) = load_texture(game, mg->north);
	*(game->texture + N) = load_texture(game, mg->south);
	*(game->texture + E) = load_texture(game, mg->west);
	*(game->texture + W) = load_texture(game, mg->east);
	if (!*(game->texture + N) || !*(game->texture + S) || \
	!*(game->texture + W) || !*(game->texture + E) || !game->door_img)
	{
		mlx_delete_image(game->mlx, *(game->texture + S));
		mlx_delete_image(game->mlx, *(game->texture + N));
		mlx_delete_image(game->mlx, *(game->texture + W));
		mlx_delete_image(game->mlx, *(game->texture + E));
		mlx_delete_image(game->mlx, game->door_img);
		return (mlx_strerror(mlx_errno), R_FAIL);
	}
	return (R_SUCCESS);
}
