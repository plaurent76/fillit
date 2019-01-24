/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvetab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:32:34 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/24 13:37:24 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"




/* pose doit poser le tetri donner a lemplacement indiquer. */

int		pose(int *str, int **map, int i, int j)
{
	int		n;

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


/* remplissage doit poser des qu'il peut le str[tab[k]] tetri en gardant la
 * position où il a poser dans str[nt] et str[nt + 1] pour aller plus vite*/

int		*remplissage(int **map, int t, char **str, int *tab, int k)
{
	int		n;

	k = k + 1;
	n = 0;
	while (str[n] != '\0')
		n++;
	n = n - 1;
	while (pose(str[tab[k]], map, (str[n][0] - 48), (str[n][1] - 48)) != 1)
	{
		if (str[n][0] == (t + 47) && str[n][1] == (t + 44))
			return (2)
		else if (str[n][1] == (t + 47) && str[n][0] != (t + 47))
		{
			str[n][0] += 1;
			str[n][1] = 0;
		}
		else if (str[n][1] != (t - 1))
			str[n][1] += 1;
	}
	return (1)
}


/* place recois tab avec un ordre qu'il doit tester, il créé une map pour le
 * tester, apl de la fonction remplissage en recusive, si le remplissage echoue
 * apl de maj tab et fin de la fonction pour recommancer avec un nouveau tab*/

int		*place(char **str, int t, char *tab, int k)
{
	int		i;
	int		**map;

	i = 0;
	if (k = -1)
	{
		if (!(map = (int **)malloc(sizeof(int *) * t + 4)))
			return (0);
		while (i < (t + 4))
			if (!(map[i++] = (int *)malloc(sizeof(int * (t + 4)))))
				return (0);
	}
	//remplissage(map, t, str, tab, &k);
	if (remplissage(map, t, str, tab, &k) == 2)
	{
		majtab(tab, k);
		free(map);
		return (tab);
	}
	else
		return (place(map, t, str, tab, k))
}


/* apl la fonction place qui modifie tab, puis verifie si tab a ete remplie
 * completement qui voudrais dire qu'on a trouver sinon on change l ordre jusqu
 * 'a ce qu'on est tout tester et ca de facon recursive en relancant avec un
 * tab dans place */

char	backt(char **str, int t, int nt, char *tab)
{
	int		i;
	int		j;
	int		k;

	// ne pas oublier d'utiliser k.
	// k = -1
	i = 0;
	j = nt - 1;
	place(str, t, tab, &k);
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


/* reception des tetri, nb de tetri et taille mini square, creation du tableau
 * recevant l'ordre de placement des tetris. recursive qui ce fait pour
 * augmenter de 1 le carré final quand necessaire */

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
