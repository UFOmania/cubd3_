#include "../include/header.h"


int get_size(const char *map_file)
{
	int len = 0;
	int fd;
	char *line;

	if (!map_file)
		return -1;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		display_error_file(ERR_CANNOT_OPEN_FILE, map_file);
		return -1;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (is_has_space_one_zero(line))
			len++;
	   free(line);
	}
	close(fd);
	return len;
}

int	loop_read_map(t_map_mg *game_mg, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		else if (parse_line(game_mg, line , &i))
		{
		  	free(line);
			close(fd);
			game_mg->maps[i] = NULL;
			fprintf(stderr, "Error: cannot open file\n");
		  	//free_game_mg(game_mg);
			return (1);
		}

	}
	game_mg->maps[i] = NULL;
	return (0);
}

int open_map(char *map_name, t_map_mg *game_mg)
{
	int	fd;
	int	size;
	int	vl;

	size = get_size(map_name);
	game_mg->map_hi = size;
	if (!map_name)
		return (display_error_file(ERR_NULL_MAP_NAME, NULL));

	if (size <= 0)
		return (display_error_file(ERR_INVALID_MAP_SIZE, NULL), 1);

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (display_error_file(ERR_CANNOT_OPEN_FILE, map_name));

	game_mg->maps = malloc(sizeof(char *) * (size + 1));
	if (!game_mg->maps)
	{
		close(fd);
		return (display_error_input_malloc(ERR_MALLOC_FAILED, NULL));
	}
   vl =  loop_read_map(game_mg, fd);
   close(fd);
   return (vl);
}


int apply_map_ope(char *map_name , t_map_mg *game_mg )
{


	if (open_map(map_name, game_mg))
	{
		free_game_mg(game_mg); // if the malloc map is return null this made segv
		return 1;
	}

	if (!is_valid_config_count(game_mg) || !validate_game_mg(game_mg))
	{
		free_game_mg(game_mg);
		return (display_error_file(ERR_INVALID_MAP_CONFIG, NULL));
	}
	if (replace_map(game_mg))//should repace this
	{
		free_game_mg(game_mg);
		return 1;
	}
	if (check_map_enclosure(game_mg->maps))
	{	
		free_game_mg(game_mg);
		return 1;
	}
	if (find_player_position(game_mg))
	{	
		free_game_mg(game_mg);
		return 1;
	}
	//prin_deb(game_mg);
//    free_game_mg(game_mg);
	return 0;
}
