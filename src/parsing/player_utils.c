/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:40:29 by massrayb          #+#    #+#             */
/*   Updated: 2025/08/28 11:40:49 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static int	is_player_symbol(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static void	find_players_in_map(t_map_mg *game_mg)
{
	int	row;
	int	col;

	row = 0;
	game_mg->player_count = 0;
	while (game_mg->maps[row])
	{
		col = 0;
		while (game_mg->maps[row][col])
		{
			if (is_player_symbol(game_mg->maps[row][col]))
			{
				game_mg->player_seen = game_mg->maps[row][col];
				game_mg->player_pos[0] = row;
				game_mg->player_pos[1] = col;
				game_mg->maps[row][col] = '0';
				game_mg->player_count++;
			}
			col++;
		}
		row++;
	}
}

static int	validate_single_player(t_map_mg *game_mg)
{
	if (game_mg->player_count != 1)
		return (1);
	return (0);
}

int	check_player_in_map(t_map_mg *game_mg)
{
	if (!game_mg || !game_mg->maps)
		return (1);
	find_players_in_map(game_mg);
	if (validate_single_player(game_mg))
		return (1);
	return (0);
}
