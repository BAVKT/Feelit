/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:41:21 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/22 16:30:21 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/*
** recupere les indexs de la piece pour la deplacer d'une case
*/
int		movepiece(t_lst *lst)
{
		ft_putendl("movepiece");
			ft_putstr("lst = ");
			ft_putcharendl(lst->id);
	g_c.i = 0;
	while (g_c.i < g_c.size)
	{
			ft_putendl("yo");
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
			ft_putendl("1111");
		return (1);
	}			
	//if (g_c.i >= g_c.size -1 && g_c.j >= g_c.size)
	//	return (0);
	g_c.i = 0;
	g_c.j = 0;
			ft_putendl("22222");
	return (0);
}

/*
** Affichage du cube
*/
void 	printcube()
{
			//ft_putendl("printcube");
	int i;
	
	i = 0;
	while (i < g_c.size)
	{
		ft_putendl(g_c.c[i]);
		//ft_putstrcolor(str[i], CYAN);
		i++;
	}
	ft_putendl("--------");
}

/*
** Suprime la piece passee
*/
void	rmpiece(t_lst *lst)
{
		ft_putstr("rmpiece ");
		ft_putcharendl(lst->id);
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
	//ft_putstr("nb + nbok : ");
	//ft_putnbr(lst->nb);
	//ft_putchar('-');
	//ft_putnbrendl(g_c.nbok);
}

/*
** Ajout d'une ligne au cube
*/
void 	onemore()
{
			ft_putendl("onemore");
			printcube();
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
