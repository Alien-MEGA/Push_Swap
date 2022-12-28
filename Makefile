# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:23:50 by reben-ha          #+#    #+#              #
#    Updated: 2022/12/28 16:42:44 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = ft_linked_list.c ft_atoi.c ft_push_swap.c rule_psr.c

OBJ = ft_linked_list.o ft_atoi.o ft_push_swap.o rule_psr.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
bonus : $(BOBJ)
	ar -rc $(NAME) $(BOBJ)
%.o : %.c push_swap.h
	cc -Wall -Wextra -Werror -c $< -o $@
clean :
	rm -f $(OBJ)
	rm -f $(BOBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all

test :
	make
	make clean
	gcc push_swap.a -o push_swap
	rm -f push_swap.a
	./push_swap 11 22 33 44 55 66 77 88
.PHONY = all bonus clean fclean re test