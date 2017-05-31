/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:14:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/31 12:48:45 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/*
** Because isok was 26 lines long...
*/

int		isokbis(t_lst *lst, int k, int nb)
{
	while (lst->piece[k] && nb < 4 && lst->nb == 0)
	{
		if (lst->piece[k] == '#')
		{
			if (g_c.i + (k / 5) >= g_c.size || g_c.j + (k % 5) >= g_c.size ||
				g_c.c[g_c.i + (k / 5)][g_c.j + (k % 5)] != '.')
				break ;
			if (g_c.c[g_c.i + (k / 5)][g_c.j + (k % 5)] == '.')
				g_c.c[g_c.i + (k / 5)][g_c.j + (k % 5)] = lst->id;
			nb++;
		}
		if (nb == 4)
			return (1);
		k++;
	}
	return (0);
}

/*
** Check if it can put the piece on the grid
*/

int		isok(t_lst *lst)
{
	int k;
	int nb;

	while (1)
	{
		nb = 0;
		k = 0;
		if (isokbis(lst, k, nb))
			return (1);
		rmpiece(lst);
		if (!incr())
			return (0);
	}
	return (0);
}

/*
** Recursive algo just feel it
*/

int		resolution(t_lst *lst)
{
	g_c.i = 0;
	g_c.j = 0;
	while (g_c.nbok != g_c.nbpiece)
	{
		if (isok(lst))
		{
			g_c.nbok++;
			if ((lst->nb = g_c.nbok) == g_c.nbpiece)
				return (1);
			lst = next(lst);
			if (resolution(lst))
				return (1);
			lst = actual();
			if (!movepiece(lst))
				return (0);
		}
		else
		{
			lst = actual();
			if (!movepiece(lst))
				return (0);
		}
		lst = next(lst);
	}
	return (1);
}

/*
** Main de la resolution
*/

int		mainres(void)
{
	t_lst	*lst;
	int		ok;

	lst = g_c.firstma;
	ok = 0;
	init();
	while (lst)
	{
		movit(lst);
		lst = lst->next;
	}
	lst = g_c.firstma;
	while (g_c.nbok != g_c.nbpiece)
	{
		ok = resolution(lst);
		if (!ok)
			onemore();
		else if (!ok && g_c.nbok < g_c.nbpiece)
			lst = next(lst);
	}
	printcube();
	return (1);
}
