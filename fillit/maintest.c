#include "fillit.h"

//Affichage du cube
void 	ft_printcube()
{
	ft_putendl("printcube");
	int i;
	int j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			ft_putchar(g_c.c[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

//Rempli de point
void	ft_addpoint()
{
	ft_putendl("addpoint");
	int i;
	int j;

	i = 0;
	while (i < g_c.size)
	{
		j = 0;
		while (j < g_c.size)
		{
			if (g_c.c[i][j] != '.' || 
				(g_c.c[i][j] <= 'A' && g_c.c[i][j] >= 'Z'))
				g_c.c[i][j] = '.';
			j++;
		}
		i++;
	}
}

//Initialiation du cube et le rempli de points.
void 	ft_initcube()
{
	ft_putendl("inicube");
	int i;

	i = 0;
	g_c.c = (char **)malloc(sizeof(char *) * g_c.size);
	while (i < g_c.size)
	{
		g_c.c[i] = (char *)malloc(sizeof(char) * g_c.size);		
		i++;
	}
	ft_addpoint();
							ft_putendl("INITCUBE CUBE");
							ft_printcube();
}

//Ajout d'une ligne au cube
void 	ft_onemore()
{
	ft_putendl("onemore");
	int i;
	int j;
	char **tmp;

	tmp = g_c.c;
	g_c.size += 1;
	ft_initcube();
	i = 0;
	while (i < g_c.size - 1)
	{
		j = 0;
		while (j < g_c.size - 1)
		{
			g_c.c[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}

int main()
{
	g_c.size = 66;
	ft_initcube();
	ft_printcube();

	ft_onemore();
	ft_printcube();
	ft_putendl("FIN");
	return (0);	
}
