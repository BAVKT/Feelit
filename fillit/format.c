/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/06 06:34:20 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


#include <stdio.h>

/*
**	Pour effacer la piece dans le tmp si elle est rentree qu'en pqrtie ou pas du tout.
*/
void	rmpiece(t_lst *lst)
{
	ft_putendl("rmpiece");

	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			if (g_c.tmp[i][j] == lst->id)
				g_c.tmp[i][j] = '.';
			j++;
		}
		i++;
	}
}

/*
** Fonction de racine carré
*/
int		ft_sqrt(int nb)
{
	int		prime;
	int		i;

	prime = 1;
	i = 0;
	while (prime < nb)
	{
		i++;
		prime = i * i;
	}
		return (i);
}

/*
** Affichage du cube
*/
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

//A EFFACER
//Affichage du cube tmp
void 	ft_printcubetmp()
{
	ft_putendl("printcubeTMP");
	int i;
	int j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			ft_putchar(g_c.tmp[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

//A EFFACER
//Affichage du cube stock 
void 	ft_printcubestock()
{
	ft_putendl("printcubeSTOCK");
	int i;
	int j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			ft_putchar(g_stock.bestcube[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

/*
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
				(g_c.c[i][j] < 'A' && g_c.c[i][j] > 'Z'))
				g_c.c[i][j] = '.';
			j++;
		}
		i++;
	}
}
*/

/*
**Initialiation du cube et le rempli de points.
*/
void 	ft_initcube()
{
	ft_putendl("inicube");
	int i;
	int j;

	i = 0;
	if (g_c.c)
	{
		ft_putendl("bli");
		g_c.tmp = g_c.c;
	}
	g_c.c = (char **)malloc(sizeof(char *) * g_c.size);
	while (i < g_c.size)
	{
		g_c.c[i] = (char *)malloc(sizeof(char) * g_c.size);		
		i++;
	}
	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			g_c.c[i][j] = '.';
			j++;
		}
		i++;
	}
}

/*
**Ajout d'une ligne au cube
*/
void 	ft_onemore()
{
	ft_putendl("onemore");
	int i;

	i = 0;
	while (i < g_c.size)
		free(g_c.c[i++]);
	free(g_c.c);
	g_c.size += 1;
	ft_initcube();
}

/*
**Fonction pour calculer le factoriel
*/
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

/*
**Fonction pour remplir l'ID de chaque piece
*/
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

/*
**Fonction pour reset le OK de chaque maillon a chaque test d'ordre
*/
void	ft_resetok(t_lst *lst)
{
	ft_putendl("resetok");
	while (lst)
	{
		lst->ok = 0;
		lst = lst->next;
	}
}

/*
**Pour tester si le cube est mieux que celui deja enregistré et l'enregistrer.
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
**Pour enregistrer la piece dans le cube si elle rentre.
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
}

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
			if (i + (k / 5) >= g_c.size || j + (k % 5) >= g_c.size ||
				g_c.tmp[i + (k / 5)][j + (k % 5)] != '.')
				return(0);
			if (g_c.tmp[i + (k / 5)][j + (k % 5)] == '.')
				g_c.tmp[i + (k / 5)][j + (k % 5)] = lst->id;	//Pas sur des indexs
			nb++;
		}
		k++;
									ft_putendl("++ CAPASSE ");
									ft_putendl("capasse piece = ");
									ft_putendl(lst->piece);
									ft_putstr("lst->ID = ");
									ft_putcharendl(lst->id);
									ft_printcube();
	}
	if (nb == 4)
	{
		ft_putendl("nb == 4");
		ft_isgudpiece(); 		//Comme c'est bon on enregistre la piece
		return (1);
	}
	return (0);
}

//Surement besoin en amont de la technique a double entree pour tester 
//tous les maillons dans chaque ordres.s.
int 	reso(t_lst *lst)
{
	ft_putendl("reso");
	int 	nbok; 					//Le nombre de pieces placées

	nbok = 0;
	while (nbok < g_c.len)
	{
		ft_chercheplace();
		if (ft_capasse(lst)) 		//Si la piece rentre on la place
		{
			ft_putendl("LA CEST PASSSEEEEEE");
			lst->ok = 1;
			nbok++;					//On incremente le nb de piece placees
			lst = g_c.firstma;
		}
		if (lst->ok == 0)
		{
									ft_putendl("ON PASSEEE IIIICCCCCIIIIIIII");
									ft_putendl("piece : ");
									ft_putendl(lst->piece);
									ft_putstr("Adresse maillon = ");
									printf("%p", lst);
									fflush(stdout);
									ft_putchar('\n');
									ft_putstr("lst->ID = ");
									ft_putnbrendl(lst->id);
									ft_putendl("if lst->ok AVANT");
									ft_printcube();		
			rmpiece(lst);
									ft_putendl("if lst->ok APRES");
									ft_printcube();		
		}
		if (!lst->next && g_c.i >= g_c.size && g_c.j >= g_c.size) //Si y a plus d'autres maillons ni place
		{
					ft_putendl("IF + ONEMORE + RESET OK");

			ft_onemore();			//On agrandi le tableau
			lst = g_c.firstma; 		//On retourne au debut de la liste.
			ft_resetok(lst);
			g_c.i = 0;
			g_c.j = 0;
			nbok = 0;
		}
		else if (!lst->next)
		{
			ft_putendl("ELSE IF lst = firstma");
			g_c.i++;
			g_c.j++;
			lst = g_c.firstma;
		}
		else
		{
			ft_putendl("ELSE lst->next");
			lst = lst->next; 		//Sinon on passe à la prochaine piece
		}
	}
	ft_isgudcube();
	return (1);
}

/*
**Avance dans le tableau jusqu'a la recherche d'un point
*/
int 	ft_chercheplace()
{
	ft_putendl("chercheplace");

	g_c.tmp = g_c.c;
	while (g_c.tmp[g_c.i][g_c.j] != '.' && g_c.i < g_c.size && g_c.j <= g_c.size)
	{
		if (g_c.tmp[g_c.i][g_c.j] == '\0')
		{
				g_c.i++;
				g_c.j = 0;
		}
		else
			g_c.j++;
	}
	return (1);
}

/*
** Trouver comment Faire les ordres 
*/
//La boucle pour tester avec chaque ordre de pieces.
void	ft_testordre(t_lst *lst)
{
	ft_putendl("testordre");

	t_lst 	*tmplst;
	int 	i;
	int 	j;
	int 	k;

	k = 0;
	i = 0;
	tmplst = lst;
	while (i++ < ft_fact(g_c.len))
	{
		j = 1;	//Maybe commencer a 0 ?
		if (k == g_c.len)
			k = 0;
		while (j++ <= g_c.len && lst->ok == 0)
		{
			reso(lst);
			if (j == g_c.len)
				lst = tmplst;
			k++;
			lst->ok = 1;
			lst = lst->next;
		}
		ft_resetok(tmplst); //Pas sur de comment passer le 1st maillon sans changer tmplst
	}
}

/*
**Le main de resolution + initialisation des variables.
*/
int		mainres(t_lst *lst)
{
	ft_putendl("mainres");

	g_c.i = 0;
	g_c.j = 0;
	g_c.len = lenlst(lst);
									ft_putstr("g_c.len = ");
									ft_putnbrendl(g_c.len);
									ft_putendl("+4");
	g_c.taillemin = ft_sqrt(g_c.len * 4);
									ft_putstr("g_c.taillemin = ");
									ft_putnbrendl(g_c.taillemin);
									ft_putendl("+5");	
	g_c.size = g_c.taillemin;
	ft_initcube();
									ft_putendl("Cube de depart : ");
									ft_printcube();
									ft_putendl("+6");
	ft_resetok(lst);
	if (reso(lst))
	{
		ft_printcube();
		return (1);
	}
	return (0);
}
