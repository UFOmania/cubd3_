#include "../include/header.h"

int init_parsed_flags(t_map_mg *game_mg)//should repace this 
{
    int i;
    if (!game_mg)
        return (1);
    i = 0;
    while (i < 6)
    {
        game_mg->parsed_flags[i] = -1;
         i++;
    }
    return 0;
}

int init_floor_color(t_map_mg *game_mg)//should repace this 
{
    int i;
    int j;

    if (!game_mg)
        return (1);
    i = 0;
    j = 0;
    while (i < 2)
    {
        while (j < 10)
        {
            game_mg->floor_color[i][j] = -1;
            j++;
        }
        i++;
    }
    return 0;
}

int init_map_mg(t_map_mg *game_mg)//should repace this 
{
    if (!game_mg)
        return (1);
    game_mg->maps = NULL;
    game_mg->north = NULL;
    game_mg->south = NULL;
    game_mg->west = NULL;
    game_mg->east = NULL;
    if (init_parsed_flags(game_mg))
        return (1);
    if (init_floor_color(game_mg))
        return (1);
    return 0;
}
