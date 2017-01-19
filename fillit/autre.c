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

//Sert a remplacer les les \n par des '.' pour tout mettre apres en une ligne
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

//Pour mettre tous les tetriminos dans une ligne
char	*daline(char *av)
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
	ligne[size + 1] = '\0';
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, 41)))
	{
		buf[ret] = '\0';
		ligne = ft_strjoin(ligne, buf);
	}
	return ((ligne = strreplace(ligne, '\n', '.')));
}
