/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:07 by eviana            #+#    #+#             */
/*   Updated: 2019/01/22 16:13:32 by eviana           ###   ########.fr       */
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

// check si on ne depasse pas du board et qu'aucune piece n'occupe l'espace
int		ft_checkboard(char **board, t_point tab, int i, int size)
{
	if (size > 0)
	{
		if ([(i / 4) + tab[0].y] < size && [(i % 4) + tab[0].x] < size &&
			[(i / 4) + tab[1].y] < size && [(i % 4) + tab[1].x] < size &&
			[(i / 4) + tab[2].y] < size && [(i % 4) + tab[2].x] < size &&
			[(i / 4) + tab[3].y] < size && [(i % 4) + tab[3].x] < size)
			return (1);
		else
			return (0);
	}
	else
	{
		if (board[(i / 4) + tab[0].y][(i % 4) + tab[0].x] == 
				board[(i / 4) + tab[1].y][(i % 4) + tab[1].x] == 
				board[(i / 4) + tab[2].y][(i % 4) + tab[2].x] == 
				board[(i / 4) + tab[3].y][(i % 4) + tab[3].x] == '.')
			return (1);
		else
			return (0);
	}
}	

// essai backtracking
char	**ft_backtrack(t_tlist *tetri, char **board, int size)
{
	int 	i;
	t_point *tab;

	i = 0;
	tab = tetri->tab;

	si la piece est placable, on la place
	si elle ne l'est pas on avance dans le board
	si on arrive a la fin du board, on clos et revient a la piece d'avant, 
	   qu'on fait bouger de 1
	



	while (ft_checkboard(board, tab, i, size) == 1) // bon ??? tant que dep pas
	{
		while (ft_checkboard(board, tab, i, size) == 1) // tant que depasse pas
		{
			while (ft_checkboard(board, tab, i, 0) == 1) // tant que place libre
			{
				board[(i / 4) + tab[0].y][(i % 4) + tab[0].x] = tetri->name;
				board[(i / 4) + tab[1].y][(i % 4) + tab[1].x] = tetri->name;
				board[(i / 4) + tab[2].y][(i % 4) + tab[2].x] = tetri->name;
				board[(i / 4) + tab[3].y][(i % 4) + tab[3].x] = tetri->name;
				if (tetri->next != NULL)
					board = ft_backtrack(tetri->next, board, size);
				else
					return (board);
			}
				
			board[(i / 4) + tab[0].y][(i % 4) + tab[0].x] = '.';
			board[(i / 4) + tab[1].y][(i % 4) + tab[1].x] = '.';
			board[(i / 4) + tab[2].y][(i % 4) + tab[2].x] = '.';
			board[(i / 4) + tab[3].y][(i % 4) + tab[3].x] = '.';


			i++; // A FINIR
		}
		i++; // au cas ou depasse a droite : revenir au i/case suivant(e)
		// ATTENTION BOUCLE INFINIE SI DEPASSE CADRE CONTINUELLEMENT
	}
	// if (tetri->next != NULL)
	//	ft_backtrack(tetri->next, board, size);
	return (board);
}

// essai backtracking
char	**ft_tetriplace(t_tlist *tetrilist, int	tetrinb)
{
	char 	**board;
	int		size;
	int		x;
	int		y;

	// initialise le board
	y = 0;
	size = ft_sqrt(tetrinb * 4) + 1; // attention erreur si envoie 1 seule barre
	if (!(board = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL); // verif output ok
	while (y < size)
	{
		x = 0;
		if (!(board[y] = (char*)malloc(sizeof)(char) * (size + 1)))
			return (NULL);
		while (x < size)
		{
			board[y][x] = '.';
			x++;
		}
		board[y][x] = '\0';
		y++;
	}
	board[y] = NULL;
	
	// lance le backtracking
	tab = ft_backtrack(tetrilist, tab, size);
	return (tab);
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
