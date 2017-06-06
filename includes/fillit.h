/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:10:59 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/06 18:05:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# include "libft.h"

typedef struct		s_lst
{
	int				nb;
	char			*piece;
	char			id;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_cube
{
	char			**c;
	char			**tmp;
	char			last;
	int				i;
	int				j;
	int				size;
	int				nbpiece;
	int				taillemin;
	int				nbok;
	t_lst			*lst;
	t_lst			*firstma;
}					t_cube;
t_cube				g_c;

int					checknl(char *lignenl);
int					checkstartend(char *ligne, int *i, int nbl);
int					checkforme(char *ligne);
int					check(char *lignenl);
int					checktab(char *str);
int					maincheck(char **av, int fd);
int					mainres(void);
int					lenlst(t_lst *lst);
int					douit(t_lst *lst);
int					chercheplace(void);
int					incr(void);
int					resolution(t_lst *lst);
int					movepiece(t_lst *lst);
int					isok(t_lst *lst);
int					isokbis(t_lst *lst);
int					*checkmovit(t_lst *lst);
int					movepiecebis(t_lst *lst);
char				**initcube(void);
char				*strreplace(char *str, char c, char d);
void				setprev(t_lst *lst);
void				rempid(t_lst *lst);
void				resetnb(t_lst *lst);
void				init(void);
void				printcube();
void				rmpiece(t_lst *lst);
void				onemore(void);
void				movit(t_lst *lst);
void				testducul(t_lst *lst);
void				movitbis(int i, int j, char *tmp, t_lst *lst);
t_lst				*actual(void);
t_lst				*separe(char *str);
t_lst				*prevnb(t_lst *lst);
t_lst				*nextnb(t_lst *lst);
t_lst				*next(t_lst *lst);
t_lst				*initlst(t_lst *lst);
#endif
