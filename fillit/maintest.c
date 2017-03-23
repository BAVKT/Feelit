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
}

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
*/


// Pour voir si ft_incr marche

int 	ft_incr()
{
	ft_putendl("ft_incr");
	if (g_c.i + 1 > g_c.size && g_c.j >= g_c.size)
	{
			ft_putendl("ONE");
		g_c.i = 0;
		g_c.j = 0;
		return (0);
	}
	else if (g_c.j + 1 <= g_c.size)
	{
		ft_putendl("TWO");
		g_c.j++;
	}

	else
	{
		ft_putendl("THREE");
		g_c.i++;
		g_c.j = 0;
	}
			ft_putstr("PENDANT g_c.i = ");
			ft_putnbrendl(g_c.i);
			ft_putstr("PENDANT g_c.j = ");
			ft_putnbrendl(g_c.j);	
	return (1);
}

int 	main()
{
	int i;

	i = 0;
	g_c.i = 0;
	g_c.j = 0;
	g_c.size = 4;

			ft_putstr("AVANT g_c.i = ");
			ft_putnbrendl(g_c.i);
			ft_putstr("AVANT g_c.j = ");
			ft_putnbrendl(g_c.j);	
 	while (i < 8)
	{
 		i++;
 		ft_incr();
 	}
 			ft_putstr("APRES g_c.i = ");
			ft_putnbrendl(g_c.i);
			ft_putstr("APRES g_c.j = ");
			ft_putnbrendl(g_c.j);
	return (0);
}
