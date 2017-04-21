/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actioncube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:18:25 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/21 19:50:50 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Quand on arrive pas a rentrer la piece dans le cube
** Retire la piece actuelle et celle d'avant et avance d'une piece
*/
/*
void	ft_fail()
{
				ft_putendl("ft_fail");
										ft_putendl("RESOPLAC A ECHOUE DAMN");
	//g_c.nbok--;
				ft_putnbr(g_c.nbok);
				ft_putstr(" id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
	rmpiece(g_c.lst);
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
				ft_putnbr(g_c.nbok);
				ft_putstr(" id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
	rmpiece(g_c.lst);
	g_c.nbok--;
	g_c.lst->ok = 0;
	g_c.lst->nb = 0;
	g_c.lst = ft_incrlst(g_c.lst);
	g_c.i = 0;
	g_c.j = 0;
}*/
/*
void	ft_rmlastok()
{
		ft_putendl("ft_tmlastok");
	t_lst *tmp;

	tmp = g_c.lst;
	while(g_c.lst->id != g_c.last)
	{
		g_c.nbok--;
		rmpiece(g_c.lst);
		g_c.lst->ok = 0;
		g_c.lst->nb = 0;
		g_c.lst = ft_incrlst(g_c.lst);	
	}
}
*/

/*
** Pour savoir si il reste des pièces non posées après la piece actuelle
*/
/*
int		ft_lastok()
{
				ft_putendl("ft_lastok");
	t_lst *tmp;

	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
	tmp = g_c.lst;
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
	while (g_c.lst->ok == 1 && g_c.lst->id != 'A' + g_c.len - 1)
	{
				ft_putendl("hooo");
		if (!g_c.lst->next)
		{
			g_c.lst = tmp;
			return (1);
		}
		g_c.lst = g_c.lst->next;
	}
				ft_putstr("g_c.lst->id2 = ");
				ft_putcharendl(g_c.lst->id);
	if (g_c.lst->ok == 0)
	{
				ft_putendl("lol nope");
		g_c.lst = tmp;
		return(0);
	}
		g_c.lst = tmp;
				ft_putendl("YEAH");
	return (1);
}
*/

int		ft_cmpalpha(char *s)
{
				ft_putendl("ft_cmpalpha");
	t_lstalpha	*tmp;

	tmp = g_c.firstalpha;
	while (tmp)
	{
					ft_putstr("tmp->str = ");
					ft_putendl(tmp->str);
					ft_putstr("s = ");
					ft_putendl(s);
					ft_putnbrendl(ft_strcmp(tmp->str, s));
		if (ft_strcmp(tmp->str, s) == 0)	//Si il existe deja
			return (1);
		if (tmp->next)
		{
					ft_putendl("AOHOHOHOHOH");
			tmp = tmp->next;
		}
		else
			break ;
					ft_putendl("HAAAASDASDASD");
	}
	g_c.alpha->str = ft_strdup((const char *)s);
	g_c.alpha->next = NULL;
	g_c.alpha = g_c.alpha->next;
	return (0);
}

int 	ft_rempalpha()
{
					ft_putendl("ft_rempalpha");	
	t_lst	*tmp;
	char	*s;
	int		i;

	i = 0;
	tmp = g_c.firstma;
	g_c.alpha = g_c.firstalpha;
	while (g_c.alpha->next)
	{
					ft_putendl("yo");
					ft_putendl(g_c.alpha->str);
		g_c.alpha = g_c.alpha->next;
	}
	if ((g_c.alpha->next = (t_lstalpha *)malloc(sizeof(t_lstalpha))))
	{
					ft_putendl("rrrr");
		s = (char *)malloc(sizeof(char) * g_c.nbok + 1);
		while (i <= g_c.nbok)
		{
			s[i] = tmp->id;
			i++;
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		s[i] = '\0';
		if (ft_cmpalpha(s) == 0)
		{
			free(s);
			return (1);
		}
		free(s);
	}
	return (0);
}

void	ft_fail()
{
			ft_putendl("ft_fail");
	int			ok;

	ok = g_c.nbok;
	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putstr("g_c.lst->id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
	if (g_c.lst->ok == 1)
	{
		g_c.nbok--;
		rmpiece(g_c.lst);
		g_c.lst->ok = 0;
		g_c.lst->nb = 0;
	}
/*
	g_c.lst = g_c.firstma;
	while (g_c.lst->nb != g_c.nbok)
		g_c.lst = g_c.lst->next;
*/
	if (g_c.lst->id == 'A' + g_c.len - 1)
	{
		g_c.lst = g_c.firstma;
		while (g_c.lst->nb != g_c.nbok)
		{
				ft_putstr("g_c.lst->id = ");
				ft_putchar(g_c.lst->id);
				ft_putnbrendl(g_c.lst->nb);
			g_c.lst = g_c.lst->next;
		}
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putstr("g_c.lst->nb = ");
				ft_putnbrendl(g_c.lst->nb);
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
		rmpiece(g_c.lst);
		g_c.nbok--;
		g_c.lst->ok = 0;
		g_c.lst->nb = 0;
	}
	if (g_c.lst->next /*&& g_c.nbok > 0*/)
		g_c.lst = g_c.lst->next;
	if (g_c.lst->ok != 0)
		g_c.lst = ft_incrlst(g_c.lst);
	g_c.i = 0;
	g_c.j = 0;
				ft_putstr("g_c.nbok = ");
				ft_putnbrendl(g_c.nbok);
				ft_putstr("g_c.lst->nb = ");
				ft_putnbrendl(g_c.lst->nb);
				ft_putstr("g_c.lst->id = ");
				ft_putcharendl(g_c.lst->id);
}

/*
** Affichage du cube
*/
void 	ft_printcube(char **str, int size)
{
	ft_putendl("printcube");
	int i;
	
		ft_putnbrendl(size);
	i = 0;
	while (i < size)
	{
		ft_putendl(str[i]);
		//ft_putstrcolor(str[i], CYAN);
		i++;
	}
}

/*
** Ajout d'une ligne au cube
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
** Pour tester si le cube est mieux que celui deja enregistré et l'enregistrer.
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
** Pour enregistrer la piece dans le cube si elle rentre.
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
	g_c.lst->ok = 1;
	g_c.nbok++;
	g_c.lst->nb = g_c.nbok;
	g_c.i = 0;
	g_c.j = 0;
					ft_printcube(g_c.c, g_c.size);
}
