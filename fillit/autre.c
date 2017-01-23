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

/*
** Place chaque pièces dans la str de la liste.
*/
t_lst	*separe(char *str)
{
	t_lst	*lst;
	t_lst 	*tmp;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	lst = (t_lst *)malloc(sizeof(t_lst));
	tmp = lst;
	lst->piece = ft_strnew(21);
	while(str[i])
	{
		if (j == 19 && i > 0)
		{
			j = 0;
			i++;
			lst->next = (t_lst *)malloc(sizeof(t_lst));
			lst = lst->next;
			lst->piece = ft_strnew(21);
		}
		else
			lst->piece[j++] = str[i];
		i++;
	}
	return (tmp);
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
	ligne[size + 1] = '\0';
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
