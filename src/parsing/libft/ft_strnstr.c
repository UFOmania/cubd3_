/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:32:04 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/27 15:32:09 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isfound(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (str2[i] != '\0' && str1[i] != '\0' && i < len)
	{
		if (str1[i] != str2[i])
		{
			return (0);
		}
		i++;
	}
	if (str2[i] == '\0')
	{
		return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *pattern, size_t len)
{
	size_t	i;

	i = 0;
	if (!*pattern)
		return ((char *)str);
	while (i < len && str[i] != '\0')
	{
		if (str[i] == pattern[0])
		{
			if (ft_isfound(str + i, pattern, len - i))
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}
