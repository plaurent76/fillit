/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:39:54 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:23 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 100

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct 	s_tlist
{
	t_point			*tab;
	char			name;
	struct s_tlist	*next;
}				t_tlist;

int			get_next_line(const int fd, char **line);
int			ft_checknb(char *str);
int			ft_checktetri(char *str);
int			ft_checkplace(char *str, int i);

#endif
