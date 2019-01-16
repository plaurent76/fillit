/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:39:54 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:15 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point

typedef struct 	s_list
{
	t_point			*tab;
	char			name;
	struct s_list	*next;
}				t_list

int			ft_putnbr(int i);
int			get_next_line(const int fd, char **line);
void		ft_putendl(char const *s);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strnew(size_t s);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(char *str);
void		ft_putchar(char c);
void		ft_putstr(char const *str);
char		*ft_strcat2(char *dest, const char *src);
int			ft_checknb(char *str);
int			ft_checktetri(char *str);
int			ft_checkplace(char *str, int i);
#endif
