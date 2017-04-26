/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/26 16:11:02 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check si les pieces sont bien séparées par un seul \n
*/
int 	checknl(char *lignenl)
{
	int 	i;
	i = 0;
	while (lignenl[i++])
	{
		while (lignenl[i])
		{	//On vérifie juste qu'il y ait pas + de 3 nl a la suite
			if (lignenl[i] == '\n' && lignenl[i + 1] == '\n' && lignenl[i + 2] == '\n')		
				return (0);
			i++;
		}
	}
	return (1);
}

/*
** Check special pour les premieres et dernieres lignes (RIP la chair a canon)
*/
int 	checkstartend(char *ligne, int *i, int nbl)
{
	ft_putendl("checkstartend");
	if (*i > 1 && nbl == 1)
	{	//Check pour la premiere ligne (on enleve le check de la piece du dessus parce qu'il y en aura jamais)
		if (ligne[*i - 1] == '#' || ligne[*i + 1] == '#' || ligne[*i + 5] == '#')
			return (1);
		else
		{
			ft_putstr("01 - carac : ");
			ft_putnbrendl(*i);
			return (0);
		}
	}
	else if (i < (int *)ft_strlen(ligne) && nbl == 4)
	{	//Check pour la dernieres ligne (on enleve le check de la piece du dessous pour la meme raison)
		if (ligne[*i - 1] == '#' || ligne[*i + 1] == '#' || ligne[*i - 5] == '#')
			return (1);
		else
		{
			ft_putstr("02 - caracterre : ");
			ft_putnbrendl(*i);
			return (0);
		}
	}
	return (1);
}

/*
** Check si les tetriminos n'ont pas de malformations physiques parce qu'on veut pas d'handicapés 
*/
int 	checkforme(char *ligne)
{
	ft_putendl("checkforme");
	int 	i;
	int 	nbl;	//Nombre de ligne
	int		ok;

	i = 0;
	nbl = 1;
	ok = 1;
	while (ligne[i])
	{
		if (ligne[i] == '#' && (ok = checkstartend(ligne, &i, nbl))
			 && (nbl == 1 || nbl == 4))
			i++;
		else if (ligne[i] == '.')
			i++;
		else if (ligne[i] == '\n')
		{
			ligne[i - 1] == '\n' ? nbl = 1 : nbl++;
			i++;
		}
		else if (ligne[i - 1] == '#' || ligne[i + 1] == '#' || 
				ligne[i + 5] == '#' || ligne[i - 5] == '#')
			i++;
		if (ok == 0) 	//On verifie que ok soit toujours = 1 sinon ca veut dire qu'il y a erreur
			return (0);
	}
	return (1);
}

/*
** Check si il y a bien que des diezs et des points et en bon nombre parce qu'on est raciste du reste
*/
int		check(char *lignenl)
{
	int		i;
	int		pt;
	int		diez;

	i = 0;
	pt = 0;
	diez = 0;
	while (lignenl[i] != '\0') 
	{
		if (lignenl[i] != '\n' && lignenl[i] != '.' && lignenl[i] != '#')
			return (0);
		if (((pt + diez) / 4 == 0 && lignenl[i] != '\n' && lignenl[i] != '.' 
			 && lignenl[i] != '#') || pt + diez > 417)
			return (0);
		if (lignenl[i] == '.')
			pt++;
		else if (lignenl[i] == '#')
			diez++;
		i++;
	}
	if (i < 19)
		return (0);
	return ((pt / diez == 3 && pt % diez == 0) ? 1 : 0);
}

/*
** Le main qui execute les checks
*/
int		maincheck(char **av, int fd)
{
	int 	ok;
	int 	nb;
	char 	*ligne;
	char 	buf[42];
	t_lst 	*lst;

	nb = 42;
	fd = open(av[1], O_RDONLY);
	ok = read(fd, buf, nb);
	if (ok == -1)
		return (-1);
	ligne = instr(av[1]);
	if (!ligne)
		return (-1);
	if ((ok = check(ligne)))
	{
	
		if ((ok = checknl(ligne)))
		{
			lst = separe(ligne);
			ft_rempid(g_c.firstma);
			g_c.firstma = lst;
			if ((ok = checkforme(ligne)))
				return (1);
		}
	}
	return (0);
}
