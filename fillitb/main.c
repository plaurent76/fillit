/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:07 by eviana            #+#    #+#             */
/*   Updated: 2019/01/22 11:39:29 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *str)
{
	// str[16] = '\0'; cat will do
	if (ft_checknb(str) == 2)
	{
		ft_putstr("error\n"); // nb char KO
		return (0);
	}
	if (ft_checktetri(str) == 2)
	{
		ft_putstr("error\n"); // tetri KO
		return (0);
	}
	return (1);
}

// Conversion str to tab(x;y)
t_point		*ft_IDtetri(char *str)
{	
	t_point	*tab;
	int		i;
	int		j;
	int		inity;
	int		initx;
	
	i = 0;
	j = 0;
	if (!(tab = (t_point*)malloc(sizeof(t_point) * 5)))
		return (0);
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
			tab[j].x = tab[j].x - initx; // POUR METTRE EN HAUT A GAUCHE
			tab[j].y = tab[j].y - inity; // SAME
			j++;
		}
		i++;
	}

	tab[j].x = 5; // Pour signifier la fin ?? scotch
	return (tab);
}

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

t_tlist		*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb)
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
		// free tetrilist ?
		return (tetri);
	else
	{
		templist = tetrilist; // NEED TEMP ?
		while (templist->next != NULL)
			templist = templist->next;
		templist->next = tetri;
		return (tetrilist);
	}
}

// Impression pour verif
void	ft_print(t_tlist *tetrilist)
{
	t_point	*tab;
	int		i;
	int		x;
	int		y;
	
	while (tetrilist)
	{
		tab = tetrilist->tab;
		i = 0;
		while (tab[i].x != 5) // scotch ou mettre i < 4
		{
			y = 0;
			while (y < 4)
			{
				x = 0;
				while (x < 4)
				{
					if (x == tab[i].x && y == tab[i].y)
					{
						ft_putchar(tetrilist->name);
						i++; // bonne place ?
					}
					else
						ft_putchar('.');
					x++;
				}
				ft_putchar('\n');
				y++;
			}
		}
		ft_putchar('\n');
		tetrilist = tetrilist->next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;	
	char	*line;
	char	*str;
	t_tlist	*tetrilist;
	int		linenb; // compteur de ligne par tetri
	int		tetrinb; // compteur de tetri

	linenb = 1;
	tetrinb = 0;
	tetrilist = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: only one argument needed");
		return (0);
	}
	if	((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(str = ft_strnew(16)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strcat(str, line);
		free(line); // a verifier
		if (linenb == 4) // corriger pb quand + de 12 points
		{
			linenb = 0;
			if (ft_check(str) == 0)
			{
				free(str);
				return (0);
			}
			if (!(tetrilist = ft_newtetri(tetrilist, str, tetrinb)))
			{
				free(str);
				return (0);
			}
			bzero(str, 16); // modif directement a l'adresse
			tetrinb++;
		}
		else
			linenb++;
	}
	ft_print(tetrilist);
	free(str);
	return (0);
}
