/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:40 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 14:23:53 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_mandatory.h"

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	apply_inputs(&game->player, game->map);
	raycast(game);
}
