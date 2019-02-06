#include "fillit.h"

void	ft_dellist(t_tlist **alst)
{
	t_tlist *temp;

	if (alst)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			//ft_lstdelone(alst, del);
			free((*alst)->tab);
			free(*alst);
			*alst = temp;
		}
	}
}
