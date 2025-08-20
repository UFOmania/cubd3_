/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:19:24 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/31 11:55:51 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	orginal_len;
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ptr;

	start = 0;
	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	orginal_len = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (end != 0)
		orginal_len = (end - start) + 1;
	ptr = (char *) malloc(orginal_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, orginal_len + 1);
	return (ptr);
}
