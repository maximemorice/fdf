/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:41:17 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/24 03:50:13 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	place_point(t_env *e, t_point *a, t_point *b, char **z)
{
	int	i;

	i = 0;
	while (z[i + e->decalage] != 0 && z[i + e->decalage][0] != '\n')
	{
		a->x = ft_point(z[i], 1);
		a->y = ft_point(z[i], 2);
		b->x = ft_point(z[i + e->decalage], 1);
		b->y = ft_point(z[i + e->decalage], 2);
		i++;
		ft_make_segment(e, a, b);
	}
	i = 0;
	while (z[i] != 0)
		free(z[i++]);
	free(z);
	e->cnt = 0;
}

int		if_new_line(t_env *e, t_point *a, int v, int i)
{
	if (a->line == 0)
		e->decalage = i;
	a->line++;
	v = 0;
	if (e->cnt != e->decalage)
	{
		ft_putendl("Found wrong line length. Exiting.");
		exit(1);
	}
	e->cnt = 0;
	return (v);
}

void	ft_place_point(t_env *e, t_point *a, t_point *b)
{
	int		i;
	char	**z;

	i = 0;
	e->v = 0;
	z = ft_strsplit(e->tab, ' ');
	while (z[i + 1] != 0)
	{
		if (z[i][0] == '\n')
			e->v = if_new_line(e, a, e->v, i);
		e->cnt++;
		e->ox = e->x + a->line * 2 * e->e;
		e->oy = e->y + a->line * e->e;
		a->z = ft_atoi(z[i]);
		a->x = e->ox + e->v * e->e * 2;
		a->y = e->oy - e->v++ * e->e - a->z * e->ey;
		ft_tab(z[i], ft_itoa(a->x));
		ft_tab(z[i++], ft_itoa(a->y));
		b->z = ft_atoi(z[i]);
		b->x = e->ox + e->v * e->e * 2;
		b->y = e->oy - e->v * e->e - b->z * e->ey;
		if (z[i][0] != '\n')
			ft_make_segment(e, a, b);
	}
	place_point(e, a, b, z);
}

int		loop_hook(t_env *e)
{
	t_point	b;
	t_point	a;

	e->imag = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->imag, &e->bpp, &e->s_line, &e->endian);
	e->img_color = mlx_get_color_value(e->mlx, 0xffffff);
	a.line = 0;
	ft_place_point(e, &a, &b);
	mlx_put_image_to_window(e->mlx, e->win, e->imag, 0, 0);
	mlx_destroy_image(e->mlx, e->imag);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;
	char	*line;

	line = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf mapname.c.");
		return (1);
	}
	e.argv = argv;
	e.cnt = 0;
	e.e = 1;
	e.ey = 2;
	e.x = 500;
	e.y = 500;
	e.tab = ft_readmap(e.argv, line);
	if (e.tab == NULL)
		return (0);
	free(line);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "fdf");
	mlx_key_hook(e.win, fct_close, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
