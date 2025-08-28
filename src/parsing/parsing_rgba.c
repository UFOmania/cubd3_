#include "../../include/parsing.h"

// int parse_rgb_component(const char *str)
// {
//     int value;
//     int i;

//     value = 0;
//     i = 0;
//     if (!str || !*str)
//         return (-1);
//     if (str[0] == '-')
//         return (-1);
//     while (str[i] && (str[i] >= '0' && str[i] <= '9'))
//     {
//         value = value * 10 + (str[i] - '0');
//         if (value > 255)
//             return (-1);
//         i++;
//     }
//     return (value);
// }

// int rgb_string_to_int(const char *color_str)
// {
//     int r = 0, g = 0, b = 0;
//     int channel = 0;  // 0=R, 1=G, 2=B
//     int i = 0;
// 	int spe = 0;
//     int value;
//     if (!color_str)
//         return (-1);
//     if (color_str[0] == 'F' || color_str[0] == 'C')
//         i++;
//      while (color_str[i] && color_str[i] == ' ')
//         i++;
//     while (color_str[i])
//     {
// 		if (!ft_isdigit((unsigned char)color_str[i]))
// 			spe++;
//         if (ft_isdigit((unsigned char)color_str[i]))
//         {
//             value = parse_rgb_component(color_str + i);
//             if (value < 0 || value > 255)
//                 return (-1);
//             if (channel == 0)
//                 r = value;
//             else if (channel == 1)
//                 g = value;
//             else if (channel == 2)
//                 b = value;
//             channel++;
//             while (ft_isdigit((unsigned char)color_str[i]))
//                 i++;
//         }
//         else
//             i++;
//     }
//     if (channel != 3 || spe != 3)
//         return (-1);
// 	int a = 255;
//     return ((r << 24) | (g << 16) | b << 8 | a);
// }



int	parse_rgb_component(const char *str)
{
	int	value;
	int	i;

	if (!str || !*str || str[0] == '-')
		return (-1);
	value = 0;
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		value = value * 10 + (str[i] - '0');
		if (value > 255)
			return (-1);
		i++;
	}
	return (value);
}

static int	extract_rgb_components(const char *str, int *r, int *g, int *b)
{
	int	channel;
	int	value;
	int	i;
	int	spe;

	i = 0;
	channel = 0;
	spe = 0;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			spe++;
		if (ft_isdigit((unsigned char)str[i]))
		{
			value = parse_rgb_component(str + i);
			if (value < 0 || value > 255)
				return (-1);
			if (channel == 0)
				*r = value;
			else if (channel == 1)
				*g = value;
			else if (channel == 2)
				*b = value;
			channel++;
			while (ft_isdigit((unsigned char)str[i]))
				i++;
		}
		else
			i++;
	}
	if (channel != 3 || spe != 3)
		return (-1);
	return (0);
}

int	rgb_string_to_int(const char *color_str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (!color_str)
		return (-1);
	i = 0;
	if (color_str[0] == 'F' || color_str[0] == 'C')
		i++;
	while (color_str[i] && color_str[i] == ' ')
		i++;
	if (extract_rgb_components(color_str + i, &r, &g, &b) == -1)
		return (-1);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}
