/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/02/16 19:04:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include "libft.h"
#include <fcntl.h>


typedef struct 		s_lst
{
	int 			ok; 			//Si on a deja essayé de la placer.
	char			*piece; 		//La str de la piece 
	char			id; 			//La lettre
	struct s_lst	*next; 			//Le prochain maillon
}					t_lst;

//Le cube et ses index pour evier d'avoir a les passer en parametrs a chaque fois.
typedef struct 		s_cube
{
	char 			**c;
	char 			**tmp;
	int 			i;				//Index 1
	int 			j;				//Index 2
	int 			size; 			//La taille du cube
	int 			nbiter;
	int 			len; 			//La longueur de la lst;
	int 			taillemin; 		//LA taille minimum du cube;
	t_lst 			*firstma;		//Le premier maillon
}					t_cube;
t_cube				g_c;

//Pour ranger la forme la plus petite trouvee
typedef struct 		s_stock
{
	int		size;
	char	**bestcube;
}					t_stock;
t_stock				g_stock;

int		maincheck(char *av);
int 	checkforme(char *ligne);
int		check(char *av);
int 	checknl(char *lignenl);
int 	checkstartend(char *ligne, int *i, int nbl);
char 	*strreplace(char *str, char c, char d);
char	*instr(char	*av);
t_lst	*separe(char *str);
void	ft_rempid(t_lst *lst);
void	ft_resetok(t_lst *lst);
void	ft_isgud();
int 	ft_capasse(t_lst *lst);
int 	ft_chercheplace();
void	ft_testordre(t_lst *lst);
int		mainres(t_lst *lst);
int		lenlst(t_lst *lst);
#endif
