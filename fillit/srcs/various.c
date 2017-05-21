/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:44:03 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/21 22:24:39 by vmercadi         ###   ########.fr       */
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
** Met l'ensemble des pièces dans une str AVEC les \n
*/
char	*instr(char	*av)
{
	int		fd;
	int 	ret;
	int 	size;
	char 	buf[42];
	char 	*ligne;

	size = 0;
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, 41)))
	{
		buf[ret] = '\0';
		size += ret;
	}
	close(fd);
	ligne = (char *)malloc(sizeof(char) * (size + 1));
	ligne[size] = '\0';
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, 41)))
	{
		buf[ret] = '\0';
		ligne = ft_strjoin(ligne, buf);
	}
	close(fd);
	return (ligne);
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
	t_lst	*lst;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->next = NULL;
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
			}
		}
		else
			lst->piece[j++] = str[i];
		i++;
	}
	return (g_c.firstma);
}

/*
** check pour decaler les pieces en haut a gauche
** tab[0] = ligne;		tab[1] = colonnes;
*/
int		*checkmovit(t_lst *lst)
{
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
			tab[1]++;
		i++;
	}
	return (tab);
}

/*
** Décale les tetris le plus en haut a gauche possible de leur piece
*/
void	movit(t_lst *lst)
{
	int		*tab;
	int		i;	
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = 0;
	k = 0;
	tab = checkmovit(lst);
	tmp = ft_strnew(ft_strlen(lst->piece));
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
	while (tab[0]-- != 0)
		ft_strcat(tmp, "....\n");
	i = 0;
		ft_putendl("NIKETAMERE");
	while (tmp[i])
	{
			ft_putcharendl(tmp[i]);
		if (tmp[i] == '#')
			lst->piece[i] = '#';
		else if (i % 5 == 0)
			lst->piece[i] = '\n';
		else
			lst->piece[i] = '.';
		i++;
	}
		ft_putendl("piece = ");
		ft_putendl(lst->piece);
		ft_putendl("---------");
		ft_putendl("tmp");
		ft_putendl(tmp);
}
