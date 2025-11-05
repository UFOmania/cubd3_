/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:48:53 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 14:38:39 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

double	deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	rad_to_deg(double degrees)
{
	return (degrees * (180.0 / M_PI)); //TODO THIS FOR 
}
