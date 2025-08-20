NAME = cub3d


SOURC = \
		parsing/handle_map.c parsing/parsing.c \
		parsing/validation.c parsing/init_map.c \
		parsing/handle_error.c parsing/destroy_game.c \
		src/raycast/cast_ray.c src/raycast/get_distance.c  src/raycast/raycast.c \
		src/shapes/circle.c src/shapes/line.c src/shapes/map.c src/shapes/put_pixel.c src/shapes/rect.c \
		src/close.c src/init_game.c src/input.c src/main.c src/player.c src/update.c 
		

OBJ = $(SOURC:%.c=%.o)
LIBFT_PATH = libft/libft.a

CC = cc
CFLAGS =# -Wall -Wextra -Werror -fsanitize=address
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all: sub_program $(NAME)

$(NAME): $(OBJ) $(LIBFT_PATH)
	$(CC) $(CFLAGS)  $(OBJ) $(LIBFT_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


	
$%.o: $%.c header.h
	@echo $(CYAN) " - Compiling $@" $(GREEN)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo $(PURPLE) "[OK COMPILED]" $(EOC)


sub_program:
	make -C libft/ all
clean:
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
	@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
nor:
	norminette *

.PHONY: all clean fclean re bonus sub_program nor