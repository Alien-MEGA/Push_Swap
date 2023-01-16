/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:42 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/16 13:58:32 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long			data;
	int				index;
	int				lis;
	int				sub_index;
	int				h_lis;
	int				instr_s;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(long data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **lst, int option);
int		ft_lstsize(t_list *lst);
long	ft_atoi(const char *str);

void	p_ab(t_list **head_of_a, t_list **head_of_b, int option);
void	ss_ab(t_list *head_of_a, t_list *head_of_b, int option);
void	rr_ab(t_list **head_of_a, t_list **head_of_b, int option);
void	rrr_ab(t_list **head_of_a, t_list **head_of_b, int option);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);

#endif