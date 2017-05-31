/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:04:31 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/30 18:13:23 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		ft_sqrt(int nb)
{
	int	prime;
	int	i;

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
