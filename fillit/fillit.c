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
	mainres(&g_c.firstma);
	return (0);
}
