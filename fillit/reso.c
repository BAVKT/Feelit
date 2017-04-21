/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/22 14:22:29 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ca paaaaasssssse
*/
int 	ft_capasse(t_lst *lst)
{
	ft_putendl("capasse");
	int i;		//Pour pas modifier les indexs de base 
	int j;
	int k; 		//Index pour la piece
	int l;
	int nb; 	//Le nombre de diezs

	k = 0;
	l = 0;
	nb = 0;
	i = g_c.i;
	j = g_c.j;
	g_c.tmp = g_c.c;
	while (lst->piece[k] && nb < 4 && lst->ok == 0)
	{
		if (lst->piece[k] == '#')
		{
									ft_putstr("nbok = ");
									ft_putnbr(g_c.nbok);
									ft_putstr(" | id = ");
									ft_putchar(lst->id);
									ft_putnbrendl(lst->nb);
									ft_printcube(g_c.c, g_c.size);
			if (i + (k / 5) >= g_c.size || j + (k % 5) >= g_c.size ||
				g_c.tmp[i + (k / 5)][j + (k % 5)] != '.')
				return(0);
			if (g_c.tmp[i + (k / 5)][j + (k % 5)] == '.')
				g_c.tmp[i + (k / 5)][j + (k % 5)] = lst->id;
			nb++;
		}
		k++;
	}
	if (nb == 4)
		return (1);
	return (0);
}

// CETTE PARTIE EST ADAPTER AVEC RESOCHECK
/*
** Premiere partie de reso
*/
int 	resoplace()
{
					ft_putendl("resoplace");
	int ok;
					ft_printcube(g_c.tmp, g_c.size);
					ft_putstr("NB OK = ");
					ft_putnbrendl(g_c.nbok);
	g_c.i = 0;
	g_c.j = 0;
	ok = 0;
	while (ok == 0)
	{
		if (!ft_chercheplace())
			return(0);
		ok = ft_capasse(g_c.lst);
		if (ok == 0)
		{
						ft_putendl("capasse == 0");
			rmpiece(g_c.lst);
			if (g_c.i + 1 >= g_c.size && g_c.j + 1 >= g_c.size && g_c.tmp[0][0] == g_c.last)
			{
				ft_onemore();
				g_c.lst = g_c.firstma;
				ft_resetok(g_c.lst);
				g_c.i = 0;
				g_c.j = 0;
				g_c.nbok = 0;
				return (1);
			}
		}
		if (!ft_incr())
			break ;
	}
	if (ok == 1)
		ft_isgudpiece();
	return (ok);
}

/*
** La resolution
*/
/*
int 	reso()
{
	ft_putendl("reso");
	while (g_c.nbok < g_c.len) 
	{
		if (resoplace() == 0)
		{
			if (ft_lastok())
				ft_rmlastok();
			else
				ft_fail();
		}
		else
		{
			ft_putendl("yo");
			if (g_c.nbok >= g_c.len)
				return(1);
			g_c.lst = g_c.firstma;
			if (g_c.lst->ok == 1)
				g_c.lst = ft_incrlst(g_c.lst);
			reso(g_c.lst);
		}
	}
	return (1);
}
*/

/*
** La resolution
*/
int 	reso()
{
	ft_putendl("reso");
	while (g_c.nbok < g_c.len)
	{
		if (resoplace() == 0)
		{
				ft_putstr("id = ");
				ft_putcharendl(g_c.lst->id);
			ft_rempalpha();
			ft_fail();
		}
		else
		{
			ft_putendl("yo");
			if (g_c.nbok >= g_c.len)
				return(1);
			g_c.lst = g_c.firstma;
			if (g_c.lst->ok == 1)
				g_c.lst = ft_incrlst(g_c.lst);
			reso();
		}
	}
	return (1);
}

/*
** Le main de resolution + initialisation des variables.
*/
int		mainres(t_lst *lst)
{
	ft_putendl("mainres");
	t_lstalpha	*lstalpha;

	g_c.lst = lst;
	g_c.nbok = 0;
	g_c.i = 0;
	g_c.j = 0;
	g_c.len = lenlst(g_c.lst);
	g_c.last = 'A' + g_c.len - 1;
					ft_putstr("g_c.len = ");
					ft_putnbrendl(g_c.len);
	g_c.taillemin = ft_sqrt(g_c.len * 4);
	g_c.size = g_c.taillemin;
	g_c.c = ft_initcube();
	g_c.tmp = ft_initcube();
	lstalpha = (t_lstalpha *)malloc(sizeof(t_lstalpha));
	lstalpha->next = NULL;
	lstalpha->str = ft_strnew(5);
	lstalpha->str = "AAAA";	
	g_c.firstalpha = lstalpha;
	g_c.alpha = g_c.firstalpha;
	ft_setprev(g_c.lst);
	ft_resetok(g_c.lst);
				ft_putstr(" id = ");
				ft_putcharendl(lst->id);
			while (lst->next)
			{
				lst = lst->next;
				ft_putstr(" id = ");
				ft_putcharendl(lst->id);
			}
	reso();
			ft_putstr("g_c.nbok = ");
			ft_putnbrendl(g_c.nbok);
			ft_putstr("g_c.len = ");
			ft_putnbrendl(g_c.len);
	return (1);
}
