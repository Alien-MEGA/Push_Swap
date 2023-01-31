# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:23:50 by reben-ha          #+#    #+#              #
#    Updated: 2023/01/24 21:21:11 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

SRC = push_swap_mand.c \
		rule_psr_mand.c \
		short_rule_psr_mand.c

OBJ = push_swap_mand.o \
		rule_psr_mand.o \
		short_rule_psr_mand.o

BSRC = checker_bonus.c rule_psr_bonus.c

BOBJ = checker_bonus.o rule_psr_bonus.o

LIB = ./libft/libft.a

MANDUTILS = ./mandatory_utils/part_one_mand.c ./mandatory_utils/part_two_mand.c \
			./mandatory_utils/part_three_mand.c ./mandatory_utils/part_four_mand.c \
			./mandatory_utils/part_five_mand.c ./mandatory_utils/part_six_mand.c

MANDUTILSOBG = ./mandatory_utils/part_one_mand.o ./mandatory_utils/part_two_mand.o \
			./mandatory_utils/part_three_mand.o ./mandatory_utils/part_four_mand.o \
			./mandatory_utils/part_five_mand.o ./mandatory_utils/part_six_mand.o

BONUTILS = ./bonus_utils/part_one_bonus.c ./bonus_utils/part_two_bonus.c

BONUTILSOBG = ./bonus_utils/part_one_bonus.o ./bonus_utils/part_two_bonus.o

all : $(NAME)

$(NAME) : $(OBJ) $(LIB) $(MANDUTILSOBG)
	cc $(OBJ) $(LIB) $(MANDUTILSOBG) -o $(NAME)

%_mand.o : %_mand.c push_swap.h
	cc -Wall -Wextra -Werror -c $< -o $@

./mandatory_utils/%_mand.o : ./mandatory_utils/%_mand.c push_swap.h
	cc -Wall -Wextra -Werror -c $< -o $@

$(LIB) : 
	make -C ./libft

bonus : $(BOBJ) $(LIB) $(BONUTILSOBG)
	cc $(BOBJ) $(LIB) $(BONUTILSOBG) -o $(BNAME)

%_bonus.o : %_bonus.c checker_bonus.h
	cc -Wall -Wextra -Werror -c $< -o $@

./bonus_utils/%_bonus.o : ./bonus_utils/%_bonus.c checker_bonus.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJ) $(MANDUTILSOBG)
	rm -f $(BOBJ) $(BONUTILSOBG)
	make fclean -C ./libft
fclean : clean
	rm -f $(NAME)
	rm -f $(BNAME)
re : fclean all

.PHONY = all bonus clean fclean re