		/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:04:31 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/11 20:18:45 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/*
** Retourne le maillon avec le nb precedent au maillon courant
*/
t_lst	*prevnb(t_lst *lst)
{
			//ft_putnbrendl(g_c.nbok);		
			ft_putendl("prevnb");
			//ft_putchar(lst->id);
			//ft_putnbrendl(lst->nb);
	int nb;

	nb = lst->nb - 1;
	lst = g_c.firstma;
	while (lst->next && lst->nb != nb)
		lst = lst->next;
			//ft_putchar(lst->id);
			//ft_putnbrendl(lst->nb);
	return (lst);
}

/*
** Retourne le maillon avec le nb suivant au maillon courant
*/
t_lst	*nextnb(t_lst *lst)
{
			ft_putendl("nextnb");

	int nb;

	nb = lst->nb + 1;
	if (nb > g_c.nbok)
		return (NULL);
	lst = g_c.firstma;
	while (lst->next && lst->nb != nb)
		lst = lst->next;
	return (lst);	
}

/*
** Retourne le maillon suivant pas encore posé et revient au premier si il y en a pas
*/
t_lst	*next(t_lst *lst)
{
			ft_putendl("next");
	
	lst = g_c.firstma;
	while (lst->nb != 0)
	{
		if (lst->next)
			lst = lst->next;
		else 
			return (NULL);
	}
	return (lst);
}

/*
** Retourne le maillon correspondant au nombre de pieces posées
*/
t_lst	*actual()
{
			ft_putendl("actual");
			ft_putnbrendl(g_c.nbok);
	t_lst *lst;
	
	lst = g_c.firstma;
	while (lst->nb != g_c.nbok)
	{
			ft_putchar(lst->id);
			ft_putnbrendl(lst->nb);
		if (!lst->next)
			return (NULL);
		lst = lst->next;
	}
			ft_putchar(lst->id);
			ft_putnbrendl(lst->nb);
	return (lst);
}

/*
**Len lst modified
*/
int		lenlst(t_lst *lst)
{
	int nb;

	nb = 1; 				//Valeur passée a 1 au lieu de 0
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}
