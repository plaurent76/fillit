/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:19:42 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/16 16:02:45 by plaurent         ###   ########.fr       */
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

char	*place(char *tab, int k)
{
	char	x;
	if (k < 6)
	{
		x = tab[k];
		tab[k] = tab[k + 1];
		tab[k + 1] = x;
	}
	if (k == 6)
	{
		x = tab[k];
		tab[5]
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
			place(tab, k++);
		else
		{
			if (n == 0)
			{
				place(tab, 6);
			}
			n++
			k = 0;
			ft_putchar('\n');
		}
	}
}















