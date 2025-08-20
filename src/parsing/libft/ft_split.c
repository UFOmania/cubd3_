/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:36:21 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/20 20:09:35 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t		len;
	size_t		in_word;

	len = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			len++;
		}
		s++;
	}
	return (len);
}

static char	*ft_strappend(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	i = 0;
	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

static char	**ft_s_string(char **ptr, size_t word_count, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			ptr[i] = ft_strappend(s, c);
			if (!ptr[i])
			{
				while (i > 0)
					free(ptr[--i]);
				free(ptr);
				return (NULL);
			}
		}
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**ptr;

	if (!s)
		return (NULL);
	word_count = ft_count_word(s, c);
	ptr = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_s_string(ptr, word_count, s, c);
	return (ptr);
}
