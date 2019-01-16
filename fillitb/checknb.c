/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:05:29 by eviana            #+#    #+#             */
/*   Updated: 2019/01/16 13:45:50 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_checknb(char	*str)
{
	int	i;
	int	nb;
	int	k;

	i = 0;
	nb = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			nb++;
		if (str[i] == '.' || str[i] == '#')
			k++;
		i++;
	}
	if (nb == 4 && k == 16 && i == 16)
		return (1);//bon
	return (2);//mauvais
}

int	ft_checktetri(char *str)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
			n = n + ft_checkplace(str, i);//n = nb de fois que chaque piece se touche
	}
	if (n < 6)
		return (2);//mauvais
	return (1);//bon
}

int	ft_checkplace(char *str, int i)
{
	int	j;

	j = 0;
	if (i > 3)//si on est pas dans la ligne du haut on peut regarder en haut
		if (str[i - 4] == '#')
			j++;
	if (i != 3 && i != 7 && i != 11 && i != 15)//si on estpas dans la ligne de droite on peut regarder a droite
		if (str[i + 1] == '#')
			j++;
	if (i < 12)//si pas en bas
		if (str[i + 4] == '#')
			j++;
	if (i != 0 && i != 4 && i != 8 && i != 12)//si pas a gauche
		if (str[i - 1] == '#')
			j++;
	return (j);
}








