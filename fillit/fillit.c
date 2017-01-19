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
	else
	{
		ok = maincheck(av[1]);
		if (ok == 0)
			ft_putstr("Le fichier n'est pas valide.\n");
		else
			ft_putstr("Le test1 est OK.\n");
	}
}
