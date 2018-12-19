/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                        :+:      :+:    :+:       */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:16:28 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/26 22:43:39 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**str;
	int	n;
	int	i;

	n = 0;
	i = 0;
	str = (char **)malloc(sizeof(char **) * 26);
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	str[0] = ft_strnew(21);
	while (get_next_line(fd, &line) == 1)
	{
		str[i] = ft_strcat2(str[i], line);
		free(line);
		if (n == 4)
		{
			str[i][20] = '\0';
			n = 0;
			if (ft_checknb(str[i]) == 2)
			{
				ft_putstr("nb de caractere non conforme");
				return (0);
			}
			i++;
			str[i] = ft_strnew(21);
		}
		n++;
	}
	str[i] = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putstr(str[i++]);
		ft_putchar('\n');
	}
	if (argc == 2)
		close(fd);
	return (0);
}
