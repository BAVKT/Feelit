/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:24:24 by vmercadi          #+#    #+#             */
/*   Created: 2017/01/17 03:24:24 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//Check si les pieces sont bien séparées par un seul \n 
int		checknl(char *av)
{
	int 	fd;
	int 	i;
	int 	ret;
	char 	buf[42];

	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, 41)))
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i])
		{	//On vérifie juste qu'il y ait pas + de 3 nl a la suite
			if (buf[i] == '\n' && buf[i + 1] == '\n' && buf[i + 2] == '\n')		
				return (0);
			i++;
		}
	}
	close(fd);
	return (1);
}

//Check special pour les premieres et dernieres lignes
int 	checkstartend(char *ligne, int *i, int nbl)
{
	if (*i > 1 && nbl == 1)
	{	//Check pour la premiere ligne (on enleve le check de la piece du dessus parce qu'il y en aura jamais)
		if (ligne[*i - 1] == '#' || ligne[*i + 1] == '#' || ligne[*i + 5] == '#')
			return (1);
		else 
			return (0);		
	}
	else if (i < (int *)ft_strlen(ligne) && nbl == 4)
	{	//Check pour la premiere ligne (on enleve le check de la piece du dessous pour la meme raison)
		if (ligne[*i - 1] == '#' || ligne[*i + 1] == '#' || ligne[*i - 5] == '#')
			return (1);
		else 
			return (0);
	}
	return (1);
}

//Check si les tetriminos n'ont pas de malformations physiques parce qu'on veut pas d'handicapés 
int 	checkforme(char *ligne)
{
	int 	i;
	int 	nbl;	//Nombre de ligne
	int		ok;

	i = 0;
	nbl = 1;
	ok = 1;
	while (ligne[i])
	{ 	//Chaque fois qu'on tombe sur un # on test si il touche bien un autre #
		if (ligne[i] == '#' && (ok = checkstartend(ligne, &i, nbl))
			 && (nbl == 1 || nbl == 4))
			i++;
		else if (ligne[i] == '.')
			i++;
		else 		//Alors ca c'est le cancer, je sais pas pourquoi mais sinon ca marche pas.... Illogique
			i++;
		if (i % 6 == 0)
			nbl++;
		if (nbl > 4)	//On remet nbl a 0 parce que la piece est finie.
			nbl = 1;
		if (ok == 0) 	//On verifie que ok soit toujours = 1 sinon ca veut dire qu'il y a erreur
			return (0);
	}
	return (1);
}

//Check si il y a bien que des diezs et des points et en bon nombre parce qu'on est raciste du reste
int		check(char *av)
{
	int		i;
	int		pt;
	int		diez;
	int		fd;
	char 	s[2];

	pt = 0;
	diez = 0;
	fd = open(av, O_RDONLY);
	while ((i = read(fd, s, 1)))
	{
		s[1] = '\0';
		if (((pt + diez) / 4 == 0 && s[0] != '\n' && s[0] != '.' 
			 && s[0] != '#') || pt + diez > 417)
			return (0);
		if (s[0] == '.')
			pt++;
		else if (s[0] == '#')
			diez++;
	}
	close(fd);
	if (pt / diez == 3 && pt % diez == 0)
		return (1);
	else
		return (0);
}

//Le main qui execute les checks
int		maincheck(char *av)
{
	int 	ok;		//Retour du test 1
	int 	okk;	//Retour du test 2
	int 	okkk; 	//Retour du test 3
	char 	*ligne;

	ligne = instr(av);
	if ((ok = check(av)))
	{
		if ((okk = checkforme(strreplace(ligne, '\n', '.'))))
		{
			if ((okkk = checknl(av)))
			{
				separe(ligne);
				return (1);
			}
		}
	}
	return (0);
}
