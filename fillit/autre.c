/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:08 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/12 17:16:35 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/*
**	Met les pieces le plus en haut à gauche dans lst->piece 
*/
/*
MARCHE PAS 
void 	upleft(t_lst *lst)
{
	int i;		//Index dans la piece 
	int l; 		//la ligne en y 
	int k; 		//nombre de diezs

	i = 0;
	l = 1;
	k = 0;
	while (lst->piece[i])
	{
		if (lst->piece[i] == '#')
		{
			lst->piece[(i % l) + k] = '#';
			lst->piece[i] = '.';
			k++;
			i++;
		}
		else if (lst->piece[i] == '\n')
		{
			if (k != 0)
				l++;
			k = 0;
			i++;
		}
		i++;
	}
}
*/

/*
**Len lst modified
*/
int		lenlst(t_lst *lst)
{
	int nb;

	nb = 1; 				//Valeur passée a 1 au lieu de 0
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
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
