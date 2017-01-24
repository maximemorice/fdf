/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_segment4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:39:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/24 03:55:07 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		fct_close(int keycode, t_env *e)
{
	if (keycode == 24)
		e->ey++;
	if (keycode == 27)
		e->ey--;
	if (keycode == 126)
		e->y = e->y - 25;
	if (keycode == 125)
		e->y = e->y + 25;
	if (keycode == 124)
		e->x = e->x + 25;
	if (keycode == 123)
		e->x = e->x - 25;
	if (keycode == 78)
		e->e--;
	if (keycode == 69)
		e->e++;
	if (keycode == 53)
		exit(1);
	return (0);
}

char	*ft_readmap(char **argv, char *line)
{
	int		fd;
	char	*tmp;
	char	*tmp2;

	line = NULL;
	tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, line);
		free(tmp2);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, " \n");
		free(tmp2);
		free(line);
	}
	close(fd);
	if (tmp == NULL)
	{
		ft_putstr("fdf: no such file: ");
		ft_putendl(argv[1]);
	}
	return (tmp);
}

void	ft_tab(char *tab, char *number)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (tab[i] == '\n')
	{
		while (tab[i + 1] != 0 && tab[i + 1] != ',')
		{
			tab[i] = tab[i + 1];
			i++;
		}
		tab[i] = 0;
	}
	while (tab[x] != 0 && tab[x] != ',')
		x++;
	tab[x++] = ' ';
	i = 0;
	while (number[i] != 0)
		tab[x++] = number[i++];
	tab[x] = 0;
	free(number);
}

int		ft_point(char *tab, int nb)
{
	int	i;
	int	resultat;

	i = 0;
	while (tab[i] != 0)
	{
		while (tab[i] != ' ')
			i++;
		i++;
		if (nb == 1)
		{
			resultat = 0;
			while (tab[i] != ' ')
			{
				resultat = resultat * 10;
				resultat = resultat + tab[i] - 48;
				if (tab[i + 1] == 0)
					return (resultat);
				i++;
			}
			return (resultat);
		}
		nb = 1;
	}
	return (0);
}
