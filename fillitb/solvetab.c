/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvetab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:32:34 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/23 18:24:37 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pose(int *str, int **map, int i, int j, int k)
{
	int		n;
	//int		m;
	//int		l;

	//m = i;
	//l = j;
	n = -1;
	while (str[++n] != '\0')
	{
		if (str[n] == '#')
		{
			if (map[i + (n / 4)][j + (n % 4)] != '#' && i + (n / 4) < t &&
					j + (n % 4) < t)
				map[i + (n / 4)][j + (n % 4)] == '#';
			else
				return (0);
		}
	}
	return (1);
}

int		*remplissage(int **map, int t, char **str, int *tab, int k)
{
	int		i;
	int		j;
	int		n;

	n = -1;
	i = 0;
	j = 0;
	while (str[tab[++n]] != '\0' && k = 1)
	{
		k = 0;
		if (i == t)
		{
			k = n - 1;
			return (tab);
		}
		while (i < t && k == 0)
		{
			if (j = t)
				j = 0;
			while (j < t && k == 0)
			{
				if (pose(str[n], &map, i, j, 0))
					k = 1;
				else // else car sinon quand la piece est pas en coller haut gauche ca pose prblm
					j++;
			}
			i++;
		}
	}
}

int		*place(char **str, int t, char *tab, int k)
{
	int		i;
	int		**map;

	i = 0;
	if (!(map = (int **)malloc(sizeof(int *) * t + 4)))
		return (0);
	while (i < (t + 4))
		if (!(map[i++] = (int *)malloc(sizeof(int * (t + 4)))))
			return (0);
	tab = remplissage(map, t, str, tab, &k);
	free(map);
	return (tab);
}

char	backt(char **str, int t, int nt, char *tab)
{
	int		i;
	int		j;
	int		k;

	// ne pas oublier d'utiliser k.
	// k = -1
	i = 0;
	j = nt;
	tab = place(str, t, tab, &k);
	i = 0;
	while (i != j)
	{
		if (tab[j] == '\0')
			j--;
								//check va regarder si il y un tetri plus grand apres.
		else if (tab[j] < nt && check(tab, j) == 1)
		{
			tab[j]++;
			j = 0;
		}
		else
		{
			tab[j] = '\0';
			tab[j - 1]++;
			j = 0;
		}
	}
	return (backt(str, t, nt, tab));
}


char	**main(char **str, int nt, int t)
{
	int		i;
	int		j;
	char	*tab;

	i = -1;
	tab = malloc(sizeof(char) * (nt + 1));
	while (++i < nt)
		tab[i] = i;
	tab = backt(str, t, nt, tab);
	if (tab[nt] != '\0')
		return (main(str, nt, t + 1));
	else
		
}
