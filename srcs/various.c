/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:44:03 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/06 17:47:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Incrementation
*/

int		incr(void)
{
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
}

/*
** Find the next . on the grid
*/

int		chercheplace(void)
{
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
** Replace \n by .
*/

char	*strreplace(char *str, char c, char d)
{
	int	i;

	i = 0;
	if (!str || !c || !d)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			str[i] = d;
		i++;
	}
	return (str);
}

/*
** Separate the pieces in the list
*/

t_lst	*separe(char *str)
{
	t_lst	*lst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->next = NULL;
	lst->piece = ft_strnew(21);
	while (str[i])
	{
		if (!g_c.firstma)
			g_c.firstma = lst;
		if (j == 19 && i > 0 && i < (int)ft_strlen(str) - 19)
		{
			j = 0;
			i++;
			lst = initlst(lst);
		}
		else
			lst->piece[j++] = str[i];
		i++;
	}
	return (g_c.firstma);
}
