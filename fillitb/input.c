/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                        :+:      :+:    :+:       */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:16:28 by plaurent          #+#    #+#             */
/*   Updated: 2019/01/14 12:56:53 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**str;/*tableau de stockage des tetri*/
	int	n;
	int	i;

	n = 0;
	i = 0;
	str = (char **)malloc(sizeof(char *) * (26 + 1));//je malloc pour 26 pieces qui est le max + 1
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);//ouverture du fichier de lecture
	else
		return (2);
	str[0] = ft_strnew(16);//pour avoir une string de la tailles d'un tetri + les '.' qui vont avec lui
	while (get_next_line(fd, &line) == 1)//tant que la lecture n'est pas finie
	{
		//ft_putstr(line);
		str[i] = ft_strcat2(str[i], line);//je prend ce aue j ai u et le met a la fin de ce qui a ete lu avant
		free(line);//libere line pour le reutiliser a la prochaine lecture
		if (n == 4)//si on arrive a la lectur de la 4e et derniere ligne d'un tetri
		{
			n = 0;
			str[i][16] = '\0';
			if (ft_checknb(str[i]) == 2)//check du bon nb de '#' et de '.'
			{
				ft_putstr("nb de caractere non conforme");
				return (0);
			}
			if (ft_checktetri(str[i]) == 2)//check si tout les '#' forment un tetri
			{
				ft_putstr("tetri non conforme num:");
				return (0);
			}
			i++;// numero du tetri
			str[i] = ft_strnew(16);
		}
		else//si on est pas au dernier tetri alors:
			n++;
	}
	str[i] = NULL;
	i = 0;
	while (str[i] != '\0')//affichage des tetri apres verif en 1 ligne
	{
		ft_putstr(str[i++]);
		ft_putchar('\n');
	}
	if (argc == 2)
		close(fd);
	return (0);
}
