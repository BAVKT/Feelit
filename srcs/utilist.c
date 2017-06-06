/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:04:31 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/31 15:52:16 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** create a new block with the str OK
*/

t_lst	*initlst(t_lst *lst)
{
	if ((lst->next = (t_lst *)malloc(sizeof(t_lst))))
	{
		lst = lst->next;
		lst->next = NULL;
		lst->piece = ft_strnew(21);
	}
	return (lst);
}

/*
** return the next not okay block
*/

t_lst	*next(t_lst *lst)
{
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
** return the last OK block
*/

t_lst	*actual(void)
{
	t_lst	*lst;

	lst = g_c.firstma;
	while (lst->nb != g_c.nbok)
	{
		if (!lst->next)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}

/*
** len lst modified
*/

int		lenlst(t_lst *lst)
{
	int	nb;

	nb = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}
