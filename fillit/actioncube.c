/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actioncube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:18:25 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/06 16:52:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Quand on arrive pas a rentrer la piece dans le cube
** Retire la piece actuelle et celle d'avant et avance d'une piece
*/
/*
void	ft_fail()
{
				ft_putendl("ft_fail");
										ft_putendl("RESOPLAC A ECHOUE DAMN");
	//g_c.nbok--;
				ft_putnbr(g_c.nbok);
				ft_putstr(" id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
	rmpiece(g_c.lst);
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
				ft_putnbr(g_c.nbok);
				ft_putstr(" id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
	rmpiece(g_c.lst);
	g_c.nbok--;
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	g_c.lst = ft_incrlst(g_c.lst);
	g_c.i = 0;
	g_c.j = 0;
}*/

void	ft_fail()
{
				ft_putendl("ft_fail");
										ft_putendl("RESOPLAC A ECHOUE DAMN");
	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putstr("g_c.lst->nb = ");
				ft_putnbrendl(g_c.lst->nb);
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
	if (g_c.lst->ok == 1)
		g_c.nbok--;
	rmpiece(g_c.lst);
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	if (g_c.lst->id == 'A' + g_c.len - 1)
	{
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putendl("AAAAAAAAAAAAAHHHHHHHHHH");
		g_c.lst = g_c.firstma;
		while (g_c.lst->nb != g_c.nbok)
		{
				ft_putstr("g_c.lst->id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
			g_c.lst = g_c.lst->next;
		}
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putstr("g_c.lst->nb = ");
				ft_putnbrendl(g_c.lst->nb);
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
		rmpiece(g_c.lst);
		g_c.nbok--;
		g_c.lst->ok = 0;
		g_c.lst->nb = 0;
	}
		g_c.lst = ft_incrlst(g_c.lst);
	g_c.i = 0;
	g_c.j = 0;
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putstr("g_c.lst->nb = ");
				ft_putnbrendl(g_c.lst->nb);
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
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