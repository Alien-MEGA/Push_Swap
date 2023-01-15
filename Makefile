# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:23:50 by reben-ha          #+#    #+#              #
#    Updated: 2023/01/15 22:12:04 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = ft_linked_list.c ft_atoi.c ft_push_swap.c rule_psr.c \
		ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c \
		ft_isdigit.c

OBJ = ft_linked_list.o ft_atoi.o ft_push_swap.o rule_psr.o \
		ft_split.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_substr.o \
		ft_isdigit.o

all : $(NAME)
	@gcc push_swap.a -o push_swap

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)
bonus : $(BOBJ)
	@ar -rc $(NAME) $(BOBJ)
%.o : %.c push_swap.h #-Wall -Wextra -Werror
	@cc -Wall -Wextra -Werror -c $< -o $@
clean :
	@rm -f $(OBJ)
	@rm -f $(BOBJ)
fclean : clean
	@rm -f $(NAME)
re : fclean all

app : re
	@make clean
	@gcc push_swap.a -o push_swap
	@rm -f push_swap.a
run : app
	@./push_swap 3 9 6 5 7 4 1 8 2
test100 : app
	@./push_swap 194 197 16 140 40 159 67 174 54 154 89 173 62 31 13 131 145 41 134 53 144 179 97 171 108 75 5 50 60 101 148 165 70 169 132 77 141 195 128 78 192 183 147 56 127 166 191 42 200 51 74 18 130 160 139 52 32 87 20 113 11 27 190 7 156 91 180 21 155 149 143 138 181 33 29 187 117 109 80 88 158 106 126 15 136 170 36 90 34 6 115 129 164 185 55 98 135 125 3 76 | ./checker_Mac 194 197 16 140 40 159 67 174 54 154 89 173 62 31 13 131 145 41 134 53 144 179 97 171 108 75 5 50 60 101 148 165 70 169 132 77 141 195 128 78 192 183 147 56 127 166 191 42 200 51 74 18 130 160 139 52 32 87 20 113 11 27 190 7 156 91 180 21 155 149 143 138 181 33 29 187 117 109 80 88 158 106 126 15 136 170 36 90 34 6 115 129 164 185 55 98 135 125 3 76
	@./push_swap 194 197 16 140 40 159 67 174 54 154 89 173 62 31 13 131 145 41 134 53 144 179 97 171 108 75 5 50 60 101 148 165 70 169 132 77 141 195 128 78 192 183 147 56 127 166 191 42 200 51 74 18 130 160 139 52 32 87 20 113 11 27 190 7 156 91 180 21 155 149 143 138 181 33 29 187 117 109 80 88 158 106 126 15 136 170 36 90 34 6 115 129 164 185 55 98 135 125 3 76 | wc -l
gitpush : 
	git add .
	git commit -m "Push-Swap"
	git push
.PHONY = all bonus clean fclean re