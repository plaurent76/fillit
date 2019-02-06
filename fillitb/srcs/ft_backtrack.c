/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:21:28 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/06 18:19:37 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		condition1(t_point *tab, int i, int size, char **board)
{
	if (ft_checkboard1(tab, i % size, i / size, size) == 1 &&
			ft_checkboard2(board, tab, i % size, i / size) == 1)
		return (1);
	return (0);

}

int		condition2(t_tlist *tetri, char **board)
{
	if ((tetri->next == NULL && ft_checkplacetetri(board, tetri)) ||
			(tetri->next != NULL && ft_checkplacetetri(board, tetri->next)))
		return (1);
	return (0);
}

char    **pose(char **board, int *tab2, t_point *tab, char c)
{
	int        x;
	int        y;

	y = tab2[0];
	x = tab2[1];
	board[y + tab[0].y][x + tab[0].x] = c;
	board[y + tab[1].y][x + tab[1].x] = c;
	board[y + tab[2].y][x + tab[2].x] = c;
	board[y + tab[3].y][x + tab[3].x] = c;
	return (board);
}

int        *coord(int i, int size)
{
	int        *tab2;

	tab2 = malloc(sizeof(int) * 2);
	tab2[0] = i / size;//y
	tab2[1] = i % size;//x
	return (tab2);
}

char	**ft_backtrack(t_tlist *tetri, char **board, int size, int i)
{
	t_point *tab;

	tab = tetri->tab;
	while ((tetri != NULL) && i <= ((size * size) - 3))
	{
		while (i <= ((size * size) - 3))
		{
			if (condition1(tab, i, size, board))
			{
				board = pose(board, coord(i, size), tab, tetri->name);
				if (tetri->next)
					board = ft_backtrack(tetri->next, board, size, 0);
				break;
			}
			else
				i++;
		}
		if (condition2(tetri, board))
			break;
		if (tetri->next != NULL && ft_checkplacetetri(board, tetri))
			board = pose(board, coord(i, size), tab, '.');
		i++;
	}
	return (board);
}
