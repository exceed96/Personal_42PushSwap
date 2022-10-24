# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 20:03:54 by sangyeki          #+#    #+#              #
#    Updated: 2022/06/16 19:03:11 by sangyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c\
		  utils.c\
		  sort.c\
		  sort_utils_c3.c\
		  sort_over3.c\
		  sort_over3_utils.c\
		  operation.c\

SOURCES_B = checker.c\
		   	operation.c\
		  	get_next_line.c\
			utils.c\
			sort.c\
			sort_utils_c3.c\
			sort_over3.c\
			sort_over3_utils.c\
			checker_utils.c\

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

NAME = push_swap

all: $(NAME)

bonus : push_swap checker

$(NAME) : $(OBJECTS) libft
	$(CC) -o $@ $(OBJECTS) -Llibft -lft

checker : $(OBJECTS_B) libft
	$(CC) -o $@ $(OBJECTS_B) -Llibft -lft

%.o : %.c
	$(CC) -c $(CFLAGS) $?

libft :
	make -C libft bonus

clean :
	rm -f $(OBJECTS) $(OBJECTS_B)
	make -C libft clean

fclean : clean
	rm -f push_swap checker libft/libft.a

re : fclean all

.PHONY: all clean bonus fclean libft re
