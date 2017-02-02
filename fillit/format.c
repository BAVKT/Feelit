/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:24:24 by vmercadi          #+#    #+#             */
/*   Created: 2017/01/17 03:24:24 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//Pour rentrer la piece dans le tableau et passer a la suite 
int 	ft_placement(t_lst lst, t_cube c)
{
	
}

//Check si ca rentre en verifiant la hauteur et largeur 
int 	ft_capasse(t_lst lst, t_cube c)
{
	int i;	//Pour pas modifier les indexs de base 
	int j;

	i = c.i;
	j = c.j;
	while (lst.largeur > 0)
	{
		if (c.cube[i][j] != '.')
			return (0);
		while (lst.hauteur > 0)
		{
			if (c.cube[i][j] != '.')	
				return (0);
			i++;
		}
		j++;
	}
	ft_placement(lst, cube);
	return (1);
}

//Avance dans le tableau jusqu'a la recherche d'un point
int 	ft_chercheplace(t_lst lst, t_cube c)
{
	while (c.cube[c.i][c.j] != '.')
	{
		if (c.cube[c.i][c.j] == '/n')
		{
				i++;
				j = 0;
		}
		else 
			j++;
	}
	if (ft_capasse(lst, c) == 0)	//On rappelle la fonction dans qu'on sait pas 
		ft_chercheplace(lst, c);
	return(1);
}

//Le main de resolution
int		mainres(t_lst lst)
{
	t_cube 	c;
	/*
	cube.cube = //on y met le tableau créé par jcatot
	*/
	c.i = 0;
	c.j = 0;
	if (ft_chercheplace(lst, c))
		return (1);
	return (0);
}








/*
//Uen fonction qui check si y a des lignes juste de points et qui decale ces lignes 
// en dessous si elles sont au dessus et a droite si elles sont a gauche.
//Mais il faut qu'elles ne contiennnt que des '.'

void	ft_formate(t_lst *lst)
{
	int 	i;
	int 	j;
	int 	ok;
	char 	**tab;

	i = 0;
	j = 0;	
	ok = 0;
	tab = ft_strsplit(lst->piece, '\n');
	while (j++ < 4 && ok == 0)
	{
		while (i++ < 4 && ok == 0)
		{
			if (tab[i][j] == '#')
				ok = 1;
		}
	}
	while (lst->piece[(i-- * j) - 1] == '.') //On recule jusqu'au \n
		nb++;
}

//Decale les lignes
int	ft_decaligne(t_lst *lst)
{
	int 	nbl;	//Numero de la ligne a decaler
	int 	i;

	nbl = 0;
	i = 0;
	while (tab[i][j] == '.')
	{
		i++;
	}
	return (nbl);
}

//Décale les colonnes 
int	ft_decalcol(t_lst *lst)
{
	int 	nbc;	//Numero de la colonne a decaler
	int 	i;
	int 	ok;

	nbc = 0;
	ok = 0;
	i = 0;
	while (ok == 0)
	{
		nbc++;
		while (lst->piece[i] != '#')
		{
			i+=5;
			if (i >= 20)
			{
				i = 0;
				break ;
			}
			if (i == '#')
				ok = 1;
		}
		i++;
	}
	return (nbc);
}
*/










