/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/31 15:22:14 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Set the prev element of the block
*/

void	setprev(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (lst->next)
	{
		lst = lst->next;
		lst->prev = tmp;
		tmp = lst;
	}
}

/*
** Fill the ID of each piece
*/

void	rempid(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->id = 'A' + i;
		lst = lst->next;
		i++;
	}
}

/*
** Set each lst->nb to 0
*/

void	resetnb(t_lst *lst)
{
	while (lst)
	{
		lst->nb = 0;
		lst = lst->next;
	}
}

/*
** Init the grid anf fill it with points
*/

char	**initcube(void)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	str = (char **)malloc(sizeof(char *) * g_c.size);
	while (i < g_c.size)
	{
		str[i] = (char *)malloc(sizeof(char) * g_c.size);
		i++;
	}
	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

/*
** Initialise les variables des structs et listes
*/

void	init(void)
{
	rempid(g_c.firstma);
	setprev(g_c.firstma);
	resetnb(g_c.firstma);
	g_c.i = 0;
	g_c.j = 0;
	g_c.last = 'A' + g_c.nbpiece - 1;
	g_c.nbpiece = lenlst(g_c.firstma);
	g_c.taillemin = ft_sqrt(g_c.nbpiece * 4);
	g_c.size = g_c.taillemin;
	g_c.c = initcube();
}
