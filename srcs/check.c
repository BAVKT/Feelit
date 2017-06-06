/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/06 17:47:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if the number of \n is ok
*/

int		checknl(char *lignenl)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (lignenl[i])
	{
		if (lignenl[i] == '\n' && lignenl[i + 1] == '\n' && k < 19)
			return (0);
		if (k == 19)
		{
			if (lignenl[i + 1] != '\n' && lignenl[i + 1] != '\0')
				return (0);
			k = -2;
		}
		if (lignenl[i] == '\n' && lignenl[i + 1] == '\n'
			&& lignenl[i + 2] == '\n')
			return (0);
		i++;
		k++;
	}
	if (lignenl[i - 1] == '\n' && lignenl[i - 2] == '\n')
		return (0);
	return (1);
}

/*
** Special check for the first and last lines
*/

int		checkstartend(char *ligne, int *i, int nbl)
{
	if (*i > 1 && nbl == 1)
	{
		if (ligne[*i - 1] == '#'
			|| ligne[*i + 1] == '#'
			|| ligne[*i + 5] == '#')
			return (1);
		else
			return (0);
	}
	if (*i < (int)ft_strlen(ligne) && nbl == 4)
	{
		if (ligne[*i - 1] == '#'
			|| ligne[*i + 1] == '#'
			|| ligne[*i - 5] == '#')
			return (1);
		else
			return (0);
	}
	return (1);
}

/*
** Check if tetrimino is valid
*/

int		checkforme(char *ligne)
{
	int	i;
	int	nbl;
	int	ok;

	i = 0;
	nbl = 1;
	ok = 1;
	while (ligne[i])
	{
		if ((ligne[i] == '#' && (ok = checkstartend(ligne, &i, nbl))
			&& (nbl == 1 || nbl == 4)) || (ligne[i] == '.'))
			;
		else if (ligne[i] == '\n')
			ligne[i - 1] == '\n' ? nbl = 1 : nbl++;
		else if (ligne[i - 1] == '#' || ligne[i + 1] == '#' ||
				ligne[i + 5] == '#' || ligne[i - 5] == '#')
			;
		else
			return (0);
		i++;
		if (ok == 0)
			return (0);
	}
	return (1);
}

/*
** Check if there is only . and #
*/

int		check(char *lignenl)
{
	int	i;
	int	pt;
	int	diez;

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
	if (i < 19 || diez <= 0)
		return (0);
	return ((pt / diez == 3 && pt % diez == 0) ? 1 : 0);
}

/*
** Main chek
*/

int		maincheck(char **av, int fd)
{
	int		ok;
	int		nb;
	char	*ligne;
	char	buf[42];
	t_lst	*lst;

	nb = 42;
	fd = open(av[1], O_RDONLY);
	ok = read(fd, buf, nb);
	if (ok == -1)
		return (-1);
	ligne = ft_file_to_str(av[1]);
	if (!ligne)
		return (-1);
	if ((ok = check(ligne)))
	{
		if ((ok = checknl(ligne)))
		{
			lst = separe(ligne);
			g_c.firstma = lst;
			if ((ok = checkforme(ligne)))
				return (1);
		}
	}
	return (0);
}
