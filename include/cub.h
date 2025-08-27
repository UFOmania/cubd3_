#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <math.h>

#include "MLX42.h"
#include "parsing.h"
#include "libft.h"
#include <time.h>

#define R_FAIL 0
#define R_SUCCESS 1

#define WIDTH 800.0
#define HEIGHT 600.0
#define FOV 50.0
#define TILE_SIZE 100.0
#define MOVE_SPEED 10.0
#define PLAYER_RADIUS 10.0
#define ROT_SPEED 0.1

#define HORIZONTAL 1
#define VERTICAL 2
#define N 0
#define S 1
#define W 2
#define E 3

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_ray
{
	t_vec2	hit_pos;
	double	len;
	int		side;
	char	type;
	int		tex_hit_side;
}	t_ray;

typedef struct s_player
{
	int		go_right;
	int		go_up;
	int		rotate_right;
	double	angle;
	t_vec2	pos;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	mlx_image_t		*texture[4];
	char			**map;
	double			ppd;
	int				floor_color;
	int				ceiling_color;

} t_game;

void input(mlx_key_data_t keydata, void* param);
void close_game(void *param);

void update(void *param);
void	apply_inputs(t_player *player, char **map);

//init
int init_game(t_game *game, char *map_name);

//raycast
t_ray cast_ray(t_game *game, t_vec2 pos, double aray_angle);
void raycast(t_game *game);

//utils
double	deg_to_rad(double deg);
double	normilize_angle(double angle);
int		get_rgba(int r, int g, int b, int a);
double	distance(t_vec2 a, t_vec2 b);

void	clear_game(t_game *game);
#endif