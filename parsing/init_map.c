#include "header.h"
void init_parsed_flags(t_map_mg *game_mg)//should repace this 
{
    for (int i = 0; i < 6; i++)
        game_mg->parsed_flags[i] = -1;
}

void init_floor_color(t_map_mg *game_mg)//should repace this 
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 10; j++)
            game_mg->floor_color[i][j] = -1;
}

void init_game_mg(t_map_mg *game_mg)//should repace this 
{
    game_mg->maps = NULL;
    game_mg->north = NULL;
    game_mg->south = NULL;
    game_mg->west = NULL;
    game_mg->east = NULL;
    init_parsed_flags(game_mg);
    init_floor_color(game_mg);
}
