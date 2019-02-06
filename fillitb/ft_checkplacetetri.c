#include "fillit.h"

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
