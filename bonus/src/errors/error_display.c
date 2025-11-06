/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:41:14 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/06 16:44:26 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing_bonus.h"

static int	count_nbr_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	int_to_str(char *buf, int n)
{
	long	nb;
	int		len;
	int		offset;

	nb = n;
	len = count_nbr_digits(n);
	offset = 0;
	if (nb < 0)
	{
		buf[0] = '-';
		nb = -nb;
		offset = 1;
	}
	buf[len + offset] = '\0';
	while (len-- > 0)
	{
		buf[len + offset] = (nb % 10) + '0';
		nb /= 10;
	}
}

static void	_putstr_fd(const char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	print_adjacent_open_area_error(const char *msg, int row, int col)
{
	char	buf_row[12];
	char	buf_col[12];

	int_to_str(buf_row, row);
	int_to_str(buf_col, col);
	_putstr_fd(msg, STDERR_FILENO);
	_putstr_fd(" at (", STDERR_FILENO);
	_putstr_fd(buf_row, STDERR_FILENO);
	_putstr_fd(", ", STDERR_FILENO);
	_putstr_fd(buf_col, STDERR_FILENO);
	_putstr_fd(")\n", STDERR_FILENO);
}
