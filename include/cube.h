#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
// # include "../src/libft/libft.h"
# include "../src/parsing/header.h"

#define R_FAIL 0
#define R_SUCCESS 1

//settings
#define WIDTH 800
#define HEIGHT 800
#define MOVE_SPEED 20
#define FOV 50.0
#define TILE_SIZE 80.0

#define CEILING_COLOR   0xFFAAAA   // light red/pink
#define FLOOR_COLOR     0xAAAAFF   // light blue
#define WALL_COLOR      0x888888   // gray

#define HORIZONTAL 11
#define VERTICAL 22



typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_frame;


typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	int		up;
	int		right;
	int		mov_up;
	int		mov_right;
	int		rot_dir;
	double	rot_angle;
}	t_player;

typedef struct s_ray
{
	t_vec2	hit_pos;
	char	type;
	int		side;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*texture;
	void		*door;
	t_frame		frame;
	t_player	player;
}	t_game;

//utils
void put_pixel(t_frame *frame, t_vec2 pos, int color);
unsigned int get_pixel(void *texture, t_vec2 pos);

//shapes
void	draw_rect(t_frame *frame, t_vec2 start, t_vec2 size, int color);
void	draw_circle(t_frame *frame, t_vec2 pos, int radius, int color);
void	draw_line(t_frame *data, t_vec2 a, t_vec2 b, int color);
void	draw_map(t_game *game);

//map
int	read_map(t_game *game);

//init_game
int	init_game(t_game *game);

//update
int update(void *t);

//close
int close_game(void *t);

//input
int	key_press(int key_code, void *t);
int	key_release(int key_code, void *t);
int apply_input(t_game *game);

//player
void draw_player(t_game *game);

//raycast
void	raycast(t_game *game);
t_ray	cast_ray(t_game *game, t_vec2 start, double angle);
double distance(t_vec2 a, t_vec2 b);

#endif