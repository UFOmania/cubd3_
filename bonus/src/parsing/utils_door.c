/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 03:29:59 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 21:31:08 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static t_door	*create_new_door(int x, int y)
{
	t_door	*new;

	new = malloc(sizeof(t_door));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->offset = 0.0f;
	new->orientation = 0;
	new->active = false;
	new->count_door = 0;
	new->next = NULL;
	return (new);
}

static bool	append_door(t_door **head, t_door **tail, t_door *new)
{
	if (!new)
		return (false);
	if (!*head)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
	return (true);
}

static void	free_doors_with_error(t_door *head)
{
	t_door	*tmp;

	tmp = NULL;
	display_error_input_malloc(ERR_MALLOC_FAILED, NULL);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

static bool	process_door_row(char **map, int y, t_door **head, t_door **tail)
{
	int		x;
	t_door	*new;

	x = 0;
	new = NULL;
	while (map[y][x])
	{
		if (map[y][x] == 'D')
		{
			new = create_new_door(x, y);
			if (!append_door(head, tail, new))
			{
				free_doors_with_error(*head);
				return (false);
			}
			(*head)->count_door++;
		}
		x++;
	}
	return (true);
}

t_door	*create_list_door(char **map)
{
	t_door	*head;
	t_door	*tail;
	int		y;

	head = NULL;
	tail = NULL;
	y = 0;
	if (!map)
		return (NULL);
	while (map[y])
	{
		if (!process_door_row(map, y, &head, &tail))
			return (NULL);
		y++;
	}
	if (!head)
		print_error("Error: map does not contain any door");
	return (head);
}
