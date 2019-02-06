/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_IDtetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:06:39 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/06 11:32:00 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*ft_move(t_point *tab, char *str, int initx)
{
	int		i;
	int		j;
	int		inity;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			tab[j].x = i % 4;
			tab[j].y = i / 4;
			if (j == 0)
			{
				initx = tab[0].x;
				inity = tab[0].y;
			}
			tab[j].x = tab[j].x - initx;
			tab[j].y = tab[j].y - inity;
			j++;
		}
		i++;
	}
	return (tab)
}

t_point		*ft_IDtetri(char *str)
{
	t_point	*tab;
	int		j;
	int		initx;

	tab = ft_move(tab, str, initx);
	j = 0;
	while (j < 4)
	{
		j++;
		if (tab[j].x < 0)
		{
			initx = tab[j].x;
			j = 0;
			while (j < 4)
			{
				tab[j].x = tab[j].x - initx;
				j++;
			}
		}
	}
	return (tab);
}
