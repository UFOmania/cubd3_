/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:10:02 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 21:34:25 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

void	play_music(void)
{
	//system("afplay music/price-of-freedom-33106.mp3 &");   // macOS
}

void	stop_music(void)
{
	system("killall afplay"); // macOS - this kills the 'afplay' process
}

void	play_music_atck(void)
{
	system("afplay music/g36-e-fire-88029.mp3 &");// macOS
}

void	stop_music_atck(void)
{
	system("killall afplay"); // macOS
}
