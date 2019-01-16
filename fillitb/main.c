/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:07 by eviana            #+#    #+#             */
/*   Updated: 2019/01/14 18:34:54 by eviana           ###   ########.fr       */
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
	
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			tab[j].x = i % 4;
			tab[j].y = i / 4;
			j++;
		}
		i++;
	}
	tab[j] = NULL; // Pour signifier la fin ??
	return (tab);
}

// Creation du tetri via, (tab(x;y))
t_list	*ft_createtetri(t_list tetri, t_point tab, int tetrinb)
{
	if (!(tetri = (t_list*)malloc(sizeof(t_list))))
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
	else
	{
		tetri->tab = NULL;
		tetri->name = 0;
	}
	tetri->next = NULL;
	return (tetri);
}

t_list		*ft_newtetri(t_list **tetrilist, char *str, int tetrinb)
{
	t_list	*tetri;
	t_point	*tab;

	tab = ft_IDtetri(str);
	tetri = ft_createtetri(tetri, tab, tetrinb);
	

	// Maillage du dernier maillon avec la chaine
}

int		main(int argc, char **argv)
{
	int		fd;	
	char	*line;
	char	*str;
	t_list	*tetrilist;
	int		linenb; // compteur de ligne par tetri
	int		tetrinb; // compteur de tetri

	linenb = 0;
	tetrinb = 0;
	if (argc != 2)
		ft_putstr("usage: only one argument needed");
		return (0);
	else
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strcat(str, line);
		free(line); // a verifier
		if (linenb == 4)
		{
			linenb = 0;
			tetrinb++;
			if (ft_check(str) == 0)
				return (0);
			if (!ft_newtetri(tetrilist, str, tetrinb))
				return (0);
			str = bzero(str, 16);
		}
		else
			linenb++;
	}
}
