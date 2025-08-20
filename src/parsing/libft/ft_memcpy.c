/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:01:30 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/23 14:47:36 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	if (dest == src)
		return (dest);
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	dtemp = (unsigned char *)dest;
	stemp = (unsigned char *)src;
	while (0 < n--)
	{
		*(dtemp++) = *(stemp++);
	}
	return (dest);
}
