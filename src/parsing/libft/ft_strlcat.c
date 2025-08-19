/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:11:20 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/19 16:07:30 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_chad(size_t len, size_t dstsize, char *dst, const char *src)
{
	if (!dst && dstsize == 0)
	{
		if (!src)
			return (0);
		return (len);
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (dst == src)
		return (0);
	if (!dst && dstsize == 0)
		return (ft_chad(src_len, dstsize, dst, src));
	dst_len = ft_strlen(dst);
	if (!src)
		return (dst_len);
	if (dstsize == 0)
		return (src_len);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	copy_len = dstsize - dst_len - 1;
	if (src_len < copy_len)
		copy_len = src_len;
	ft_memcpy(dst + dst_len, src, copy_len);
	dst[dst_len + copy_len] = '\0';
	return (dst_len + src_len);
}
