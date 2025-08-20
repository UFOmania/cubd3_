/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:44:48 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/24 17:17:26 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	str_len;
	size_t	i;

	str_len = 0;
	i = 0;
	while (s1[str_len] != '\0')
		str_len++;
	ptr = malloc(str_len + 1);
	if (!ptr)
		return (NULL);
	while (i < str_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[str_len] = '\0';
	return (ptr);
}
