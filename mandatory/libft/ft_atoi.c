/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:33:11 by ybassour          #+#    #+#             */
/*   Updated: 2025/02/09 12:18:22 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_handlespaces(const char *str)
{
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

static const char	*ft_handlesign(const char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	str = ft_handlespaces(str);
	str = ft_handlesign(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		if (number > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		number = number * 10 + (*str) - 48;
		str++;
	}
	number *= sign;
	return (number);
}
