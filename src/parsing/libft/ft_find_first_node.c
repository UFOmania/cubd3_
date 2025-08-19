/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:43:11 by ybassour          #+#    #+#             */
/*   Updated: 2025/01/19 18:16:20 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_find_first_node(t_list *list)
{
	t_list	*head;

	if (!list)
		return (NULL);
	head = list;
	return (head);
}
