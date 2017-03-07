/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/06 21:42:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		ok;

	if (ac != 2)
	{
		ft_putstrcolor("usage : ./fillit #FICHIER#", YELLOW);
		return (0);
	}
	if ((ok = maincheck(av[1])))
		ft_putstrcolor("The file seems OK.", GREEN_BOLD);
	else
	{
		ft_putstrcolor("ERROR : The file isn't well formatted.", RED_BOLD);
		return (0);
	}
	if (mainres(g_c.firstma))
		ft_putstrcolor("SUCCESS", GREEN_BOLD);
	else
		ft_putstrcolor("Echec critique !", RED_BOLD);

	return (0);
}
