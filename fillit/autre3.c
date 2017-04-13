/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:20:38 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/06 17:46:00 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Pour effacer la piece dans le tmp si elle est rentree qu'en pqrtie ou pas du tout.
*/
void	rmpiece(t_lst *lst)
{
	ft_putendl("rmpiece");

	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			if (g_c.tmp[i][j] == lst->id)
				g_c.tmp[i][j] = '.';
			j++;
		}
		i++;
	}
}


