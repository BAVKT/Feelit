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
//Reste a trouver pourquoi il accepte pas mon malloc ce gros batard
//Puis a enregistrer l'adresse du premier maillon
//Puis a tester le tout.
t_lst	*separe(char *str)
{
	t_lst 	*lst;
	int 	i;
	int 	j;
	int 	nbl;

ft_putendl("On passe ici");
	i = 0;
	nbl = 1;
	lst = (t_lst *)malloc(sizeof(t_lst));
	while (str[i++])
	{
		ft_putendl("NBL INFERIEUR  A 4");
		if (str[i] == '\n')
			nbl++;
		if (nbl == 1)
			lst->piece = (char *)malloc(sizeof((char) * (16)));
		else if (nbl > 4)
		{
		ft_putendl("NBL > 4");
			nbl = 1;
			lst->piece[j] = '\0';
			j = 0;
			lst = lst->next;
		}
		else
			lst->piece[j++] = str[i];
	}
	ft_putendl("On passe a la fin");
	return (lst);
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
