/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:35:18 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/06 11:45:17 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.hst"

// Creation du tetri via tab(x;y) et son numero
t_tlist	*ft_createtetri(t_point *tab, int tetrinb)
{
	t_tlist *tetri;

	if (!(tetri = (t_tlist*)malloc(sizeof(t_tlist))))
		return (NULL);
	if (tab)
	{
		if (!(tetri->tab = (void*)malloc(sizeof(t_point) * (5))))
		{
			free(tetri);
			return (NULL);
		}
		ft_memcpy(tetri->tab, tab, (sizeof(t_point) * 5)); // ??? sizeof ???
		tetri->name = (char)tetrinb + 'A';
	}
	else // usefull ?
	{
		tetri->tab = NULL;
		tetri->name = 0;
	}
	tetri->next = NULL;
	// FREE QQUCHOSE ?
	return (tetri);
}

*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb)
{
	t_tlist	*tetri;
	t_tlist	*templist; // free ?
	t_point	*tab;

	tab = ft_IDtetri(str);
	tetri = ft_createtetri(tab, tetrinb);
	free(tab);
	tab = NULL;

	// Maillage du nouveau maillon a la fin de la chaine
	if (tetrilist == NULL)
		return (tetri);
	else
	{
		templist = tetrilist; // NEED TEMP ? // FREE TEMP SOMEWHERE ?
		while (templist->next != NULL)
			templist = templist->next;
		templist->next = tetri;
		return (tetrilist);
	}
}
