/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:13:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/03/08 05:56:16 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	res(t_lst *lst)
{
	t_lst *lst2;

	lst2 = &lst;
	while (lst)
	{
		while (lst->ok)
		{

		}
		ft_resetok(lst);
		lst = g_c.firstma;
	}
	lst = lst->next;
}


//Surement besoin en amont de la technique a double entree pour tester 
//tous les maillons dans chaque ordres.
int 	reso()
{
	int 	nbok; 	//Le nombre de pieces placées

	nbok = 0;
	while (nbok < g_c.len)
	{
		if (capasse(lst)) 			//Si la piece rentre
		{
			place(lst);				//On la place
			lst->ok = 1;
			nbok++; 				//On incremente le nb de piece placees
		}
		if (!lst->next) 			//Si y a plus d'autres maillons
		{
			ft_onemore();			//On agrandi le tableau
			lst = &g_c.firstma; 	//On retourne au debut de la liste.
		}
		else
			lst = lst->next; 		//Sinon on passe à la prochaine piece
	}
}
