/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 00:10:40 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/23 23:29:32 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void	ft_make_segment(t_env *e, t_point *a, t_point *b)
{
	t_axe	o;

	o.dy = b->y - a->y;
	if ((o.dx = b->x - a->x) != 0)
	{
		if (o.dx > 0)
		{
			if ((o.dy = b->y - a->y) != 0)
			{
				if (o.dy > 0)
					ft_one_and_two(e, a, b, &o);
				else
				{
					if (o.dx >= -o.dy)
						ft_third(e, a, b, &o);
					else
						ft_fourth(e, a, b, &o);
				}
			}
		}
	}
	make_segment(e, a, b, &o);
}

void	ft_first(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dx;
	o->dx = i * 2;
	o->dy = o->dy * 2;
	while (a->x != b->x)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i - o->dy) < 0)
		{
			a->y++;
			i = i + o->dx;
		}
		a->x++;
	}
}

void	ft_second(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dy;
	o->dy = i * 2;
	o->dx = o->dx * 2;
	while (a->y != b->y)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i - o->dx) < 0)
		{
			a->x++;
			i = i + o->dy;
		}
		a->y++;
	}
}

void	ft_third(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dx;
	o->dx = i * 2;
	o->dy = o->dy * 2;
	while (a->x != b->x)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i + o->dy) < 0)
		{
			a->y--;
			i = i + o->dx;
		}
		a->x++;
	}
}

void	ft_fourth(t_env *e, t_point *a, t_point *b, t_axe *o)
{
	int	i;

	i = o->dy;
	o->dy = i * 2;
	o->dx = o->dx * 2;
	while (a->y != b->y)
	{
		put_pixel(e, a->x, a->y);
		if ((i = i + o->dx) > 0)
		{
			a->x++;
			i = i + o->dy;
		}
		a->y--;
	}
}
