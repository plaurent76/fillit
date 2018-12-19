/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:16:28 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/26 22:43:39 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>

static unsigned int	ft_strtest(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char			*ft_strjoin2(char *s1, char *s2, size_t size)
{
	char		*str;
	int			nb;
	char		*tmp;

	nb = ft_strlen(s1) + ++size;
	str = ft_strnew(nb);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --size > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - tmp));
}

static char			*ft_howcpy(char *str)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (str);
	}
	if (ft_strtest(str) > 0)
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (str);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[256];
	int			res;
	char		*ptr;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(str[fd]) && (str[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(str[fd], '\n')) &&
	(res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = str[fd];
		str[fd] = ft_strjoin2(ptr, buff, res);
		free(ptr);
	}
	*line = ft_strsub(str[fd], 0, ft_strtest(str[fd]));
	if (ft_howcpy(str[fd]) == NULL)
		return (0);
	return (1);
}
