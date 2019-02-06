/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:39:54 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/06 18:20:30 by plaurent         ###   ########.fr       */
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

t_point		*ft_move(t_point *tab, char *str, int initx);
int			*coord(int i, int size);
char		**pose(char **board, int *tab2, t_point *tab, char c);
void		ft_dellist(t_tlist **alst);
char		**ft_tetriplace(t_tlist *tetrilist, int tetrinb);
char		**ft_createboard(int size);
int			ft_nearsqrt(int nb);
char		**ft_backtrack(t_tlist *tetri, char **board, int size, int i);
int			ft_checkplacetetri(char **board, t_tlist *tetri);
int			ft_checkboard2(char **board, t_point *tab, int x, int y);
int			ft_checkboard1(t_point *tab, int x, int y, int size);
void		ft_printboard(char **board);
t_tlist		*ft_createtri(t_point *tab, int tetrinb);
t_point		*ft_IDtetri(char *str);
int			ft_check(char *str, int n);
t_tlist		*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb);
int			get_next_line(const int fd, char **line);
int			ft_checknb(char *str);
int			ft_checktetri(char *str);
int			ft_checkplace(char *str, int i);

#endif
