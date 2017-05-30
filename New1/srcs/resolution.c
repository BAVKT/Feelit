/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:14:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/30 16:18:44 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"


///*
//** Algo de resolution
//*/
//int		resolution(t_lst *lst)
//{
//	if (!lst->next || resolution(lst))
//	if ()
//}
//
//
///*
//** Main de resolution
//*/
//int		mainres()
//{
//	resolution(g_c.firstma);
//	return (1);
//}

/*
** Essaye de faire rentrer la piece 
*/
//int		isok(int i, int j, t_lst *lst)
//{
//				ft_putendl("isok");
//				ft_putnbrendl(lst->nb);
//				//printcube();
//				//ft_putnbrendl(i);
//				//ft_putnbrendl(j);
//	int k; 		//Index pour la piece
//	int l;
//	int nb; 	//Le nombre de diezs
//
//	k = 0;
//	l = 0;
//	nb = 0;
//	while (lst->piece[k] && nb < 4 && lst->nb == 0)
//	{
//		if (lst->piece[k] == '#')
//		{
//			if (i + (k / 5) >= g_c.size || j + (k % 5) >= g_c.size ||
//				g_c.c[i + (k / 5)][j + (k % 5)] != '.')
//				return (0);
//			if (g_c.c[i + (k / 5)][j + (k % 5)] == '.')
//				g_c.c[i + (k / 5)][j + (k % 5)] = lst->id;
//			nb++;
//		}
//		k++;
//	}
//				printcube();
//	if (nb == 4)
//		return (1);
//	ft_putendl("here");
//	rmpiece(lst);
//	return (0);
//}
//
int		isok(t_lst *lst)
{
				ft_putstr("isok ");
				ft_putcharendl(lst->id);
				//printcube();
				//ft_putnbrendl(i);
				//ft_putnbrendl(j);
	int k; 		//Index pour la piece
	int nb; 	//Le nombre de diezs
	k = 0;
	nb = 0;
	while (nb != 4)
	{
		while (lst->piece[k] && nb < 4 && lst->nb == 0)
		{
			if (lst->piece[k] == '#')
			{
							ft_putstr("i - j ");
							ft_putnbr(g_c.i);
							ft_putchar('-');
							ft_putnbrendl(g_c.j);
				if (g_c.i + (k / 5) >= g_c.size || g_c.j + (k % 5) >= g_c.size ||
					g_c.c[g_c.i + (k / 5)][g_c.j + (k % 5)] != '.')
					break ;
				if (g_c.c[g_c.i + (k / 5)][g_c.j + (k % 5)] == '.')
					g_c.c[g_c.i + (k / 5)][g_c.j + (k % 5)] = lst->id;
				nb++;
							printcube();
			}
			if (nb == 4)
				return (1);
			k++;
		}
		nb = 0;
		k = 0;
		rmpiece(lst);
		if(!incr())
			return (0);			
	}
	return (0);
}

/*
** Algo de resolution
*/
int	resolution(t_lst *lst)
{
			ft_putendl("resolution");

	g_c.i = 0;
	g_c.j = 0;
	while (g_c.nbok != g_c.nbpiece)
	{
		if (isok(lst))
		{
			g_c.nbok++;
			lst->nb = g_c.nbok;
				ft_putnbrendl(g_c.nbok);
				ft_putnbrendl(g_c.nbpiece);
			if (g_c.nbok == g_c.nbpiece)
				return (1);
			lst = next(lst)	;
			if (resolution(lst))
				return(1);
				ft_putendl("i - j - size");
				ft_putnbrendl(g_c.i);
				ft_putnbrendl(g_c.j);
				ft_putnbrendl(g_c.size);
				ft_putendl("hey");
			lst = actual(lst);
				ft_putcharendl(lst->id);
			if (!movepiece(lst))
			{
					ft_putendl("HUI");
				return (0);
			}
			lst = next(lst);
		}
		else
		{
					ft_putcharendl(lst->id);
			lst = actual(lst);
			if (!movepiece(lst))
					return (0);
				ft_putendl("NIK");
			lst = next(lst);
		}
	}
	return (1);
}

/*
** Main de la resolution
*/
int		mainres()
{
			ft_putendl("mainres");
	t_lst	*lst;
	int		ok;

	lst = g_c.firstma;
	ok = 0;
	init();
	while (lst)
	{
		movit(lst);
		lst = lst->next;
	}
	//exit(0);
	lst = g_c.firstma;
	while (g_c.nbok != g_c.nbpiece)
	{
		ok = resolution(lst);
		if (!ok)
			onemore();
		else if (!ok && g_c.nbok < g_c.nbpiece)
			lst = next(lst);
	}
			ft_putendl("FINAL CUBE");
			printcube();
	return (1);
}

///*
//** Algo de resolution
//*/
//int	resolution(t_lst *lst)
//{
//	while (g_c.nbok < g_c.nbpiece)
//	{
//		if (douit(lst))
//		{
//			g_c.i = 0;
//			g_c.j = 0;
//				ft_putnbrendl(g_c.nbok);
//				ft_putnbrendl(g_c.nbpiece);
//			if (g_c.nbok >= g_c.nbpiece)
//			{
//				exit(1);
//				ft_putendl("hayo");
//				return (1);
//			}
//			resolution(next(lst));
//		}
//		else if (lst->id == g_c.last)
//			return (0);
//		else
//		{
//					ft_putendl("reso rm");
//			rmpiece(actual(lst));
//			g_c.i = 0;
//			g_c.j = 0;
//			lst = next(lst);
//		}
//	}
//	return (0);
//}
//
///*
//** Main de la resolution
//*/
//int		mainres()
//{
//			ft_putendl("mainres");
//	t_lst *lst;
//
//	init();
//	lst = g_c.firstma;
//	while (g_c.nbok < g_c.nbpiece)
//	{
//		if (!resolution(lst))
//		{
//			if (lst->id == g_c.last)
//			{
//				onemore();
//				lst = g_c.firstma;
//			}
//			else
//			{
//						ft_putendl("mainres rm");			
//				rmpiece(actual(lst));
//				lst = next(lst);
//			}
//		}
//		if (g_c.nbok >= g_c.nbpiece)
//			return (1);
//	}
//	return (0);
//}
//