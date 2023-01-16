# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-hastudent.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:23:50 by reben-ha          #+#    #+#              #
#    Updated: 2023/01/16 18:41:13 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker


SRC = ft_push_swap.c rule_psr.c \
		./libft/ft_atoi.c ./libft/ft_isdigit.c \
		./libft/ft_split.c ./libft/ft_strdup.c ./libft/ft_strjoin.c \
		./libft/ft_strlen.c ./libft/ft_substr.c ./libft/ft_strncmp.c \
		./libft/get_next_line.c ./libft/get_next_line_utils.c \
		./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c \
		./libft/ft_lstlast.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c
OBJ = ft_push_swap.o rule_psr.o \
		./libft/ft_atoi.o ./libft/ft_isdigit.o \
		./libft/ft_split.o ./libft/ft_strdup.o ./libft/ft_strjoin.o \
		./libft/ft_strlen.o ./libft/ft_substr.o ./libft/ft_strncmp.o \
		./libft/get_next_line.o ./libft/get_next_line_utils.o \
		./libft/ft_lstadd_back.o ./libft/ft_lstadd_front.o \
		./libft/ft_lstlast.o ./libft/ft_lstnew.o ./libft/ft_lstsize.o

all : $(NAME)

$(NAME) : $(OBJ) 
	cc $(OBJ) -o $(NAME)
%.o : %.c push_swap.h #-Wall -Wextra -Werror
	cc -Wall -Wextra -Werror -c $< -o $@
clean :
	rm -f $(OBJ)
	rm -f $(BOBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
