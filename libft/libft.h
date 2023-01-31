/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:34:12 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/21 20:38:59 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

t_list	*ft_lstnew(long data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **lst, int option);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int c, int option);
int		ft_strchr_cheack_gnl(const char *str, int c);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif