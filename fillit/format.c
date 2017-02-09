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

//Affichage du cube
void 	ft_printcube()
{
	ft_putendl("printcube");
	int i;
	int j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			ft_putchar(g_c.c[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

//Rempli de point
void	ft_addpoint()
{
	ft_putendl("addpoint");
	int i;
	int j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			if (g_c.c[i][j] != '.' || 
				(g_c.c[i][j] <= 'A' && g_c.c[i][j] >= 'Z'))
				g_c.c[i][j] = '.';
			j++;
		}
		i++;
	}
}

//Initialiation du cube et le rempli de points.
void 	ft_initcube()
{
	ft_putendl("inicube");
	int i;

	i = 0;
	g_c.c = (char **)malloc(sizeof(char *) * g_c.size);
	while (i < g_c.size)
	{
		g_c.c[i] = (char *)malloc(sizeof(char) * g_c.size);		
		i++;
	}
	ft_addpoint();
}

//Ajout d'une ligne au cube
void 	ft_onemore()
{
	ft_putendl("onemore");
	int i;
	int j;
	char **tmp;

	tmp = g_c.c;
	g_c.size += 1;
	ft_initcube();
	i = 0;
	while (i < g_c.size - 1)
	{
		j = 0;
		while (j < g_c.size - 1)
		{
			g_c.c[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}

//Fonction pour calculer le factoriel
int 	ft_fact(int nb)
{
	ft_putendl("fact");
	int r;
	int i;

	r = 1;
	i = 0;
	while (i < nb)
	{
		r *= i;
		i++;
	}
	return (r);
}

//Fonction pour remplir l'ID de chaque piece
void 	ft_rempid(t_lst *lst)
{
	ft_putendl("rempid");
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
	ft_putendl("resetok");
	while (lst)
	{
		lst->ok = 0;
		lst = lst->next;
	}
}

//Pour tester si le cube est mieux aue celui eja enregistrer et l'enregistrer.
void	ft_isgud()
{
	ft_putendl("isgud");
	if (g_c.size >= g_stock.size)
		return ;
	g_stock.size = g_c.size;
	g_stock.bestcube = g_c.tmp;
}

//Check si la piece rentre et la met dans cube si c'est bon
int 	ft_capasse(t_lst lst)
{
	ft_putendl("capasse");
	int i;		//Pour pas modifier les indexs de base 
	int j;
	int k; 		//Index pour la piece
	int nb; 	//Le nombre de diezs

	k = 0;
	nb = 0; 	
	i = g_c.i;
	j = g_c.j;
	g_c.tmp[g_c.i][g_c.j] = '#'; 	//Peutetre cette ligne en trop
	while (lst.piece[k])
	{
		if (lst.piece[k] == '#')
		{
			g_c.tmp[g_c.i + (k / 6)][g_c.j + (k % 6)] = '#';	//Pas sur des indexs
			nb++;
		}
		k++;
		if (nb == 4)
		{
			ft_isgud(g_c.tmp); 		//Comme c'est bon on enregistre le cube
			return (1);
		}
	}
	return (0);
}

//Avance dans le tableau jusqu'a la recherche d'un point
int 	ft_chercheplace(t_lst lst)
{
	ft_putendl("chercheplace");
	while (g_c.tmp[g_c.i][g_c.j] != '.' && g_c.tmp[g_c.i][g_c.j])
	{
		if (g_c.tmp[g_c.i][g_c.j] == '\n')
		{
				g_c.i++;
				g_c.j = 0;
		}
		else
			g_c.j++;
	}
	//Peut etre besoin de faire une incrementation de j pour pas boucler sur le meme point
	if (ft_capasse(lst) == 0 && g_c.j++ != g_c.size)	//On rappelle tant qu'on sait pas 
		ft_chercheplace(lst);
	if (g_c.j == g_c.size - 1)	//Si on est a la fin du cube
		ft_onemore();	
	return(1);
}

/*
** Trouver comment Faire les ordres 
*/
//La boucle pour tester avec chaque ordre de pieces.
void	ft_testordre(t_lst *lst)
{
	ft_putendl("testordre");
	t_lst 	tmplst;
	int 	i;
	int 	j;
	int 	k;

	k = 0;
	i = 0;
	tmplst = &lst;
	while (i++ < ft_fact(g_c.len))
	{
		j = 1;	//Maybe commencer a 0 ?
		if (k == g_c.len)
			k = 0;
		while (j++ <= g_c.len && lst->ok == 0)
		{
			ft_chercheplace(lst);
			if (j == g_c.len)
				lst = &tmplst;
			k++;
			lst->ok = 1;
			lst = lst->next;
		}
		ft_resetok(&tmplst);//Pas sur de comment passer le 1st maillon sans changer tmplst
	}
}

//Le main de resolution + initialisation des variables.
int		mainres(t_lst *lst)
{
	ft_putendl("mainres");

	g_c.size = 2;
	g_c.tmp = g_c.c;
	g_c.i = 0;
	g_c.j = 0;
	g_c.len = ft_lenlst(lst);
	ft_initcube();
	ft_resetok(lst);
	if (ft_chercheplace(lst))
		return (1);
	return (0);
}













