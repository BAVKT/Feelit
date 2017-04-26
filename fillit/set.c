/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/24 18:19:20 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Defini le prev de chaque maillon de la liste
*/
void 	ft_setprev(t_lst *lst)
{
	t_lst 	*tmp;

	tmp = lst;
	while (lst->next)
	{
		lst = lst->next;
		lst->prev = tmp;
		tmp = lst;
	}
}

/*
** Fonction pour remplir l'ID de chaque piece
*/
void 	ft_rempid(t_lst *lst)
{
	ft_putendl("rempid");
	int 	i;

	i = 0;
	while(lst)
	{
		lst->id = 'A' + i;
		lst = lst->next;
		i++;
	}
}

/*
** Fonction pour reset le OK de chaque maillon a chaque test d'ordre
*/
void	ft_resetok(t_lst *lst)
{
	ft_putendl("resetok");
	while (lst)
	{
		lst->ok = 0;
		lst->nb = 0;
		lst = lst->next;
	}
}

/*
** Initialiation du cube et le rempli de points.
*/
char	**ft_initcube()
{
	ft_putendl("initcube");
	int i;
	int j;
	char **str;

	i = 0;
	str = (char **)malloc(sizeof(char *) * g_c.size);
	while (i < g_c.size)
	{
		str[i] = (char *)malloc(sizeof(char) * g_c.size);		
		i++;
	}
	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}
