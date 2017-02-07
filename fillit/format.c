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

/*
**
** PEUT ETRE QU'IL FAUT METTRE DES POINTS A LA PLACE DES FLECHES
** OU INVERSEMENT COMME ON PASSE UN MAILLON DE LA STRUCT
**
*/

//Fonction pour remplir l'ID de chaque piece
void 	ft_rempid(t_lst *lst)
{
	int 	i;

	i = 0;
	while(lst)
	{
		lst->id = 'A' + i;
		lst = lst->next;
		i++;
	}
}

//Fonction pour reset le OK de chaque maillon a chaque test d'ordre
void	ft_resetok(t_lst *lst)
{
	while (lst)
	{
		lst->ok = 0;
		lst = lst->next;
	}
}

//Pour tester si le cube est mieux aue celui eja enregistrer et l'enregistrer.
void	ft_isgud(char **tmp)
{
	if (g_c.size >= g_stock.size)
		return ;
	g_stock.size = g_c.size;
	g_stock.bestcube = tmp;
}

//Check si la piece rentre et la met dans cube si c'est bon
int 	ft_capasse(t_lst lst, char **tmp)
{
	int i;	//Pour pas modifier les indexs de base 
	int j;
	int k; 	//Index pour la piece
	int nb 	//Le nombre de diezs

	k = 0;
	nb = 0; 	
	i = g_c.i;
	j = g_c.j;
	tmp[g_c.i][g_c.j] = '#'; 	//Peutetre cette ligne en trop
	while (lst->piece[k])
	{
		if (lst->piece[k] == '#')
		{
			tmp[g_c.i + (k / 6)][g_c.j + (k % 6)] = '#';	//Pas sur des indexs
			nb++;
		}
		k++;
		if (nb == 4)
		{
			ft_isgud(tmp); 		//Comme c'est bon on enregistre le cube
			return (1);
		}
	}
	return (0);
}

//Avance dans le tableau jusqu'a la recherche d'un point
int 	ft_chercheplace(t_lst lst, char **tmp)
{
	while (tmp[g_c.i][g_c.j] != '.' && tmp[g_c.i][g_c.j])
	{
		if (tmp[g_c.i][g_c.j] == '/n')
		{
				g_c.i++;
				g_c.j = 0;
		}
		else
			g_c.j++;
	}
	//Peut etre besoin de faire une incrementation de j pour pas boucler sur le meme point
	if (ft_capasse(lst, tmp) == 0 && g_c.j != g_c.size)	//On rappelle tant qu'on sait pas 
		ft_chercheplace(lst, tmp);
	if (g_c.j == g_c.size - 1)	//Si on est a la fin du cube
	{
		//Fonction d'agrandissement du cube
	}		
	return(1);
}

//La boucle pour tester avec chaque ordre de pieces.
void	ft_testordre(t_lst *lst)
{
	char 	**tmp;
	int 	len;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	tmp = g_c.cube;
	len = ft_lenlst(lst);
	while (i++ < ((len * len) - len)) //Pas sur du calcul là
	{
		while (lst && j++ < len)
		{

		}
		lst->ok = 1;
	}
	ft_chercheplace(lst)
}

//Le main de resolution
int		mainres(t_lst *lst)
{
	/*
	cube.cube = //on y met le tableau créé par jcatot
	*/
	g_c.i = 0;
	g_c.j = 0;
	ft_resetok(t_lst *lst);
	if (ft_chercheplace(lst))
		return (1);
	return (0);
}













