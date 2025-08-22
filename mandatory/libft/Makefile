# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:45:45 by ybassour          #+#    #+#              #
#    Updated: 2025/08/20 10:15:02 by ybassour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	 ft_putchar_fd.c \
					 ft_strncmp.c  \
					 ft_atoi.c \
					ft_inttoa.c   \
					ft_putendl_fd.c  \
					ft_strlcpy.c \
					ft_bzero.c   \
					ft_strdup.c  \
					ft_strlen.c \
					ft_calloc.c  \
					ft_isdigit.c  \
					ft_memset.c  \
					ft_putstr_fd.c  \
					get_next_line.c \
					get_next_line_utils.c \
					ft_inttoa.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME):		$(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	clean 



