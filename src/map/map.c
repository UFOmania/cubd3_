#include "../../include/cube.h"

int read_map(t_game *game)
{
	int	fd;
	int i;
	char	*tmp;

	game->map = malloc(sizeof(char *) * 10);
	if (!game->map)
		return(perror("read_map"), R_FAIL);
	fd = open("map", O_RDONLY);
	if (fd == -1)
		return (perror("read_map"), R_FAIL);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		game->map[i] = ft_strtrim(tmp, "\n");
		printf("%s\n",  tmp);
		free(tmp);
		i++;
	}
	printf("done\n");
	exit(0);
	return (R_SUCCESS);
}