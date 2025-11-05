/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:48:49 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 14:23:53 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_mandatory.h"

static void	clear_images(t_game *game)
{
	if (game->img)
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
	free_map(game->map);
	clear_images(game);
	mlx_close_window(game->mlx);
}
