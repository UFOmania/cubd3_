/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normilize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:30 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 14:38:39 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

double	normilize_angle(double angle)
{
	if (angle >= 2 * M_PI)
		angle = fmod(angle, 2 * M_PI);
	return (angle);
}
