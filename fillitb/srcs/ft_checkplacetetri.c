/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkplacetetri.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:28:50 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/06 17:30:46 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkboard1(t_point *tab, int x, int y, int size)
{
	if ((y + tab[0].y) < size && (x + tab[0].x) < size &&
			(y + tab[1].y) < size && (x + tab[1].x) < size &&
			(y + tab[2].y) < size && (x + tab[2].x) < size &&
			(y + tab[3].y) < size && (x + tab[3].x) < size)
		return (1);
	else
		return (0);
}

int		ft_checkboard2(char **board, t_point *tab, int x, int y)
{
	if (board[y + tab[0].y][x + tab[0].x] == '.' &&
			board[y + tab[1].y][x + tab[1].x] == '.' &&
			board[y + tab[2].y][x + tab[2].x] == '.' &&
			board[y + tab[3].y][x + tab[3].x] == '.')
		return (1);
	else
		return (0);
}

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
