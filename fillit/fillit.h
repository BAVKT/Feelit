/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:50:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/04/21 16:42:47 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include "libft.h"
#include <fcntl.h>

typedef struct 		s_lst
{
	int 			ok; 			//Si on a deja essayé de la placer.
	int 			nb;				//le numero de l'ordre auuel il a ete posé
	char			piece[21]; 		//La str de la piece 
	char			id; 			//La lettre
	struct s_lst	*next; 			//Le prochain maillon
	struct s_lst 	*prev;			//Le precedent maillon
}					t_lst;

typedef struct 			s_lstalpha
{
	char 				*str;			//Contient l'alphabet
	struct s_lstalpha	*next;
}						t_lstalpha;

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
	int 			taillemin; 		//La taille minimum du cube;
	int 			nbok;
	char			last;			//La derniere lettre de la chaine
	t_lst			*lst; 			//Le maillon en cours
	t_lst 			*firstma;		//Le premier maillon
	t_lstalpha		*alpha;
	t_lstalpha		*firstalpha;	//Le premier maillon de lstalpha
}					t_cube;
t_cube				g_c;


//Pour ranger la forme la plus petite trouvee
typedef struct 		s_stock
{
	int				size;
	char			**bestcube;
}					t_stock;
t_stock				g_stock;

int		maincheck(char **av, int fd);
int 	checkforme(char *ligne);
int		check(char *av);
int 	checknl(char *lignenl);
int 	checkstartend(char *ligne, int *i, int nbl);
int 	ft_capasse(t_lst *lst);
int 	resoplace();
int 	resocheck();
int		reso();
int		mainres(t_lst *lst);
char	**ft_initcube();
void 	ft_setprev(t_lst *lst);
void 	ft_rempid(t_lst *lst);
void	ft_resetok(t_lst *lst);
void 	ft_printcube(char **str, int size);
void 	ft_onemore();
void	ft_isgudcube();
void	ft_isgudpiece();
void	ft_fail();
int		lenlst(t_lst *lst);
t_lst	*separe(char *str);
char	*instr(char	*av);
char 	*strreplace(char *str, char c, char d);
void	rmpiece(t_lst *lst);
int 	ft_chercheplace();
int 	ft_incr();
int		ft_sqrt(int nb);
int 	ft_fact(int nb);
t_lst 	*ft_incrlst(t_lst *lst);
int		ft_lastok();
void	ft_rmlastok();
int 	ft_rempalpha();
int		ft_cmpalpha(char *s);
#endif
