/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_segment2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:39:04 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/23 23:39:47 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void	ft_eighth(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dy;
	o->dy = i * 2;
	o->dx = o->dx * 2;
	while (a->y != b->y)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i - o->dx) >= 0)
		{
			a->x--;
			i = i + o->dy;
		}
		a->y--;
	}
}

void	ft_seventh(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dx;
	o->dx = i * 2;
	o->dy = o->dy * 2;
	while (a->x != b->x)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i - o->dy) >= 0)
		{
			a->y--;
			i = i + o->dx;
		}
		a->x--;
	}
}

void	ft_sixth(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dy;
	o->dy = i * 2;
	o->dx = o->dx * 2;
	while (a->y != b->y)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i + o->dx) <= 0)
		{
			a->x--;
			i = i + o->dy;
		}
		a->y++;
	}
}

void	ft_fifth(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dx;
	o->dx = i * 2;
	o->dy = o->dy * 2;
	while (a->x != b->x)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i + o->dy) >= 0)
		{
			a->y++;
			i = i + o->dx;
		}
		a->x--;
	}
}

void	make_segment(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	if (o->dy == 0 && o->dx > 0)
	{
		while (a->x != b->x)
			put_pixel(e, a->x++, a->y);
	}
	if ((o->dy = b->y - a->y) != 0 && o->dx < 0)
	{
		if (o->dy > 0)
		{
			if (-o->dx >= o->dy)
				ft_fifth(e, a, b, o);
			else
				ft_sixth(e, a, b, o);
		}
		else
		{
			if (o->dx <= o->dy)
				ft_seventh(e, a, b, o);
			else
				ft_eighth(e, a, b, o);
		}
	}
	ft_finish(e, a, b, o);
}
