NAME = cub3D
LIBMLX = lib/libmlx42.a
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

SRCS	=	src/cast_ray.c \
			src/clear_game.c \
			src/deg_to_rad.c \
			src/get_distance.c \
			src/get_pixel_color.c \
			src/get_rgba.c \
			src/init_game.c \
			src/input.c \
			src/load_texture.c \
			src/main.c \
			src/movement.c \
			src/normilize_angle.c \
			src/raycast.c \
			src/render.c \
			src/update.c \
			src/parsing/destroy_game.c \
			src/parsing/handle_error.c \
			src/parsing/handle_error_utils.c \
			src/parsing/handle_map.c \
			src/parsing/init_map.c \
			src/parsing/parsing.c \
			src/parsing/parsing_map_config.c \
			src/parsing/parsing_rgba.c \
			src/parsing/player_utils.c \
			src/parsing/utils.c \
			src/parsing/valid.c \
			src/parsing/validation.c 


OBJS	:= ${SRCS:.c=.o}

all: _libft $(NAME)

_libft:
	make -C ./libft

$(NAME): $(OBJS)
	cc -c malloc.c -o malloc.o
	cc $(FLAGS) $(OBJS) $(LIBMLX) $(LIBFT) -lglfw -framework Cocoa -framework OpenGL -framework IOKit malloc.o -o $(NAME)

%.o: %.c include/cub.h include/parsing.h libft/libft.h $(LIBFT)
	cc $(FLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJS)
	make fclean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: clean all