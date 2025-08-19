/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:55:29 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/29 23:27:23 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (NULL);
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
	return (ptr);
}
