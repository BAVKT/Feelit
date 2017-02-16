/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/02/15 17:11:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		ok;

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit #FICHIER#");
		return (0);
	}
	if ((ok = maincheck(av[1])))
		ft_putstr("The file seems OK.\n");
	else
		ft_putstr("ERROR : The file isn't well formatted.\n");
	mainres(g_c.firstma);
	return (0);
}
