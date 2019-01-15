/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:19:42 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/15 12:15:33 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sizesquare(int n)
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

