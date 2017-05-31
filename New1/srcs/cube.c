/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:41:21 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/30 17:16:55 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/*
** recupere les indexs de la piece pour la deplacer d'une case
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
	if (isok(lst))
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
** Affichage du cube
*/

void	printcube(void)
{
	int i;

	i = 0;
	while (i < g_c.size)
	{
		ft_putendl(g_c.c[i]);
		i++;
	}
}

/*
** Suprime la piece passee
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
** Ajout d'une ligne au cube
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
