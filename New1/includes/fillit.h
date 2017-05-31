/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:10:59 by vmercadi          #+#    #+#             */
/*   Updated: 2017/05/30 18:24:55 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include "libft.h"

typedef struct 		s_lst
{
	int 			nb;				//Le numero de l'ordre auquel il a ete posé
	char			*piece; 		//La str de la piece 
	char			id; 			//La lettre
	struct s_lst	*next; 			//Le prochain maillon
	struct s_lst 	*prev;			//Le precedent maillon
}					t_lst;

typedef struct 		s_cube
{
	char 			**c;
	char 			**tmp;
	char			last;			//Lettre du dernier maillon
	int 			i;				//Index 1
	int 			j;				//Index 2
	int 			size; 			//La taille du cube
	int 			nbpiece; 		//La longueur de la lst;
	int 			taillemin; 		//La taille minimum du cube;
	int 			nbok;
	t_lst			*lst; 			//Le maillon en cours
	t_lst 			*firstma;		//Le premier maillon
}					t_cube;
t_cube				g_c;

int 	checknl(char *lignenl);
int 	checkstartend(char *ligne, int *i, int nbl);
int 	checkforme(char *ligne);
int		check(char *lignenl);
int		maincheck(char **av, int fd);
int		mainres(void);
int		ft_sqrt(int nb);
int		lenlst(t_lst *lst);
int		douit(t_lst *lst);
int 	chercheplace(void);
int 	incr(void);
int		resolution(t_lst *lst);
int		movepiece(t_lst *lst);
int		isok(t_lst *lst);
int		isokbis(t_lst *lst, int k, int nb);
int		*checkmovit(t_lst *lst);
char	**initcube(void);
char 	*strreplace(char *str, char c, char d);
void 	setprev(t_lst *lst);
void 	rempid(t_lst *lst);
void	resetnb(t_lst *lst);
void	init(void);
void 	printcube();
void	rmpiece(t_lst *lst);
void 	onemore(void);
void	movit(t_lst *lst);
void	testducul(t_lst *lst);
void	movitbis(int i, int j, char *tmp, t_lst *lst);
t_lst	*actual(void);
t_lst	*separe(char *str);
t_lst	*prevnb(t_lst *lst);
t_lst	*nextnb(t_lst *lst);
t_lst	*next(t_lst *lst);
t_lst	*initlst(t_lst *lst);
#endif