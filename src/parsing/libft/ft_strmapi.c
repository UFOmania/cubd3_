/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:08:59 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/29 23:53:18 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
