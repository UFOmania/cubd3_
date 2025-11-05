/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:10:02 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 11:57:09 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

void play_music(void)
{
  //system("afplay music/price-of-freedom-33106.mp3 &");   // macOS
	// system("mpg123 -q music.mp3 &"); // Linux
}

void stop_music(void)
{
  system("killall afplay"); // macOS - this kills the 'afplay' process
	//system("killall mpg123"); // Linux
}

void play_music_atck(void)
{
    system("afplay music/g36-e-fire-88029.mp3 &");   // macOS
    // system("mpg123 -q music/war-99133.mp3 &"); // Linux
}

void stop_music_atck(void)
{
    system("killall afplay"); // macOS
    // system("killall mpg123"); // Linux
}