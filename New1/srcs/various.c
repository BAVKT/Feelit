/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:44:03 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/30 16:18:36 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

/*
** Incremente dans les indexs i et j comme il faut
*/
/*int 	incr()
{
		ft_putendl("incr");
	if (g_c.i + 1 >= g_c.size && g_c.j >= g_c.size)
		return (0);
	else if (g_c.j + 1 <= g_c.size)
		g_c.j++;
	else
	{	
		g_c.i++;
		g_c.j = 0;
	}
	return (1);
}*/

/*
** Incremente dans les indexs i et j comme il faut
*/
int 	incr()
{
	//ft_putendl("ft_incr");
		//ft_putstr("g_c.taille = ");
		//ft_putnbrendl(g_c.size);
		//ft_putstr("g_c.i = ");
		//ft_putnbrendl(g_c.i);
		//ft_putstr("g_c.j = ");
		//ft_putnbrendl(g_c.j);
	if (g_c.i + 1 >= g_c.size && g_c.j >= g_c.size)
	{
				//ft_putendl("YAGYAGYAGYA");
		//g_c.i = 0;
		//g_c.j = 0;
		return (0);
	}
	else if (g_c.j + 1 <= g_c.size)
	{
					//ft_putendl("YUGYUGYUGYU");	
		g_c.j++;
	}
	else
	{
					//ft_putendl("YOGYOGYOGYO");	
		g_c.i++;
		g_c.j = 0;
	}
	//	ft_putstr("g_c.i = ");
	//	ft_putnbrendl(g_c.i);
	//	ft_putstr("g_c.j = ");
	//	ft_putnbrendl(g_c.j);
	return (1);
}

/*
** Avance dans le tableau jusqu'a la recherche d'un point
*/
int 	chercheplace()
{
	ft_putendl("chercheplace");

	while (g_c.c[g_c.i][g_c.j] != '.' && g_c.i < g_c.size && g_c.j <= g_c.size)
	{
		if (!incr())
			break ;
	}
	if (g_c.c[g_c.i][g_c.j] != '.')
	{
		g_c.i = 0;
		g_c.j = 0;
		return (0);
	}
	return (1);
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
** Sert à remplacer les \n par des '.' pour tout mettre apres en une ligne
*/
char 	*strreplace(char *str, char c, char d)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = d;
		i++;
	}
	return (str);
}

/*
** Place chaque pièces dans la str de la liste.
*/
t_lst	*separe(char *str)
{
		ft_putendl("separe");
	t_lst	*lst;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->next = NULL;
	lst->piece = ft_strnew(21);
	while(str[i])
	{
		if (!g_c.firstma)
			g_c.firstma = lst;
		if (j == 19 && i > 0 && i < (int)ft_strlen(str) - 19)
		{
			j = 0;
			i++;
			if ((lst->next = (t_lst *)malloc(sizeof(t_lst))))
			{
				lst = lst->next;
				lst->next = NULL;
				lst->piece = ft_strnew(21);
			}
		}
		else
			lst->piece[j++] = str[i];
		i++;
	}
	return (g_c.firstma);
}

/*
** Décale les tetris le plus en haut a gauche possible de leur piece
*/
/*void	movit(t_lst *lst)
{
	ft_putendl("movit");

	int		i;	
	int		j;

					ft_putendl("LST->PIECE");
					ft_putendl(lst->piece);
	i = 0;
	j = 0;
	while (lst->piece[i] != '#')
		i++;
	while (lst->piece[j + i])
	{
		if (lst->piece[j + i] == '#')
		{
			lst->piece[j] = lst->piece[j + i];
			lst->piece[j + i] = '.';
				//ft_putstr("j     = ");
				//ft_putcharendl(lst->piece[j]);
				//ft_putstr("i + j = ");
				//ft_putcharendl(lst->piece[j + i]);
		}
		j++;
	}
					//ft_putendl("TMP");
			 		//ft_putendl(tmp);
					ft_putendl("LST->PIECE APRES");
					ft_putendl(lst->piece);
}
*/


//void	movit(t_lst *lst)
//{
//		ft_putendl("movit");
//			ft_putendl("lst->piece AVANT");
//			ft_putendl(lst->piece);
//	int		i;
//	int		j;
//	int		k;
//	char	**str;
//	
//	i = 0;
//	j = 0;
//	str = ft_strsplit(lst->piece, '\n');
//	while (lst->piece[i] != '#')
//	{
//		if (lst->piece[i] == '\n')
//		{
//			j++;
//			j = 0;
//		}
//		i++;
//	}
//		printcube(str);
//	str = toup(i, str);
//		printcube(str);
//	str = toleft(j, str);
//				ft_putendl("yas");
//	i = 0;
//	j = 0;
//	k = 0;
//	while (str[i][j])
//	{
//		while(str[i][j])
//		{
//			lst->piece[k++] = str[i][j];
//			j++;
//		}
//		j = 0;
//		i++;
//	}			ft_putendl("lst->piece APRES");
//			ft_putendl(lst->piece);
//}

//0 = ligne   1 = colonnes

int		*checkmovit(t_lst *lst)
{
		ft_putendl("checkmovit");

	int 	i;
	int		*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 0;
	while (lst->piece[i] != '#')
	{
		if (lst->piece[i] == '\n')
			tab[0]++;
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (lst->piece[i] == '.' && lst->piece[i + 5] == '.' && 
			lst->piece[i + 10] == '.' && lst->piece[i + 15] == '.')
			tab[1]+=1;
		else
			break ;
		i++;
	}
	return (tab);
}


/*
** Décale les tetris le plus en haut a gauche possible de leur piece
*/
void	movit(t_lst *lst)
{
	//	ft_putendl("movit");
	int		*tab;
	int		i;	
	int		j;
	int		k;
	char	*tmp;

		ft_putendl("AVANT");
		ft_putendl(lst->piece);
	i = 0;
	j = 0;
	k = 0;
	tab = checkmovit(lst);
	ft_putendl("yo");
	ft_putnbrendl(tab[0]);
	ft_putnbrendl(tab[1]);
	if (tab[0] == 0 && tab[1] == 0)
		return ;
	tmp = ft_strnew(21);
	i += 5 * tab[0];
	while (lst->piece[i])
	{
		if (i % 5 == 0)
			i += tab[1];
		else if (lst->piece[i] == '\n')
		{
			while (k++ < tab[1])
				tmp[j++] = '.';
			k = 0;
			tmp[j] = '\n';
		}
		tmp[j++] = lst->piece[i++];
	}
	if (tmp[j - 1] != '\n')	
		tmp[j++] = '\n';
	while (tab[0]-- != 0)
		ft_strcat(tmp, "....\n");
	i = 0;
	while (i < 18)
		i++;
	while (tmp[i] != '.')
		tmp[i--] = '.';
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			tmp[i] = '\0';
		i++;	
	}
	//ft_putnbrendl(i);
	lst->piece = tmp;
	ft_putendl("APRES");
	ft_putendl(lst->piece);
	i = 0;
	while (tmp[i])
	{
		ft_putnbrendl(tmp[i]);
		i++;
	}
}


////Test d'un autre movit
//void	movetop(t_lst *lst)
//{
//	int		i;
//	int		j;
//	int		*tab;
//	char	*tmp;
//
//	j = 0;
//	i = 0;
//	tab = checkmovit(lst);		
//	tmp = ft_strnew(21);
//	i += 5 * tab[0];
//	while (lst->piece[i])
//		tmp[j++] = lst->piece[i++];
//	if (tmp[j - 1] != '\n')	
//		tmp[j++] = '\n';
//	while (tab[0]-- != 0)
//		ft_strcat(tmp, "....\n");
//	lst->piece = tmp;
//}
//
//void	moveleft(t_lst *lst)
//{
//	int		i;
//	int		j;
//	int		k;
//	int		*tab;
//	char	*tmp;
//
//	j = 0;
//	k = 0;
//	tab = checkmovit(lst);
//	tmp = ft_strnew(21);	
//	while (j < 3)
//	{
//		i = 0;
//		while (i < tab[1])
//		{
//			tmp[k] = lst->piece[i + tab[1]];
//			i++;
//			k++;
//		}
//		j++;
//	}
//	i = 0;
//	while (i + tab[1] < 3)
//	{
//		tmp[k] = '.';
//		i++;
//		k++;
//	}
//	lst->piece = tmp;
//}
//
/*
void	movit(t_lst *lst)
{
		ft_putendl("AVANT");
		ft_putendl(lst->piece);
		movetop(lst);
		moveleft(lst);
		ft_putendl("APRES");
		ft_putendl(lst->piece);
}
*/	






