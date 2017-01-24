/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_segment3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 01:31:25 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/23 23:39:43 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void	put_pixel(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x > 0 && y > 0 && x < 1000 && y < 1000)
	{
		r = ((e->img_color & 0xFF0000) >> 16);
		g = ((e->img_color & 0xFF00) >> 8);
		b = ((e->img_color & 0xFF));
		e->data[y * e->s_line + x * e->bpp / 8] = b;
		e->data[y * e->s_line + x * e->bpp / 8 + 1] = g;
		e->data[y * e->s_line + x * e->bpp / 8 + 2] = r;
	}
}

void	ft_one_and_two(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	if (o->dx >= o->dy)
		ft_first(e, a, b, o);
	else
		ft_second(e, a, b, o);
}

void	ft_finish(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	if (o->dy == 0 && o->dx < 0)
	{
		while (a->x != b->x)
			put_pixel(e, a->x--, a->y);
	}
	else
	{
		if ((o->dy = b->y - a->y) != 0)
		{
			if (o->dy > 0)
				while (a->y != b->y)
					put_pixel(e, a->x, a->y++);
			else
				while (a->y != b->y)
					put_pixel(e, a->x, a->y--);
		}
	}
	put_pixel(e, a->x, a->y);
}
