#include "fillit.h"

char	**board(char **board, int *tab2, t_point *tab, char c)
{
	int	x;
	int	y;

	y = tab2[0];
	x = tab[1];
	// ft_putstr("D : je positionne \n"); // TEST TEST TEST
	board[y + tab[0].y][x + tab[0].x] = c;
	board[y + tab[1].y][x + tab[1].x] = c;
	board[y + tab[2].y][x + tab[2].x] = c;
	board[y + tab[3].y][x + tab[3].x] = c;;
	return (board);
}

char 	**eaf(t_tlist *tetri, char **board, int *tab2, int tab) 
{
	if ((tetri->next == NULL && ft_checkplacetetri(board, tetri)) ||
	   	(tetri->next != NULL && ft_checkplacetetri(board, tetri->next)))
		return (NULL);
	if (tetri->next != NULL && ft_checkplacetetri(board, tetri))
	{
		tab[0] = y = i / size;
		tab[1] = x = i % size;
		board = board(board, tab2, tab, '.');
	}
	return (board);
}



char	**ft_backtrack(t_tlist *tetri, char **board, int size)
{
	int 	i;
	int		x;
	int		y;
	t_point *tab;

	i = -1;
	tab = tetri->tab;
	while ((tetri != NULL) && ++i <= ((size * size) - 3))
	{
		while (i <= ((size * size) - 3))
		{
			tab[0] = y = i / size;
			tab[1] = x = i % size;
			if (ft_checkboard1(tab, x, y, size) == 1 &&
				ft_checkboard2(board, tab, x, y) == 1)
			{
				board = board(board, tab2, tab, tetri->name);
				if (tetri->next)
					board = ft_backtrack(tetri->next, board, size);
				break;
			}
			else
				i++;
		}
		tab[0] = y = i / size;
		tab[1] = x = i % size;
		if (!eaf(tetri, board, tab2, tab))
			break;
		else
			board = eaf(tetri, board, tabé, tab);
	}
	return (board);
}
