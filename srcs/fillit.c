/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/06 13:57:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		ok;
	int		fd;

	fd = 0;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit #FICHIER#");
		return (0);
	}
	ok = maincheck(av, fd);
	if (ok <= 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (!mainres())
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
