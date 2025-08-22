NAME = cub3d


SOURC = \
		mandatory/parsing/handle_map.c mandatory/parsing/parsing.c \
		mandatory/parsing/validation.c mandatory/parsing/init_map.c \
		mandatory/parsing/handle_error.c mandatory/parsing/destroy_game.c \
		mandatory/src/raycast/cast_ray.c mandatory/src/raycast/get_distance.c  mandatory/src/raycast/raycast.c \
		mandatory/src/shapes/circle.c mandatory/src/shapes/line.c mandatory/src/shapes/map.c mandatory/src/shapes/put_pixel.c mandatory/src/shapes/rect.c \
		mandatory/src/close.c mandatory/src/init_game.c mandatory/src/input.c mandatory/src/main.c mandatory/src/player.c mandatory/src/update.c \
		

OBJ = $(SOURC:%.c=%.o)
LIBFT_PATH = mandatory/libft/libft.a

CC = cc
CFLAGS =-g3 -fsanitize=address
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
	make -C mandatory/libft/ all
clean:
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	rm -f $(OBJ)
	$(MAKE) clean -C mandatory/libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
	@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
nor:
	norminette *

.PHONY: all clean fclean re bonus sub_program nor