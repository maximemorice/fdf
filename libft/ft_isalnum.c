/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:05:07 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/05 15:34:23 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	i;
	int	y;

	i = ft_isalpha(c);
	y = ft_isdigit(c);
	if ((i > 0) || (y > 0))
		return (1);
	return (0);
}
