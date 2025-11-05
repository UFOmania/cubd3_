
NAME = cub3D
NAME_BONUS = cub3D_bonus


FLAGS = -Wall -Wextra -Werror

LDLIBS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

INCLUDE_MANDATORY	= include/.MLX42.h include/libft.h include/cub_mandatory.h include/parsing_mandatory.h
INCLUDE_BONUS		= include/.MLX42.h include/libft.h include/cub_bonus.h include/parsing_bonus.h    

LIBMLX	=	mlx/libmlx42.a
LIBFT	=	libft/libft.a

SRC		=	mandatory/src/raycast/cast_ray.c \
			mandatory/src/clear/clear_game.c \
			mandatory/src/raycast/deg_to_rad.c \
			mandatory/src/raycast/get_distance.c \
			mandatory/src/raycast/get_pixel_color.c \
			mandatory/src/raycast/get_rgba.c \
			mandatory/src/init/init_game.c \
			mandatory/src/movement/input.c \
			mandatory/src/init/load_texture.c \
			mandatory/src/engine/main.c \
			mandatory/src/movement/movement.c \
			mandatory/src/raycast/normilize_angle.c \
			mandatory/src/raycast/raycast.c \
			mandatory/src/raycast/render.c \
			mandatory/src/engine/update.c \
			mandatory/src/parsing/destroy_game.c \
			mandatory/src/parsing/handle_error.c \
			mandatory/src/parsing/handle_error_utils.c \
			mandatory/src/parsing/handle_map.c \
			mandatory/src/parsing/init_map.c \
			mandatory/src/parsing/parsing.c \
			mandatory/src/parsing/parsing_map_config.c \
			mandatory/src/parsing/parsing_rgba.c \
			mandatory/src/parsing/player_utils.c \
			mandatory/src/parsing/utils.c \
			mandatory/src/parsing/valid.c \
			mandatory/src/parsing/validation.c 

SRC_BONUS =	bonus/src/door/door_utils.c \
			bonus/src/door/door_utils1.c \
			bonus/src/door/door_utils2.c \
			bonus/src/door/ft_door.c \
			bonus/src/init_game/init_game_anim.c \
			bonus/src/init_game/init_game.c \
			bonus/src/minimap/draw_minimap_rays.c \
			bonus/src/minimap/minimap_utils.c \
			bonus/src/minimap/minimap.c \
			bonus/src/mouse/mouse.c \
			bonus/src/parsing/destroy_game.c \
			bonus/src/parsing/handle_error_utils.c \
			bonus/src/parsing/handle_error.c \
			bonus/src/parsing/handle_map.c \
			bonus/src/parsing/init_map.c\
			bonus/src/parsing/parsing_map_config.c \
			bonus/src/parsing/parsing_rgba.c \
			bonus/src/parsing/parsing.c \
			bonus/src/parsing/player_utils.c \
			bonus/src/parsing/utils_door.c \
			bonus/src/parsing/utils.c \
			bonus/src/parsing/valid.c \
			bonus/src/parsing/validation.c \
			bonus/src/sound/sound.c \
			bonus/src/sprit/sprit.c \
			bonus/src/raycast/cast_ray.c \
			bonus/src/clear/clear_game.c \
			bonus/src/raycast/deg_to_rad.c \
			bonus/src/raycast/get_distance.c \
			bonus/src/raycast/get_pixel_color.c \
			bonus/src/raycast/get_rgba.c \
			bonus/src/movement/input.c\
			bonus/src/init_game/load_texture.c \
			bonus/src/movement/movement.c \
			bonus/src/raycast/normilize_angle.c \
			bonus/src/raycast/raycast.c \
			bonus/src/raycast/render.c \
			bonus/src/engine/update.c \
			bonus/src/engine/main.c \
 
  
 

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}


all: _libft $(NAME)


bonus:  _libft $(NAME_BONUS)

_libft:
	make -C ./libft

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBMLX) $(LIBFT) $(LDLIBS) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	cc $(FLAGS) $(OBJ_BONUS) $(LIBMLX) $(LIBFT) $(LDLIBS) -o $(NAME_BONUS)


mandatory/src/%.o: mandatory/src/%.c $(INCLUDE_MANDATORY) $(LIBFT)
	cc $(FLAGS) -o $@ -c $<

bonus/src/%.o: bonus/src/%.c $(INCLUDE_BONUS) $(LIBFT)
	cc $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJ_BONUS) 
	make fclean -C ./libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: clean all


