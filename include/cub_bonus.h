/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <massrayb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:45 by massrayb          #+#    #+#             */
/*   Updated: 2025/11/05 18:46:24 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <math.h>
# include ".MLX42.h"
# include "libft.h"
# include "parsing_bonus.h"
# include <time.h>

# define R_FAIL 0
# define R_SUCCESS 1
# define SPRITE_W 100
# define SPRITE_H 100
# define WIDTH 1280.0
# define HEIGHT 720.0
# define FOV 50.0
# define TILE_SIZE 100.0
# define MOVE_SPEED 10.0
# define PLAYER_RADIUS 15.0
# define ROT_SPEED 0.1
#define MAX_DOOR_HITS 4
# define HORIZONTAL 1
# define VERTICAL 2
# define N 0
# define S 1
# define W 2
# define E 3

static 	const int CENTER_X_MOUSE = WIDTH / 2;
static const int CENTER_Y_MOUSE = HEIGHT / 2;
#define SPRITE_OFFSET_X 550
#define SPRITE_OFFSET_Y 370

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_ray
{
	t_vec2	hit_pos;
	double	len;
	double	ray_angle;
	int		tex_hit_side;
	float distance;
	float	ray_x;
    float	ray_y;
	float	d_x;
    float	d_y;
		int		map_x;
	int		map_y;;
}	t_ray;

typedef struct s_player
{
	t_vec2	pos;
	double	angle;
	int		go_right;
	int		go_up;
	int		rotate_right;
	int		rotate_right_mouse;
    int mouse_down;
	int is_over_gang;
	double dir_x;    // direction vector x
	double dir_y;    // direction vector y
	double plane_x;  // camera plane x
	double plane_y;  // camera plane 
	int x; // for mr
    int y; // for me
    char dir;  // 'N', 'S', 'E', or 'W'
	 int cell_x; // for me
    int cell_y; // for me
	mlx_image_t* image; // for me
}	t_player;
// --- Animation state ---
// typedef struct s_anim {
//     int current_frame;
//     float elapsed;
//     int num_frames;
//     float frame_time;
// } t_anim;
typedef struct s_anim 
{
    mlx_image_t *image[20];
    int width;
    int height;
} t_anim;

#define STEP_SIZE 2
#define PLAYER_SPEED 4.0f  
#define ROTATE_SPEED 0.05f  

#define WIN_W 1280
#define WIN_H 720
#define CELL_SIZE 30
#define PLAYER_SIZE 30
// #define MOVE_SPEED 5
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
typedef struct s_door
{
    int cell_x;
    int cell_y;
	int x; // for mr
    int y; // for me
    float offset;
	int orientation; bool active;
	int count_door;
	mlx_image_t* image; // for me
	struct s_door *next;
} t_door;


typedef struct s_minimap
{
	int				_x_player;
	int				_y_player;
	int px;
    int py;
    int view;
    int cell_size;
    int map_h;
    int map_w;
	int y_start ;
    int y_end ;
    int x_start ;
    int x_end;
	void *image[10];
	int draw_y;
	int draw_x;
	char c;
	int _cell_size;
	
}t_minimap;
typedef struct s_door_hit 
{
    t_door *door;
    float distance;
    int orientation;
    float ray_x;
    float ray_y;
} t_door_hit;

typedef struct s_door_render
{
	int		column_height;
	float	open_factor;
	int		visible_height;
	int		shift_up;
}	t_door_render;

typedef struct s_game
{
	mlx_image_t*	image; // for me
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	mlx_image_t		*texture[4];
	mlx_image_t	 	*sprite_sheet;
	mlx_image_t		*door_img;
    t_anim			anim;
	char			**map;
	double			ppd;
	int				floor_color;
	int				ceiling_color;
	t_ray			ray;
	t_door			door;
	t_door			*ptrdoor;

	t_minimap		minimap;
	int				last_time;
	 bool			_mouse_click ;
	 bool ignore_next_mouse;
	 bool has_touched_mouse;
	 bool mouse_locked;
}	t_game;

typedef struct s_raycast_args
{
	int		y_on_screen;
	int		x_on_screen;
	int		tex_x;
	int		tex_y;
	double	wall_h;
	double	margen;
	t_ray	ray;
}	t_raycast_args;



void			input(mlx_key_data_t keydata, void *param);
void			close_game(void *param);
void			update(void *param);
void			apply_inputs(t_player *player, char **map);

//init
int				init_game(t_game *game, char *map_name);
int				load_textures(t_game *game, t_map_mg *mg);
mlx_image_t		*load_texture(t_game *game, char *src);
//raycast
t_ray			cast_ray(t_game *game, t_vec2 pos, double aray_angle);
void			raycast(t_game *game);
void			do_render(t_game *game, t_raycast_args *a);

//utils
double			deg_to_rad(double deg);
double			normilize_angle(double angle);
int				get_rgba(int r, int g, int b, int a);
double			distance(t_vec2 a, t_vec2 b);
unsigned int	get_pixel_color(mlx_image_t *img, uint32_t x, uint32_t y);
void			clear_game(t_game *game);
///
void			catch_mouse_click(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

void			catch_mouse_move(double xpos, double ypos, void *param);
void			stop_music();
void			play_music(void);
void			play_music_atck(void);
void			update_update(void *param);

t_player		get_player_position(char *mapp[]);
void			ft_fill_map(t_game *game);
void			ft_raycast_doors(t_game *game);
void			ft_draw_door(t_game *game, t_door *door);
void			ft_update_door_3d(t_game *game);
t_door			*create_list_door(char **map);
int				is_over_gang(void *param);
int				increamte_gnag_shoot(void *param);
int				init_game_anim(t_game  *game ,t_anim *anim);

int				check_door_orientation(char **map, int x, int y);
int				hit_door(char **map, int map_x, int map_y);
void			draw_column(t_game *game, int screen_x, int start , int end ,int tex_x);
int				is_vertical_or_horizontal_door_hit(char **map, float door_x, float door_y);
t_door			*get_target_door(t_game *game, int map_x, int map_y);
int				cast_ray_collect_doors(t_game *game, float ray_angle, t_door_hit *hits);
void			ft_draw_player(t_game *game, int px, int py, int cell_size);
void			ft_minimap_init(t_game *game, t_minimap *minimap);
void			ft_draw_rays_minimap(t_game *game, t_minimap *minimap);
void			clear_doors(t_game *game);
// void			process_mouse_rotation(t_game *game,double xpos, double ypos);
void			process_mouse_rotation(t_game *game);
#endif