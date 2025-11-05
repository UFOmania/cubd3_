/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:54:34 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 18:48:32 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static bool	is_door_between_walls(char **map, int x, int y)
{
	if (x == 0 || y == 0 || !map[y + 1] || !map[y][x + 1])
		return (false);
	if (map[y][x - 1] == 'D' || map[y][x + 1] == 'D')
	{
		print_error("door touches another door horizontally");
		return (false);
	}
	if (map[y - 1][x] == 'D' || map[y + 1][x] == 'D')
	{
		print_error("door touches another door vertically");
		return (false);
	}
	if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
		return (true);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
		return (true);
	print_error("door not placed between two walls");
	return (false);
}

static bool	check_door_row(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == 'D')
		{
			if (!is_door_between_walls(map, x, y))
				return (false);
		}
		x++;
	}
	return (true);
}

bool	is_valid_door(char **map)
{
	int	y;

	if (!map || !*map)
		return (display_error_input_malloc(ERR_NULL_INPUT, NULL), false);
	y = 0;
	while (map[y])
	{
		if (!check_door_row(map, y))
			return (false);
		y++;
	}
	return (true);
}
