/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/09 06:09:15 by vmercadi         ###   ########.fr       */
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
void 	ft_printcube(char **str, int size)
{
	ft_putendl("printcube");
	int i;
	int j;
		ft_putnbrendl(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(str[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

/*
** Pour copier un tableau dans l'autre. b = dest
*/
/*
void	ft_cp(char **a, char **b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (a[i][j])
	{
		j = 0;
		while (a[i][j])
		{
			b[i][j] = a[i][j];
			j++;
		}
		i++;
	}
}
*/

/*
**Initialiation du cube et le rempli de points.
*/
char	**ft_initcube()
{
	ft_putendl("initcube");
	int i;
	int j;
	char **str;

	i = 0;
	str = (char **)malloc(sizeof(char *) * g_c.size);
	while (i < g_c.size)
	{
		str[i] = (char *)malloc(sizeof(char) * g_c.size);		
		i++;
	}
	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			str[i][j] = '.';
			j++;
		}
		i++;
	}
	ft_putendl("str");
//	ft_printcube(str, g_c.size);
	return (str);
}


/*
**	Pour copier les peices d'un cube a l'autre
*/
/*
void	ft_cpcube(char **str, char **dest, int size)
{
	ft_putendl("ft_cpcube***********************");
	int i;
	int j;

ft_putendl("AVANT1");
//ft_changecolor(RED);
ft_putendl("g_c.tmp");
ft_printcube(g_c.tmp, size);
ft_putendl("g_c.c");
ft_printcube(g_c.c, size);
//ft_resetcolor();

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{	
			if ((str[i][j] >= 'A' && str[i][j] <= 'Z') || str[i][j] == '.')						
				dest[i][j] = str[i][j];
			j++;
		}
		i++;
	}
ft_putendl("*** APRES");
ft_printcube(str, size);
ft_printcube(dest, size);
}
*/
/*
**Ajout d'une ligne au cube
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
					ft_putstr("CAPASSE j = ");
					ft_putnbrendl(g_c.j);	
	g_c.tmp = g_c.c;
	if (!lst)
		return (1);
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
									ft_putstrcolor("lst->ID = ", MAGENTA);
									ft_putcharendl(lst->id);
									ft_putstr("i = ");
									ft_putnbrendl(i + (k / 5));
									ft_putstr("j = ");
									ft_putnbrendl(j + (k % 5));
					ft_putstr("CAPASSE 2 g_c.j / j = ");
					ft_putnbr(g_c.j);
					ft_putnbrendl(j);
									ft_printcube(g_c.c, g_c.size);
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

	while (g_c.nbok < g_c.len) // avant <=
	{
									ft_printcube(g_c.tmp, g_c.size);
		ft_chercheplace(lst);
		ft_putstr("NB OK = ");
		ft_putnbrendl(g_c.nbok);
		if (ft_capasse(lst)) 		//Si la piece rentre on la place
		{
					ft_putendl("LA CEST PASSSEEEEEE");
			//lst->ok = 1;
			//g_c.nbok++;					//On incremente le nb de piece placees
			lst->ok = 1;
			g_c.nbok++;
			if (g_c.nbok == g_c.len)
				return (1);
			if (g_c.nbok < g_c.len)
			{
				lst = g_c.firstma;
				while (lst->ok != 0)
					lst = lst->next;
				if (reso(lst) == 0)
				{
					g_c.nbok--;
					rmpiece(lst);
					lst->ok = 0;
				}

			}
			lst = g_c.firstma;
		}
		if (lst->ok == 0)	
			rmpiece(lst);
		if (!lst->next && (g_c.i > g_c.size || g_c.j > g_c.size)) //Si y a plus d'autres maillons ni place
		{
					ft_putendl("IF + ONEMORE + RESET OK");
			ft_onemore();
			lst = g_c.firstma;
			ft_resetok(lst);
			g_c.i = 0;
			g_c.j = 0;
			g_c.nbok = 0;
		}
		else if (!lst->next)
		{
					ft_putendl("ELSE IF lst = firstma");
			if (g_c.j > g_c.size)
			{
					ft_putendl("ICI LA BOUCLE ");
				g_c.i++;
				g_c.j = 0;
			}
			else
				g_c.j++;
			lst = g_c.firstma;
		}
		else
		{
					ft_putendl("ELSE lst->next");
			lst = lst->next; 		//Sinon on passe à la prochaine piece
		}
	ft_isgudcube();
	return (1);
}

/*
** Avance dans le tableau jusqu'a la recherche d'un point
*/
int 	ft_chercheplace(t_lst *lst)
{
	ft_putendl("chercheplace");

	while (g_c.tmp[g_c.i][g_c.j] != '.' && g_c.i < g_c.size && g_c.j <= g_c.size)
	{
					ft_putendl("HAAAA");
					ft_putstr("g_c.i = ");
					ft_putnbrendl(g_c.i);
					ft_putstr("g_c.j = ");
					ft_putnbrendl(g_c.j);	
					ft_putstr("g_c.size = ");
					ft_putnbrendl(g_c.size);									
		if (g_c.tmp[g_c.i][g_c.j] == '\0' && g_c.i + 1 < g_c.size)
		{
					ft_putendl("HOOOO");
				g_c.i++;
				g_c.j = 0;
		}
		else if (g_c.j + 1 <= g_c.size)
		{
					ft_putendl("HIIIII");
			g_c.j++;
		}
		else if (g_c.i + 1 >= g_c.size && g_c.j >= g_c.size)
		{
			ft_onemore();
			lst = g_c.firstma;
			ft_resetok(lst);
			g_c.i = 0;
			g_c.j = 0;
			g_c.nbok = 0;
		}
	}
					ft_putendl("HEEEEE");

	return (1);
}

/*
** Trouver comment Faire les ordres 
*/
//La boucle pour tester avec chaque ordre de pieces.
/*
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
*/

/*
**Le main de resolution + initialisation des variables.
*/
int		mainres(t_lst *lst)
{
	ft_putendl("mainres");

	g_c.nbok = 0;
	g_c.i = 0;
	g_c.j = 0;
	g_c.len = lenlst(lst);
	g_c.taillemin = ft_sqrt(g_c.len * 4);
	g_c.size = g_c.taillemin;
							ft_putendl("g_c.c");
	g_c.c = ft_initcube();
							ft_putendl("CLEMENT");
							ft_printcube(g_c.c, g_c.size);
							ft_putendl("g_c.tmp");
	g_c.tmp = ft_initcube();
	//ft_printcube(g_c.tmp, g_c.size);
					ft_putstr("MAINRES j = ");
					ft_putnbrendl(g_c.j);
	ft_resetok(lst);
	if (reso(lst))
	{
		ft_printcube(g_c.c, g_c.size);
		return (1);
	}
	return (0);
}
