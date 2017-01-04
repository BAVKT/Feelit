/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 03:24:24 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/02 05:09:32 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"





/*

FAIT AU DEBUT

//On vérifie si les pieces passées sont valable
//PAs sur que les calculs soient bon, surtout avec un buffer de 2
int		check(char **av)
{
	int		i;
	int		pt;
	int		diez;
	int		fd;
	char 	s[2];

	pt = 0;
	diez = 0;
	fd = open(av[1], O_RDONLY);
	while ((i = read(fd, s, 1)))
	{
		s[i] = '\0';
		if ((pt + diez) / 4 == 0 && s[1] != '\n' && s[1] != '.' 
				&& pt + diez < 417 && s[1] != '#')
			return (0);
		else if (s[i] == '.')
			pt++;
		else if (s[i] == '#')
			diez++;
	}
	if (pt / diez == 3)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		ok;

	if (ac > 2 || ac < 2)
	{
		ft_putstr("usage : ./fillit #FICHIER#");
		return (0);
	}
	else
	{
		ok = check(av[1]);
		if (ok == 0)
			ft_putstr("Le fichier n'est pas valide.");
		else
			ft_fillit();
	}
}
*/