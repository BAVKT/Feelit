/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:41:21 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/06 18:06:43 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		movepiecebis(t_lst *lst)
{
	int k;

	k = 0;
	while (lst->piece[k] != '#')
		k++;
	while (g_c.j > 0 && k != 0)
	{
		if (g_c.j == 0)
		{
			g_c.i--;
			g_c.j = g_c.size;
		}
		g_c.j--;
		k--;
	}
	return (1);
}

/*
** Move the piece to the next .
*/

int		movepiece(t_lst *lst)
{
	g_c.i = 0;
	while (g_c.i < g_c.size)
	{
		g_c.j = 0;
		while (g_c.j < g_c.size)
		{
			if (g_c.c[g_c.i][g_c.j] == lst->id)
				break ;
			g_c.j++;
		}
		if (g_c.c[g_c.i][g_c.j] == lst->id)
			break ;
		g_c.i++;
	}
	if (movepiecebis(lst) && isok(lst))
	{
		g_c.nbok++;
		lst->nb = g_c.nbok;
		g_c.i = 0;
		g_c.j = 0;
		return (1);
	}
	g_c.i = 0;
	g_c.j = 0;
	return (0);
}

/*
** Obviously print the cube
*/

void	printcube(void)
{
	int i;

	i = 0;
	while (i < g_c.size)
	{
		write(1, g_c.c[i], g_c.size);
		ft_putchar('\n');
		i++;
	}
}

/*
** Erase the piece from the grid
*/

void	rmpiece(t_lst *lst)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			if (g_c.c[i][j] == lst->id)
				g_c.c[i][j] = '.';
			j++;
		}
		i++;
	}
	if (lst->nb != 0)
	{
		g_c.nbok--;
		lst->nb = 0;
	}
}

/*
** Add 1 row and column to the grid
*/

void	onemore(void)
{
	int i;

	i = 0;
	while (i < g_c.size)
		free(g_c.c[i++]);
	free(g_c.c);
	g_c.size++;
	g_c.nbok = 0;
	g_c.c = initcube();
	resetnb(g_c.firstma);
}
