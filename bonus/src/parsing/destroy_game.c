/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:01:39 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 11:47:08 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing_mandatory.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_map_mg(t_map_mg *game_mg)
{
	if (!game_mg)
		return ;
	if (game_mg->north)
		free(game_mg->north);
	if (game_mg->south)
		free(game_mg->south);
	if (game_mg->west)
		free(game_mg->west);
	if (game_mg->east)
		free(game_mg->east);
	free_map(game_mg->maps);
	free(game_mg);
}
