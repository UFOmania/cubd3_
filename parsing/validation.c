#include "../include/header.h"
bool ispossible_characters(char c)
{
	return (c == ' ' || c == '1' || c == '0' || 
			c == '\n' || c == 'N' || c == 'S' || 
			c == 'E' || c == 'W' || c == 'D'); //todo remove D
}

bool is_has_space_one_zero(char *line)
{
	int i;

	if (!line || !*line)
		return (false);
	i = 0;
	
	while (line[i] != '\0')
	{
		if (!ispossible_characters(line[i]))
			return (false);
		i++;
	}
	return (true);
}
int is_valid_arg(char *map_name)
{
	char	*map_exction;

	map_exction = strrchr(map_name, '.');
	if (!map_exction)
		return (1);
	if(strcmp(map_exction, ".cub") == 0)
		return (0);
	return (1);
}

char    *is_valid_texture(char *line, const char *id)
{
	char    *path;
	int     i;
	int     fd;

	if (!line || !id)
		return (display_error_input_malloc(ERR_NULL_INPUT, NULL), NULL);
	if (ft_strncmp(line, id, ft_strlen(id)) != 0
		|| line[ft_strlen(id)] != ' ')
			return (display_error_direction(ERR_INVALID_ID), NULL);
	i = ft_strlen(id);
	while (line[i] == ' ')
		i++;
	path = ft_strdup(line + i);
	if (!path)
		return (NULL); // include strdup
	path[ft_strlen(path) - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		display_error_file(ERR_FILE_OPEN_FAILED, path);
		free(path);
		return (NULL);
	}
	close(fd);
	free(line);
	line = NULL;
	return (path);
}


bool is_valid_config_count(t_map_mg *game_mg)
{
	if (game_mg->parsed_flags[5] != 1)
		return (false);
	// if (game_mg->parsed_flags[6] != -1)
	// 	return false;
	return (true);
}

bool validate_game_mg(t_map_mg *game_mg)
{
	if (!game_mg->north || !game_mg->south || !game_mg->west || !game_mg->east)
		return (false);
	if (game_mg->floor_color[0][0] == -1 || game_mg->floor_color[1][0] == -1)
		return false;
	return (true);
}

void prin_deb(t_map_mg *game_mg)
{
	printf("Floor color: %d\n", game_mg->floor_color[0][0]);
	printf("Ceiling color: %d\n", game_mg->floor_color[1][0]);

	int i = 0;
	while (game_mg->maps[i])
	{
		 printf("Map line %d: %s\n", i, game_mg->maps[i]);
		 i++;
	}

	printf("\nNO: %s\n", game_mg->north);
	printf("SO: %s\n", game_mg->south);
	printf("WE: %s\n", game_mg->west);
	printf("EA: %s\n", game_mg->east);
}

// Checks if the map is properly enclosed by '1's, no open zeros touching spaces or edges
int check_map_enclosure(char **map)
{
    int row = 0;
    int col;

    if (!map || !*map)
    {
        printf("Error: Map is empty or invalid.\n");
        return 1;
    }

    while (map[row])
    {
        col = 0;
        while (map[row][col] != '\0')
        {
            if (map[row][col] == '0')
            {
                // Check if '0' is at any map edge (top, left, right, or bottom)
                if (row == 0 || col == 0 || !map[row + 1] || map[row][col + 1] == '\0')
                {
                    printf("Error: Open space at edge at (%d, %d)\n", row, col);
                    return 1;
                }

                // Check if '0' is adjacent to a space character
                if (map[row][col + 1] == ' ' ||
                    map[row][col - 1] == ' ' ||
                    map[row + 1][col] == ' ' ||
                    map[row - 1][col] == ' ')
                {
                    printf("Error: Space next to open area at (%d, %d)\n", row, col);
                    return 1;
                }
            }
            col++;
        }
        row++;
    }
    return (0);
}

