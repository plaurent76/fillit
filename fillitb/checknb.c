#include "header.h"

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
		if (str[i] == ',' || str[i] == '#')
			k++;
		i++;
	}
	ft_putnbr(k);
	ft_putchar('\n');
	ft_putnbr(nb);
	ft_putchar('\n');
	if (nb == 4 && k == 16)
		return (1);
	return (2);
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
			n = n + ft_checkodbg(str, i);
	}
	if (n < 6)
		return (2);
	return (1);
}

int	ft_checkodbg(char *str, int i)
{
	int	k;

	k = 0;
	if (i > 3)
		if (str[i - 4] == '#')
			k++;
	if (i != 3 && i != 7 && i != 11 && i != 15)
		if (str[i + 1] == '#')
			k++;
	if (i < 12)
		if (str[i + 4] == '#')
			k++;
	if (i != 0 && i != 4 && i != 8 && i != 12)
		if (str[i - 1] == '#')
			k++;
	//ft_putnbr(k);
	return (k);
}








