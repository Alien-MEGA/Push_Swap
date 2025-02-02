/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:42 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/21 20:39:18 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

void	p_ab(t_list **head_of_a, t_list **head_of_b);
void	ss_ab(t_list *head_of_a, t_list *head_of_b, int option);
void	rr_ab(t_list **head_of_a, t_list **head_of_b, int option);
void	rrr_ab(t_list **head_of_a, t_list **head_of_b, int option);

long	ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_isdigit(int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int c, int option);
int		ft_strchr_cheack_gnl(const char *str, int c);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);

t_list	*in(t_list *head, int index);
int		ft_check_sort(t_list **stack_a);
void	ft_indexing(t_list *stack_a);
void	ft_error(int option);
void	ft_input_manage(int argc, char **argv, t_list **stack_a, int i);
void	ft_check_error(t_list *stack_a);
void	ft_apply_rules(t_list **stack_a, t_list **stack_b, char *full_str);

#endif