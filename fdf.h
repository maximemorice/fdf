/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:34:07 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/18 14:43:56 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"

typedef struct		s_axe
{
	int				dx;
	int				dy;
}					t_axe;

typedef struct		s_env
{
	unsigned int	img_color;
	void			*mlx;
	void			*win;
	void			*imag;
	int				bpp;
	int				s_line;
	char			*data;
	int				endian;
	int				e;
	int				ey;
	int				decalage;
	char			**argv;
	char			*tab;
	char			**tmp;
	int				ox;
	int				oy;
	int				y;
	int				x;
	int				v;
	int				cnt;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				line;
}					t_point;

int					fct_close(int keycode, t_env *e);
char				*ft_readmap(char **argv, char *line);
void				ft_tab(char *tab, char *number);
int					ft_point(char *tab, int nb);
void				ft_tab(char *tab, char *number);
void				put_pixel(t_env *e, int x, int y);
void				ft_make_segment(t_env *e, t_point *a, t_point *b);
void				place_point(t_env *e, t_point *a, t_point *b, char **z);
void				ft_one_and_two(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_finish(t_env *e, t_point *a, t_point *b, t_axe *o);
void				make_segment(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_first(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_second(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_third(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_fourth(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_fifth(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_sixth(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_seventh(t_env *e, t_point *a, t_point *b, t_axe *o);
void				ft_eighth(t_env *e, t_point *a, t_point *b, t_axe *o);
#endif
