/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:48:49 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/06 17:58:33 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static void	clear_images(t_game *game)
{
	int	i;

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
	i = 0;
	while (game->anim.image[i] && i < 8)
	{
		mlx_delete_image(game->mlx, game->anim.image[i]);
		i++;
	}
}

void	clear_doors(t_game *game)
{
	t_door	*temp;
	t_door	*next;

	temp = game->ptrdoor;
	if (!temp)
		return ;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	game->ptrdoor = NULL;
}

void	clear_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	clear_images(game);
	mlx_close_window(game->mlx);
	clear_doors(game);
}
