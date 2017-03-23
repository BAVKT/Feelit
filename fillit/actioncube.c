/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actioncube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:18:25 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/23 21:14:11 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Quand on arrive pas a rentrer la piece dans le cube
** Retire la piece actuelle et celle d'avant et avance d'une piece
*/
void	ft_fail()
{
				ft_putendl("ft_fail");
										ft_putendl("RESOPLAC A ECHOUE DAMN");
	//g_c.nbok--;
	rmpiece(g_c.lst);
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
	rmpiece(g_c.lst);
	g_c.nbok--;
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	g_c.lst = ft_incrlst(g_c.lst);
	g_c.i = 0;
	g_c.j = 0;
}

/*
** Affichage du cube
*/
void 	ft_printcube(char **str, int size)
{
	ft_putendl("printcube");
	int i;
	
		ft_putnbrendl(size);
	i = 0;
	while (i < size)
	{
		ft_putendl(str[i]);
		//ft_putstrcolor(str[i], CYAN);
		i++;
	}
}

/*
** Ajout d'une ligne au cube
*/
void 	ft_onemore()
{
	ft_putendl("onemore");
	int i;

			ft_printcube(g_c.tmp, g_c.size);
			ft_printcube(g_c.c, g_c.size);
	i = 0;
	while (i < g_c.size)
		free(g_c.c[i++]);
	free(g_c.c);
	g_c.size++;
	g_c.c = ft_initcube();
	g_c.tmp = ft_initcube();
}

/*
** Pour tester si le cube est mieux que celui deja enregistré et l'enregistrer.
*/
void	ft_isgudcube()
{
	ft_putendl("isgudcube");
	if (g_c.size >= g_stock.size)
		return ;
	g_stock.size = g_c.size;
	g_stock.bestcube = g_c.tmp;
}

/*
** Pour enregistrer la piece dans le cube si elle rentre.
*/
void	ft_isgudpiece()
{
	ft_putendl("isgudpiece");
	int i;
	int j;
	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			g_c.c[i][j] = g_c.tmp[i][j];
			j++;
		}
		i++;
	}
	g_c.lst->ok = 1;
	g_c.nbok++;
	g_c.lst->nb = g_c.nbok;
	g_c.i = 0;
	g_c.j = 0;
					ft_printcube(g_c.c, g_c.size);
}
