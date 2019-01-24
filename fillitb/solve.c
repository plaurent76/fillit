/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:19:42 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/22 13:26:16 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*int		sizesquare(int n)
{
	n = n * 4;
	while (n % 4 != 0)
		n++;
	return (n / 4);
}



char	**solve(char **tab, char **str, int t)
{
	
}

void	mainsolve(char **str, int nt)
{
	int		t;
	int		i;
	char	**tab;

	i = -1;
	t = sizesquare(nt);
	tab = (char **)malloc(sizeof(char *) * (t + 1));
	while (++i < t)
		tab[i] = (char *)malloc(sizeof(char) * (t + 1));
	tab = solve(tab, str, t);
*/

char	*place(char *tab, int k, int n)
{
	char	x;

	if (k < 6)
	{
		x = tab[k + n];
		tab[k] = tab[k + 1 + n];
		tab[k + 1 + n] = x;
	}
	if (k == (6 - n))
	{
		x = tab[0];
		tab[0] = tab[5];
		tab[5] = x;
	}
	return (tab);
}

int		main()
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	tab[7] = {'A', 'B', 'C', 'D', 'E', 'F'};

	j = 0;
	k = 0;
	n = 0;
	while (j++ < 721)
	{
		i = -1;
		while (tab[++i] != '\0')
			ft_putchar(tab[i]);
		if (k < (5 - n))
			place(tab, k++, n);
		else
		{
			if (n == 0)
			{
				place(tab, 6, n);
			}
			if (n >= 6 - n)
				n = 0;
			k = 0;
			ft_putchar('\n');
		}
	}
}















