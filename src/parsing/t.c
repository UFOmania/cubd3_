
#include  <libc.h>
// int get_long_line_in_map(int fd)
// {
// 	char *line;
// 	int line_leng;

// 	if (fd < 0)
// 		return (perror ("Errorr: fd get_long_line_in_map \n"), - 1) ; //todo change the error sms when you com
// 	line_leng = 0;
// 	while (1)
// 	{
// 		line = get_next_line (fd);
// 		if (!line)
// 		{
// 			free (line);
// 			break;
// 		}
// 		if (is_has_space_one_zero(line))
// 		{
// 			if (line_leng < (int)ft_strlen(line))
// 				line_leng = (int)ft_strlen(line);
// 		}
// 		free (line);
// 	}
// 	return (line_leng);
// }


// #include <stdio.h>
// #include <limits.h>
// #include <stdint.h>

// #include <stdio.h>
// #include <limits.h>
// #include <stdlib.h>

// int main(void) {
//     char buffer[32];

//     // Convert CHAR_MIN to string and back to int using atoi
//     sprintf(buffer, "%d", CHAR_MIN);
//     printf("CHAR_MIN : %d\n", atoi(buffer));

//     sprintf(buffer, "%d", CHAR_MAX);
//     printf("CHAR_MAX : %d\n", atoi(buffer));

//     sprintf(buffer, "%d", SHRT_MIN);
//     printf("SHRT_MIN : %d\n", atoi(buffer));

//     sprintf(buffer, "%d", SHRT_MAX);
//     printf("SHRT_MAX : %d\n", atoi(buffer));

//     sprintf(buffer, "%u", USHRT_MAX);
//     printf("USHRT_MAX : %d\n", atoi(buffer));  // atoi returns int; use cast or strtoul for unsigned

//     sprintf(buffer, "%d", INT_MIN);
//     printf("INT_MIN : %d\n", atoi(buffer));

//     sprintf(buffer, "%d", INT_MAX);
//     printf("INT_MAX : %d\n", atoi(buffer));

//     sprintf(buffer, "%u", UINT_MAX);
//     printf("UINT_MAX : %d\n", atoi(buffer));  // atoi returns int; cast or strtoul better

//     // For long values:
//     sprintf(buffer, "%ld", LONG_MIN);
//     printf("LONG_MIN : %d\n", atoi(buffer));  // use atol for long

//     sprintf(buffer, "%ld", LONG_MAX);
//     printf("LONG_MAX : %d\n", atoi(buffer));

//     sprintf(buffer, "%lu", ULONG_MAX);
//     printf("ULONG_MAX : %d\n", atoi(buffer)); // strtoul for unsigned long

//     // For long long values:
//     sprintf(buffer, "%lld", LLONG_MIN);
//     printf("LLONG_MIN : %d\n", atoi(buffer));  // atoll for long long

//     sprintf(buffer, "%lld", LLONG_MAX);
//     printf("LLONG_MAX : %d\n", atoi(buffer));

//     sprintf(buffer, "%llu", ULLONG_MAX);
//     printf("ULLONG_MAX : %d\n", atoi(buffer)); // strtoull for unsigned long long

//     return 0;
// }
// // int parse_line(t_game_mg *game_mg, char *line, int *i)
// // {
// //     int j;
    
// //     if (ft_strncmp(line, "NO ", 3) == 0)
// //     {
// //         if (game_mg->parsed_flags[0] != -1)
// //             return (perror("Error: Duplicate NO"), 1);
// //         game_mg->north = line;
// //         if (!game_mg->north)
// //             return (perror("Error: strdup"), 1);
// //         game_mg->parsed_flags[0] = 1;
// //     }
// //     else if (ft_strncmp(line, "SO ", 3) == 0)
// //     {
// //         if (game_mg->parsed_flags[1] != -1)
// //             return (perror("Error: Duplicate SO"), 1);
// //         game_mg->south =  line;
// //         if (!game_mg->south)
// //             return (perror("Error: strdup"), 1);
// //         game_mg->parsed_flags[1] = 1;
// //     }
// //     else if (ft_strncmp(line, "WE ", 3) == 0)
// //     {
// //         if (game_mg->parsed_flags[2] != -1)
// //             return (perror("Error: Duplicate WE"), 1);
// //         game_mg->west = line;
// //         if (!game_mg->west)
// //             return (perror("Error: strdup"), 1);
// //         game_mg->parsed_flags[2] = 1;
// //     }
// //     else if (ft_strncmp(line, "EA ", 3) == 0)
// //     {
// //         if (game_mg->parsed_flags[3] != -1)
// //             return (perror("Error: Duplicate EA"), 1);
// //         game_mg->east =  line;
// //         if (!game_mg->east)
// //             return (perror("Error: strdup"), 1);
// //         game_mg->parsed_flags[3] = 1;
// //     }
// //     else if (ft_strncmp(line, "F ", 2) == 0)
// //     {
// //         if (game_mg->parsed_flags[4] != -1)
// //             return (perror("Error: Duplicate Floor Color"), 1);
// //         game_mg->floor_color[0][0] = rgb_string_to_int(line);
// //         if (game_mg->floor_color[0][0] == -1)
// //             return (perror("Error: Invalid Floor Color"), 1);
// //         game_mg->parsed_flags[4] = 1;
// // 		free(line);
// //     }
// //     else if (ft_strncmp(line, "C ", 2) == 0)
// //     {
// //         if (game_mg->parsed_flags[5] != -1)
// //             return (perror("Error: Duplicate Ceiling Color"), 1);
// //         game_mg->floor_color[1][0] = rgb_string_to_int(line);
// //         if (game_mg->floor_color[1][0] == -1)
// //             return (perror("Error: Invalid Ceiling Color"), 1);
// //         game_mg->parsed_flags[5] = 1;
// // 		free(line);
// //     }
// //     else if (is_has_space_one_zero(line))
// //     {
// //         j = *i;
// //         game_mg->maps[j] = line;
// //         if (!game_mg->maps[j])
// //         {
// //             return fprintf(stderr, "Error: strdup failed\n"), 1;
// //         }
// //         j++;
// //         *i = j;
// //     }
// //     else
// //     {
// //        fprintf(stderr, "Error: [%s]\n", line);
// //     //   free(line);
// //     //    line = NULL;
// //        return 1;
// //     }

// //     return 0; // success
// // }