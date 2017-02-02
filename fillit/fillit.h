/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:24:24 by vmercadi          #+#    #+#             */
/*   Created: 2017/01/17 03:24:24 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include "libft.h"
#include <fcntl.h>

//id = A ou B ou C, etc..
typedef struct 		s_lst
{
	int 			hauteur;
	int 			largeur;
	int 			ok;
	char			*piece;
	char			id;
	struct s_lst	*next;
}					t_lst;

//Le cube et ses index pour evier d'avoir a les passer en parametrs a chaque fois.
typedef struct 		s_cube
{
	char 			**c;
	int 			i;
	int 			j;
}					t_cube;

t_cube				g_cube;

//Pour ranger la forme la plus petite trouvee
typedef struct 		s_stock
{
	int		taille;
	char	**bestcube;
}					t_stock;

int 	checkforme(char *ligne);
int		check(char *av);
int		maincheck(char *av);
char 	*strreplace(char *str, char c, char d);
char	*instr(char	*av);
t_lst	*separe(char *str);

#endif
