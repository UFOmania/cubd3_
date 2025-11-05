/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_anim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:09:14 by ybassour          #+#    #+#             */
/*   Updated: 2025/11/05 12:06:22 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub_bonus.h"

static void	ft_set_anim_images(char **anim_image)
{
	(anim_image)[0] = "bonus/animations 1/1.png";
	(anim_image)[1] = "bonus/animations 1/2.png";
	(anim_image)[2] = "bonus/animations 1/3.png";
	(anim_image)[3] = "bonus/animations 1/4.png";
	(anim_image)[4] = "bonus/animations 1/5.png";
	(anim_image)[5] = "bonus/animations 1/6.png";
	(anim_image)[6] = "bonus/animations 1/7.png";
	(anim_image)[7] = NULL;
}

static int	ft_load_textures(mlx_texture_t **textures, char *(*anim_image))
{
	int	i;

	i = 0;
	while (anim_image[i])
	{
		textures[i] = mlx_load_png(anim_image[i]);
		if (!textures[i])
		{
			print_error("error: failed to load PNG texture");
			while (--i >= 0)
				mlx_delete_texture(textures[i]);
			return (R_FAIL);
		}
		i++;
	}
	return (R_SUCCESS);
}

static int	ft_convert_to_images(t_game *game,
			t_anim *anim, mlx_texture_t **textures)
{
	mlx_image_t	*image;
	int			i;

	i = 0;
	while (textures[i] != NULL && i < 7)
	{
		image = mlx_texture_to_image(game->mlx, textures[i]);
		mlx_delete_texture(textures[i]);
		if (!image)
		{
			print_error("error: failed to convert texture to image");
			while (--i >= 0)
				mlx_delete_image(game->mlx, anim->image[i]);
			return (R_FAIL);
		}
		anim->image[i] = image;
		i++;
	}
	return (R_SUCCESS);
}

int	init_game_anim(t_game *game, t_anim *anim)
{
	char			*anim_image[8];
	mlx_texture_t	*textures[8];

	ft_set_anim_images(anim_image);
	if (ft_load_textures(textures, anim_image) == R_FAIL)
		return (R_FAIL);
	if (ft_convert_to_images(game, anim, textures) == R_FAIL)
		return (R_FAIL);
	return (R_SUCCESS);
}
