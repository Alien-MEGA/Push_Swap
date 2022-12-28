# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:23:50 by reben-ha          #+#    #+#              #
#    Updated: 2022/12/22 16:23:52 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

SRC = 

OBJ = 

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
bonus : $(BOBJ)
	ar -rc $(NAME) $(BOBJ)
%.o : %.c #library.h
	cc -Wall -Wextra -Werror -c $< -o $@
clean :
	rm -f $(OBJ)
	rm -f $(BOBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
just : re
	make clean
.PHONY = all bonus clean fclean re just