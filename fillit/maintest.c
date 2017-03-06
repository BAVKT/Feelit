#include "fillit.h"
/*
//Pour voir si upleft marche.
int 	main(int ac, char **av)
{
	t_lst *lst;

	maincheck(av[1]);
	lst = g_c.firstma;
	while (lst->next)
	{
		ft_putendl("AVANT");
		ft_putendl(lst->piece);
		ft_putendl("APRES");
		upleft(lst);
		ft_putendl(lst->piece);
		lst = lst->next;
	}
	return (0);
}*/

int main(int ac, char **av)
{
	t_lst *lst;

	if (maincheck(av[1]) == 1)
		ft_putendl("FIlE IS OKAY");
	else
		ft_putendl("FILE IS NOT OKAY");
	lst = g_c.firstma;
	while (lst->next)
	{
		ft_putcharendl(lst->id);
		lst = lst->next;
	}
	return (0);
}