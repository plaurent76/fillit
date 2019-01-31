/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:24:17 by eviana            #+#    #+#             */
/*   Updated: 2019/01/31 19:07:54 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *str, int n)
{
	if (n == 1 && str[0] != '\0')
	{
		ft_putstr("error\n");
		return (0);
	}
	if (n == 2)
	{
		if (ft_checknb(str) == 2)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (ft_checktetri(str) == 2)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	return (1);
}

// Conversion str to tab(x;y)
t_point		*ft_IDtetri(char *str)
{	
	t_point	*tab;
	int		i;
	int		j;
	int		inity;
	int		initx;

	i = 0;
	j = 0;
	if (!(tab = (t_point*)malloc(sizeof(t_point) * 5)))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			tab[j].x = i % 4;
			tab[j].y = i / 4;
			if (j == 0)
			{
				initx = tab[0].x;
				inity = tab[0].y;
			}
			tab[j].x = tab[j].x - initx;
			tab[j].y = tab[j].y - inity;
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 4)
	{
		j++;
		if (tab[j].x < 0)
		{
			initx = tab[j].x;
			j = 0;
			while (j < 4)
			{
				tab[j].x = tab[j].x - initx;
				j++;
			}
		}
	}
	return (tab);
}

// Creation du tetri via tab(x;y) et son numero
t_tlist	*ft_createtetri(t_point *tab, int tetrinb)
{
	t_tlist *tetri;
	
	if (!(tetri = (t_tlist*)malloc(sizeof(t_tlist))))
		return (NULL);
	if (tab)
	{
		if (!(tetri->tab = (void*)malloc(sizeof(t_point) * (5))))
		{
			free(tetri);
			return (NULL);
		}
		ft_memcpy(tetri->tab, tab, (sizeof(t_point) * 5)); // ??? sizeof ???
		tetri->name = (char)tetrinb + 'A';
	}
	else // usefull ?
	{
		tetri->tab = NULL;
		tetri->name = 0;
	}
	tetri->next = NULL;
	// FREE QQUCHOSE ?
	return (tetri);
}

t_tlist		*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb)
{
	t_tlist	*tetri;
	t_tlist	*templist; // free ?
	t_point	*tab; 

	tab = ft_IDtetri(str);
	tetri = ft_createtetri(tab, tetrinb);
	free(tab);
	tab = NULL;
	
	// Maillage du nouveau maillon a la fin de la chaine
	if (tetrilist == NULL)
		return (tetri);
	else
	{
		templist = tetrilist; // NEED TEMP ? // FREE TEMP SOMEWHERE ?
		while (templist->next != NULL)
			templist = templist->next;
		templist->next = tetri;
		return (tetrilist);
	}
}

void	ft_printboard(char **board)
{
	int i;
	int j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}

// check si on ne depasse pas du board et qu'aucune piece n'occupe l'espace
int		ft_checkboard1(t_point *tab, int x, int y, int size)
{
	if ((y + tab[0].y) < size && (x + tab[0].x) < size &&
		(y + tab[1].y) < size && (x + tab[1].x) < size &&
		(y + tab[2].y) < size && (x + tab[2].x) < size &&
		(y + tab[3].y) < size && (x + tab[3].x) < size)
	{
		// ft_putstr("B : piece fit le board\n"); // TEST TEST TEST
		return (1);
	}
	else
		return (0);
}

// check que la place est libre sur le board
int		ft_checkboard2(char **board, t_point *tab, int x, int y)
{
	if (board[y + tab[0].y][x + tab[0].x] == '.' &&
			board[y + tab[1].y][x + tab[1].x] == '.' &&
			board[y + tab[2].y][x + tab[2].x] == '.' &&
			board[y + tab[3].y][x + tab[3].x] == '.')
	{	
		// ft_putstr("C : la place est libre\n"); // TEST TEST TEST
		return (1);
	}
	else
		return (0);
}

// check qu'on a jamais place la piece a cet endroit du board
//int		ft_checkboard3(char ***board, )

int		ft_checkplacetetri(char **board, t_tlist *tetri)
{
	int i;
	int j;
	
	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == tetri->name)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// essai backtracking
char	**ft_backtrack(t_tlist *tetri, char **board, int size)
{
	int 	i;
	int		x;
	int		y;
	t_point *tab;

	i = 0;
	tab = tetri->tab;
	while ((tetri != NULL) && i <= ((size * size) - 3))
	{
		while (i <= ((size * size) - 3))
		{
			// ft_putstr("A : je tente de positionner\n"); // TEST TEST TEST
			y = i / size;
			x = i % size;
			if (ft_checkboard1(tab, x, y, size) == 1 &&
					ft_checkboard2(board, tab, x, y) == 1)
			{
				// ft_putstr("D : je positionne \n"); // TEST TEST TEST
				board[y + tab[0].y][x + tab[0].x] = tetri->name;
				board[y + tab[1].y][x + tab[1].x] = tetri->name;
				board[y + tab[2].y][x + tab[2].x] = tetri->name;
				board[y + tab[3].y][x + tab[3].x] = tetri->name;
				// ft_printboard(board); // TEST TEST TEST
				if (tetri->next)
					board = ft_backtrack(tetri->next, board, size);
				// ft_putstr("je ressors du backtracking\n"); // TEST TEST TEST
				break;
			}
			else
				i++;
		}
		if ((tetri->next == NULL && ft_checkplacetetri(board, tetri)) ||
				   	(tetri->next != NULL && ft_checkplacetetri(board, tetri->next)))
				break;
		if (tetri->next != NULL && ft_checkplacetetri(board, tetri)) 
		{	
			// ft_putstr("je clean\n"); // TEST TEST TEST
			y = i / size;
			x = i % size;
			board[y + tab[0].y][x + tab[0].x] = '.';
			board[y + tab[1].y][x + tab[1].x] = '.';
			board[y + tab[2].y][x + tab[2].x] = '.';
			board[y + tab[3].y][x + tab[3].x] = '.';
			// ft_putstr("c'est clean\n"); // TEST TEST TEST
			// ft_printboard(board); // TEST TEST TEST
		}
		i++;
	}
	return (board);
}

int		ft_nearsqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i < nb && i <= 46340)
		i++;
	return (i);
}

char	**ft_createboard(int size)
{
	char	**board;
	int 	x;
	int		y;

	y = 0;
	if (!(board = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(board[y] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (x < size)
		{
			board[y][x] = '.';
			x++;
		}
		board[y][x] = '\0';
		y++;
	}
	board[y] = NULL;
	return (board);
}

// essai backtracking
char	**ft_tetriplace(t_tlist *tetrilist, int	tetrinb)
{
	char 	**board;
	int		size;
	int		i;

	size = ft_nearsqrt(tetrinb * 4);
	board = ft_createboard(size);
	board = ft_backtrack(tetrilist, board, size);
	while (!ft_checkplacetetri(board, tetrilist))
	{
		i = 0;
		while (i < (size + 1))
		{
			free(board[i]);
			i++;
		}
		free(board);
		size++;
		board = ft_createboard(size);
		board = ft_backtrack(tetrilist, board, size);
	}
	return (board);
}

/*
// Impression pour verif
void	ft_print(t_tlist *tetrilist)
{
	t_point	*tab;
	int		i;
	int		x;
	int		y;
	
	while (tetrilist)
	{
		tab = tetrilist->tab;
		i = 0;
		while (i < 4) // here was the scotch
		{
			y = 0;
			while (y < 4)
			{
				x = 0;
				while (x < 4)
				{
					if (x == tab[i].x && y == tab[i].y)
					{
						ft_putchar(tetrilist->name);
						i++;
					}
					else
						ft_putchar('.');
					x++;
				}
				ft_putchar('\n');
				y++;
			}
		}
		ft_putchar('\n');
		tetrilist = tetrilist->next;
	}
	// free(tab); // ADD FREE
	// free(tetrilist); // ADD FREE
}
*/

void	ft_dellist(t_tlist **alst)
{
	t_tlist *temp;

	if (alst)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			//ft_lstdelone(alst, del);
			free((*alst)->tab);
			free(*alst);
			*alst = temp;
		}
	}
}

int		main(int argc, char **argv)
{
	int		fd;	
	char	*line;
	char	*str;
	t_tlist	*tetrilist;
	int		linenb;
	int		tetrinb;

	linenb = 1;
	tetrinb = 0;
	tetrilist = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: only one argument needed");
		return (0);
	}
	if	((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(str = ft_strnew(16)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strcat(str, line);
		if (linenb == 0 && ft_check(str, 1) == 0)
		{
			free(str);
			free(line);
			return (0);
		}
		free(line); // a verifier
		if (linenb == 4) // corriger pb quand + de 12 points
		{
			linenb = 0;
			if (ft_check(str, 2) == 0)
			{
				free(str);
				return (0);
			}
			if (!(tetrilist = ft_newtetri(tetrilist, str, tetrinb)))
			{
				free(str);
				return (0);
			}
			bzero(str, 16);
			tetrinb++;
		}
		else
			linenb++;
	}
	free(line);
	if (linenb != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	// ft_print(tetrilist); // TEST TEST TEST
	ft_printboard(ft_tetriplace(tetrilist, tetrinb));
	ft_dellist(&tetrilist);
	free(str); // ADD FREE
	return (0);
}
