NAME = cub
LIBMLX = lib/libmlx42.a
LIBFT = lib/libft.a

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$ cc  $(OBJS) $(LIBMLX) $(LIBFT) -lglfw -framework Cocoa -framework OpenGL -framework IOKit  -o $(NAME)

%.o: %.c
	 cc  -o $@ -c $<  && printf "Compiling: $(notdir $<)"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all