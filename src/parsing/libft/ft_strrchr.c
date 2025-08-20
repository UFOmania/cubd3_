/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:05:08 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/20 20:08:07 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*ptr;
	size_t	len;

	chr = (char)c;
	ptr = NULL;
	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == chr)
			ptr = (char *)&s[len];
		len++;
	}
	if (s[len] == chr)
		ptr = (char *)&s[len];
	return (ptr);
}
