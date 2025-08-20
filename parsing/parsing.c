#include "../include/header.h"

int parse_rgb_component(const char *str)
{
    int value;
    int i;

    value = 0;
    i = 0;
    if (!str || !*str)
        return (-1);
    if (str[0] == '-')
        return (-1);
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        value = value * 10 + (str[i] - '0');
        if (value > 255)
            return (-1);
        i++;
    }
    return (value);
}

int rgb_string_to_int(const char *color_str)
{
    int r = 0, g = 0, b = 0;
    int channel = 0;  // 0=R, 1=G, 2=B
    int i = 0;
	int spe = 0;
    int value;
    if (!color_str)
        return (-1);
    if (color_str[0] == 'F' || color_str[0] == 'C')
        i++;
     while (color_str[i] && color_str[i] == ' ')
        i++;
    while (color_str[i])
    {
		if (!ft_isdigit((unsigned char)color_str[i]))
			spe++;
        if (ft_isdigit((unsigned char)color_str[i]))
        {
            value = parse_rgb_component(color_str + i);
            if (value < 0 || value > 255)
                return (-1);
            if (channel == 0)
                r = value;
            else if (channel == 1)
                g = value;
            else if (channel == 2)
                b = value;
            channel++;
            while (ft_isdigit((unsigned char)color_str[i]))
                i++;
        }
        else
            i++;
    }
    if (channel != 3 || spe != 3)
        return (-1);
    return ((r << 16) | (g << 8) | b);
}

int  parse_no_so(t_map_mg *game_mg, char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        if (game_mg->parsed_flags[0] != -1)
            return (display_error_direction(ERR_DUPLICATE_NO));
        game_mg->north = is_valid_texture(line, "NO");
        if (!game_mg->north)
            return (1);
        game_mg->parsed_flags[0] = 1;
        return (0);
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        if (game_mg->parsed_flags[1] != -1)
            return (display_error_direction(ERR_DUPLICATE_SO));
        game_mg->south = is_valid_texture(line, "SO");
        if (!game_mg->south)
            return (1);
        game_mg->parsed_flags[1] = 1;
        return (0);
    }
    return (-1);
}


int parse_we_ea(t_map_mg *game_mg, char *line)
{
    if (ft_strncmp(line, "WE ", 3) == 0)
    {
        if (game_mg->parsed_flags[2] != -1)
            return (display_error_direction(ERR_DUPLICATE_WE));
        game_mg->west = is_valid_texture(line, "WE");
        if (!game_mg->west)
            return (1);
        game_mg->parsed_flags[2] = 1;
        return (0);
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        if (game_mg->parsed_flags[3] != -1)
            return (display_error_direction(ERR_DUPLICATE_EA));
        game_mg->east = is_valid_texture(line, "EA");
        if (!game_mg->east)
            return (1);
        game_mg->parsed_flags[3] = 1;
        return (0);
    }
    return (-1);
}


int parse_colors(t_map_mg *game_mg, char *line)
{
    if (ft_strncmp(line, "F ", 2) == 0)
    {
        if (game_mg->parsed_flags[4] != -1)
            return (display_error_color(ERR_DUPLICATE_FLOOR_COLOR));
        game_mg->floor_color[0][0] = rgb_string_to_int(line);
        if (game_mg->floor_color[0][0] == -1)
            return (display_error_color(ERR_INVALID_FLOOR_COLOR));
        game_mg->parsed_flags[4] = 1;
        free(line);
        return (0);
    }
    else if (ft_strncmp(line, "C ", 2) == 0)
    {
        if (game_mg->parsed_flags[5] != -1)
            return (display_error_color(ERR_DUPLICATE_CEIL_COLOR));
        game_mg->floor_color[1][0] = rgb_string_to_int(line);
        if (game_mg->floor_color[1][0] == -1)
        return (display_error_color(ERR_INVALID_CEIL_COLOR));
        game_mg->parsed_flags[5] = 1;
        free(line);
        return (0);
    }
    return (-1);
}

int parse_map_or_error(t_map_mg *game_mg, char *line, int *i)
{
    int j;
    if (line[0] == '\n' && *i <= 0)
    {
        free (line);
        line = NULL;
        return 0;
    }
    if (is_has_space_one_zero(line))
    {
        j = *i;
        game_mg->maps[j] = line;
        if (!game_mg->maps[j])
            return (fprintf(stderr, "Error: strdup failed\n"), 1);//should include the some error
        j++;
        *i = j;
        return (0);
    }
    fprintf(stderr, "Error:00000000 [%s]\n", line);
    return (1);
}


int parse_line(t_map_mg *game_mg, char *line, int *i)
{
    int ret;

    ret = parse_no_so(game_mg, line);
    if (ret != -1)
        return (ret);

    ret = parse_we_ea(game_mg, line);
    if (ret != -1)
        return (ret);

    ret = parse_colors(game_mg, line);
    if (ret != -1)
        return (ret);

    return (parse_map_or_error(game_mg, line, i));
}


int get_long_line_in_map(char **map)
{
    int long_line;
    int i;
    int len;

    if (!map || !*map)
        return (0);
    long_line = 0;
    i = 0;
    len = 0;
    while (map[i])
    {
        len = ft_strlen(map[i]);
        if (len > long_line)
            long_line = len;
        i++;
    }
    return (long_line);
}

static void free_map(char **map)
{
    int i = 0;
    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

char *copy_with_spaces(const char *src, int long_line)
{
    int len;
    char *dst;
    int i;

    if (!src)
        return( NULL);

    len = ft_strlen(src);
    dst = malloc(long_line + 1); // +1 for '\0'
    if (!dst)
        return (NULL);

    // Copy original string safely
    ft_strlcpy(dst, src, len + 1);

    // Fill rest with spaces using while loop
    i = len;
    while (i < long_line)
    {
        dst[i] = ' ';
        i++;
    }
    dst[long_line] = '\0';
    return (dst);
}


int  remove_newline_chars(t_map_mg *game_mg)
{
    int row;
    int col;

    if (!game_mg || !game_mg->maps)
        return (1);

    row = 0;
    while (game_mg->maps[row])
    {
        col = 0;
        while (game_mg->maps[row][col])
        {
            if (game_mg->maps[row][col] == '\n')
                game_mg->maps[row][col] = '\0';
            col++;
        }
        row++;
    }
    return (0);
}

int replace_map(t_map_mg *game_mg)
{
    int long_line;
    char **new_map;
    int i;

    if (!game_mg || game_mg->map_hi <= 0 || !game_mg->maps)
        return 1;

    long_line = get_long_line_in_map(game_mg->maps);
    new_map = malloc(sizeof(char *) * (game_mg->map_hi + 1));
    if (!new_map)
        return (1);

    i = 0;
    remove_newline_chars(game_mg);
    while (game_mg->maps[i])
    {
        new_map[i] = copy_with_spaces(game_mg->maps[i], long_line);
        if (!new_map[i])
        {
            free_map(new_map);
            return (1);
        }
        i++;
    }
    new_map[i] = NULL;

    free_map(game_mg->maps);
    game_mg->maps = new_map;
    return (0);
}

static int is_player_symbol(char c)
{
    return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int find_player_position(t_map_mg *game_mg)
{
    int row;
    int col;

    if (!game_mg || !game_mg->maps)
        return 1;
    row = 0;
    game_mg->player_count = 0;
    while (game_mg->maps[row])
    {
        col = 0;
        while (game_mg->maps[row][col])
        {
            if (is_player_symbol(game_mg->maps[row][col]))
            {
                game_mg->player_pos[0] = row;
                game_mg->player_pos[1] = col;
                game_mg->player_count++;
            }
            col++;
        }
        row++;
    }
    if (game_mg->player_count != 1)
        return 1;
    return (0);
}
