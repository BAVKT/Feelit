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
		ft_putstr("lst->ok = ");
		ft_putnbrendl(lst->ok);
		ft_putstr("lst->id = ");
		ft_putcharendl(lst->id);
	while (lst->piece[k] && nb < 4 && lst->ok == 0)
	{
		if (lst->piece[k] == '#')
		{
									ft_putendl("++ CAPASSE ");
									ft_putendl("capasse piece = ");
									ft_putendl(lst->piece);
									ft_putstr("lst->ID = ");
									ft_putcharendl(lst->id);
					ft_putstr("CAPASSE 2 g_c.i = ");
					ft_putnbrendl(g_c.i);
					ft_putstr("CAPASSE 2 g_c.j = ");
					ft_putnbrendl(g_c.j);
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
			rmpiece(g_c.lst);
						ft_putendl("FT-CAPASSE == 0");
			//if (!resocheck())
			//	return (0);
			if (g_c.i + 1 >= g_c.size && g_c.j >= g_c.size)
			{
				ft_onemore();
				g_c.lst = g_c.firstma;
				ft_resetok(g_c.lst);
				g_c.i = 0;
				g_c.j = 0;
				g_c.nbok = 0;
				return (0);
			}
		}
		if (!ft_incr())
			break ;
	}
	if (ok == 1)
		ft_isgudpiece();
	return (ok);
}

// CETTE PARTIE QUI N'EST PLUS BONNE IL DOIT RETURN 0 DANS D'AUTRES CAS
/*
** Deuxieme partie de reso
*/

/*
int 	resocheck()
{
	ft_putendl("resocheck");
						ft_putstr("g_c.i = ");
						ft_putnbrendl(g_c.i + 1);
						ft_putstr("g_c.j = ");
						ft_putnbrendl(g_c.j);
						ft_putstr("g_c.size = ");
						ft_putnbrendl(g_c.size);
						ft_putstr("g_c.c[0][0] = ");
						ft_putcharendl(g_c.c[0][0]);
						ft_putstr("'A' + g_c.len - 1 = ");
						ft_putcharendl('A' + g_c.len - 1);
						ft_putstr("g_c.lst->id = ");
						ft_putcharendl(g_c.lst->id);
						if (g_c.lst->id == 'A' + g_c.len - 1)
							ft_putendl("PAS DE NEXT");
						else 
							ft_putendl("NIK TOI BIEN");
	if (g_c.lst->id == 'A' + g_c.len - 1 && g_c.i + 1 >= g_c.size && g_c.j >= g_c.size && g_c.c[0][0] == 'A' + g_c.len - 1)
	{
				ft_putendl("IF + ONEMORE + RESET OK");
		ft_onemore();
		g_c.lst = g_c.firstma;
		ft_resetok(g_c.lst);
		g_c.i = 0;
		g_c.j = 0;
		g_c.nbok = 0;
	}
	else if (g_c.lst->id == 'A' + g_c.len - 1 && g_c.i + 1 >= g_c.size && g_c.j >= g_c.size)
		return (0);
	else if (g_c.i + 1 >= g_c.size && g_c.j >= g_c.size && g_c.lst->next)
	{
				ft_putendl("ELSE g_c.lst->next");
		g_c.lst = ft_incrlst(g_c.lst);
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
		g_c.i = 0;
		g_c.j = 0;
	}
		ft_putendl("Le return (1)");
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
			ft_fail();
			if (g_c.lst->id == 'A' + g_c.len - 1)
			{
				ft_putnbr(g_c.nbok);
				ft_putstr(" id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
			/*	g_c.lst = g_c.firstma;
				while (g_c.lst->nb != g_c.nbok && g_c.lst->next)
				{
					g_c.lst = g_c.lst->next;
				ft_putstr(" id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);	
				}*/
				ft_fail();
			}
		}
		else
		{
			ft_putendl("yo");
			if (g_c.nbok >= g_c.len)
				return(1);
			g_c.lst = g_c.firstma;
			g_c.lst = ft_incrlst(g_c.lst);
			reso(g_c.lst);
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

	g_c.lst = lst;
	g_c.nbok = 0;
	g_c.i = 0;
	g_c.j = 0;
	g_c.len = lenlst(g_c.lst);
	g_c.taillemin = ft_sqrt(g_c.len * 4);
	g_c.size = g_c.taillemin;
	g_c.c = ft_initcube();
	g_c.tmp = ft_initcube();
	ft_setprev(g_c.lst);
	ft_resetok(g_c.lst);
	reso();
	return (1);
}
