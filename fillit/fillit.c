/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/08 05:56:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		ok;
	int		fd;

	fd = 0;
	if (ac != 2)
	{
		ft_putstrcolor("usage : ./fillit #FICHIER#", YELLOW);
		return (0);
	}
	ok = maincheck(av, fd);
	if (ok == 1)
		ft_putstrcolor("The file seems OK.", GREEN_BOLD);
	else if (ok == 0)
		ft_putstrcolor("ERROR : The file isn't well formatted.", RED_BOLD);
	else if (ok == -1)
		ft_putstrcolor("You have to give me a valid file.", RED_BOLD);
	if (ok == -1)
		return (0);
	if (mainres(g_c.firstma))
		ft_putstrcolor("SUCCESS", GREEN_BOLD);
	else
		ft_putstrcolor("Echec critique !", RED_BOLD);
	return (0);
}
