CFLAGS = -fsanitize=address -g3 #-Wall -Wextra -Werror
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:%.c=%.o)
NAME= cube3d

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c include/cube.h
	cc $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all



