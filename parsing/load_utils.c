#include "../include/header.h"

int load_texture(t_game *game)
{
    game->n_texture.texture = mlx_xpm_file_to_image(game->mlx, game->map_mg->north,
                                &game->n_texture.width, &game->n_texture.height);
    game->s_texture.texture = mlx_xpm_file_to_image(game->mlx, game->map_mg->south,
                                &game->s_texture.width, &game->s_texture.height);
    game->w_texture.texture = mlx_xpm_file_to_image(game->mlx, game->map_mg->west,
                                &game->w_texture.width, &game->w_texture.height);
    game->e_texture.texture = mlx_xpm_file_to_image(game->mlx, game->map_mg->east,
                                &game->e_texture.width, &game->e_texture.height);

    if (!game->n_texture.texture || !game->s_texture.texture ||
        !game->w_texture.texture || !game->e_texture.texture)
        {
            printf("b\b\b\b bbbbbbbbbbbb \n \a\a\a\a\a\a\a\a\a \n\n\n\n");
            return (0);
        } // failure
    return (1); // success
}
