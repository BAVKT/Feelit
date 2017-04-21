/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:21:44 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/13 15:45:28 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Avance dans le tableau jusqu'a la recherche d'un point
*/
int 	ft_chercheplace()
{
	ft_putendl("chercheplace");

	while (g_c.tmp[g_c.i][g_c.j] != '.' && g_c.i < g_c.size && g_c.j <= g_c.size)
	{
			if (ft_incr() == 0)
				return (0);
	}
	return (1);
}

/*
** Incremente dans les indexs i et j comme il faut
*/
int 	ft_incr()
{
	ft_putendl("ft_incr");
	
			//ft_putstr("g_c.i = ");
			//ft_putnbrendl(g_c.i);
			//ft_putstr("g_c.j = ");
			//ft_putnbrendl(g_c.j);
	if (g_c.i + 1 >= g_c.size && g_c.j >= g_c.size)
	{
					//ft_putendl("YAGYAGYAGYA");
		//g_c.i = 0;
		//g_c.j = 0;
		return (0);
	}
	else if (g_c.j + 1 <= g_c.size)
	{
					//ft_putendl("YUGYUGYUGYU");	
		g_c.j++;
	}
	else
	{
					//ft_putendl("YOGYOGYOGYO");	
		g_c.i++;
		g_c.j = 0;
	}
		//ft_putstr("g_c.i = ");
		//ft_putnbrendl(g_c.i);
		//ft_putstr("g_c.j = ");
		//ft_putnbrendl(g_c.j);
	return (1);
}

/*
** Retourne le premier maillon pas en core posé en prenant des precautions
*/
t_lst 	*ft_incrlst(t_lst *lst)
{
	ft_putendl("ft_incrlst");
	if (lst->id == 'A' + g_c.len - 1)
		lst = g_c.firstma;
	else if (lst->id == 'A' && g_c.nbok > 0)
		lst->id = 'A';
	else
		lst = lst->next;
	while (lst->ok != 0)
	{
		if (!lst->next || !lst || lst->id == 'A' + g_c.len - 1)
			lst = g_c.firstma;
		else
			lst = lst->next;
	}
	return (lst);
}

/*
** Fonction de racine carré
*/
int		ft_sqrt(int nb)
{
	int		prime;
	int		i;

	prime = 1;
	i = 0;
	while (prime < nb)
	{
		i++;
		prime = i * i;
	}
		return (i);
}

/*
** Fonction pour calculer le factoriel
*/
int 	ft_fact(int nb)
{
	ft_putendl("fact");
	int r;
	int i;

	r = 1;
	i = 0;
	while (i < nb)
	{
		r *= i;
		i++;
	}
	return (r);
}
