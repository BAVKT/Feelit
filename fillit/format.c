/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/02/16 19:02:25 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


#include <stdio.h>
/*
**
** PEUT ETRE QU'IL FAUT METTRE DES POINTS A LA PLACE DES FLECHES
** OU INVERSEMENT COMME ON PASSE UN MAILLON DE LA STRUCT
**
*/

//Fonction de racine carré
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
	if (prime == nb)
		return (i);
	else
		return (i + 1);
}

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

//Initialiation du cube et le rempli de points.
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

	//ft_printcubetmp();
	ft_addpoint();
	//ft_printcubetmp();
	if (g_c.tmp)
	{
					ft_putendl("1");
		i = 0;
		while (i < g_c.size - 1)
		{
					ft_putstr("i");
					ft_putnbrendl(i);
			j = 0;
			while (j < g_c.size - 1)
			{
					ft_putstr("j");
					ft_putnbrendl(j);
				g_c.c[i][j] = g_c.tmp[i][j];
				j++;
			}
			i++;
		}
		ft_printcubetmp();
		ft_putstr(" initcube");
	}

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

//Pour tester si le cube est mieux que celui deja enregistré et l'enregistrer.
void	ft_isgudcube()
{
	ft_putendl("isgudcube");
	if (g_c.size >= g_stock.size)
		return ;
	g_stock.size = g_c.size;
	g_stock.bestcube = g_c.tmp;
}

//Pour enregistrer la piece dans le cube si elle rentre.
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

//Trouver comemnt calculer l'index l'index J
//Check si la piece rentre et la met dans cube si c'est bon
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
	nb = 1;
	i = g_c.i;
	j = g_c.j;
	g_c.tmp = g_c.c;
	while (lst->piece[l] != '#')
		l++;
	while (lst->piece[k + l] || nb == 4)
	{
														ft_putstr("piece[k + l] = ");
														ft_putchar(lst->piece[k + l]);
														ft_putchar('\n');
														ft_putstr("k + l = ");
														ft_putnbrendl(k + l);
														ft_putstr("k = ");
														ft_putnbrendl(k);
														ft_putstr("l = ");
														ft_putnbrendl(l);
		if (lst->piece[k + l] == '#')
		{
														ft_putendl("ON PASSE ICI");
														ft_putstr("AVANT g_c.tmp[i][j] = ");
														ft_putchar(g_c.tmp[i + (k / 6)][j + (k % 5)]);
														ft_putchar('\n');
														ft_putstr("[i + (k / 6)] = ");
														ft_putnbr(i + (k / 6));
														ft_putchar('\n');
														ft_putstr("[j + (k mod 5)] = ");
														ft_putnbr(j + (k % 5));
														ft_putchar('\n');
			if (!g_c.tmp[i + (k  / 6)][j + (k % 5)])
				return(0);
			if (g_c.tmp[i + (k / 6)][j + (k % 5)] == '.')
				g_c.tmp[i + (k / 6)][j + (k % 5)] = '#';	//Pas sur des indexs
			nb++;
														ft_putstr("i = ");
														ft_putnbrendl(i);	
														ft_putstr("j = ");
														ft_putnbrendl(j);	
														ft_putstr("k = ");
														ft_putnbrendl(k);
														ft_putstr("l = ");
														ft_putnbrendl(l);	
														ft_putstr("APRES g_c.tmp[i][j] = ");
														ft_putchar(g_c.tmp[i + (k / 6)][j + (k % 5)]);
														ft_putchar('\n');
														ft_printcubetmp();
														ft_putstr("nb = ");
														ft_putnbrendl(nb);
		}
		k++;
	}
	if (nb == 4)
	{
									ft_putendl("ON EST DANS NB == 4");
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
			lst->ok = 1;
			nbok++; 				//On incremente le nb de piece placees
		}
		if (!lst->next) 			//Si y a plus d'autres maillons
		{
			ft_onemore();			//On agrandi le tableau
			lst = g_c.firstma; 		//On retourne au debut de la liste.
						ft_putendl("reso/Adresse firstma = ");
						printf("%p\n", g_c.firstma);
		}
		else
			lst = lst->next; 		//Sinon on passe à la prochaine piece
		g_c.i++;
		g_c.j++;
	}
	ft_isgudcube();
	return (1);
}

//Avance dans le tableau jusqu'a la recherche d'un point
int 	ft_chercheplace()
{
	ft_putendl("chercheplace");
	g_c.tmp = g_c.c;
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
	
/*
	//Peut etre besoin de faire une incrementation de j pour pas boucler sur le meme point
	if (ft_capasse(lst) == 0 && g_c.j != g_c.size - 1 && lst->ok == 0)	//On rappelle tant qu'on sait pas 
		ft_capasse((lst = lst->next));
	ft_resetok();
	if (ft_capasse(lst) == 0 && g_c.j != g_c.size - 1 && lst->ok == 1)	//On rappelle tant qu'on sait pas 
		ft_chercheplace((lst = lst->next));
	if (g_c.j == g_c.size - 1)	//Si on est a la fin du cube
		ft_onemore();
	return(1);
*/
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
		ft_resetok(tmplst);//Pas sur de comment passer le 1st maillon sans changer tmplst
	}
}

//Le main de resolution + initialisation des variables.
int		mainres(t_lst *lst)
{
	ft_putendl("mainres");

									ft_putendl("+1");
	g_c.i = 0;
									ft_putendl("+2");
	g_c.j = 0;
									ft_putendl("+3");
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
		return (1);
	return (0);
}













