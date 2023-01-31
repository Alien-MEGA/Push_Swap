# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/01/21 20:39:55 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_lstadd_back.c ft_lstnew.c ft_strdup.c ft_strncmp.c get_next_line_utils.c \
		ft_atoi.c ft_lstadd_front.c ft_lstsize.c ft_strjoin.c ft_substr.c ft_isdigit.c \
		ft_lstlast.c ft_split.c ft_strlen.c get_next_line.c ft_lstclear.c
OBJ = ft_lstadd_back.o ft_lstnew.o ft_strdup.o ft_strncmp.o get_next_line_utils.o \
		ft_atoi.o ft_lstadd_front.o ft_lstsize.o ft_strjoin.o ft_substr.o ft_isdigit.o \
		ft_lstlast.o ft_split.o ft_strlen.o get_next_line.o ft_lstclear.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
%.o : %.c libft.h
	cc -Wall -Wextra -Werror -c $< -o $@
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY = all bonus clean fclean re