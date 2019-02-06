#include "fillit.h"

int		tetrinb(t_tlist *tetrilist, int mode, int linenb, int argc)
{
	int	tetrinb;
	t_tlist *tetritmp;
	
	if (mode == 1)
	{
		tetritmp = tetrilist;
		tetrinb = 0;
		while (tetritmp != NULL)
		{
			tetritmp = tetritmp->next;
			tetrinb++;
		}
		return (tetrinb);
	}
	if (mode == 2 && linenb != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (mode == 3 && argc != 2)
	{
		ft_putstr("usage: only one argument needed");
		return (0);
	}
	return (1);
}

t_tlist		*main2(int fd, t_tlist *tetrilist, char *str, char *line)
{
	int	linenb;

	linenb = 1;
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strcat(str, line);
		if (linenb == 0 && ft_check(str, 1) == 0)
			return (0);
		free(line); // a verifier
		if (linenb == 4) // corriger pb quand + de 12 points
		{
			linenb = 0;
			if (ft_check(str, 2) == 0)
				return (0);
			if (!(tetrilist = ft_newtetri(tetrilist, str, tetrinb(tetrilist, 1, linenb, 2))))
				return (0);
			bzero(str, 16);
		}
		else
			linenb++;
	}
	if (!(tetrinb(tetrilist, 2, linenb, 0)))
		return (0);
	return (tetrilist);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	*line;
	t_tlist	*tetrilist;

	tetrilist = NULL;
	line = NULL;
	if (tetrinb(tetrilist, 3, 0, argc) == 0)
		return (0);
	if	((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(str = ft_strnew(16)))
		return (0);
	if (!(tetrilist = main2(fd, tetrilist, str, line)))
		return (0);
	free(str);
	free(line);
	// ft_print(tetrilist); // TEST TEST TEST
	ft_printboard(ft_tetriplace(tetrilist, tetrinb(tetrilist, 1, 0, argc)));
	ft_dellist(&tetrilist);
	close(fd);
	//free(str); // ADD FREE
	return (0);
}
