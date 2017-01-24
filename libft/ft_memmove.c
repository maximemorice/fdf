/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 00:11:52 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 17:32:26 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dst)
	{
		while (len-- != 0)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else if (src > dst)
	{
		while (++i != len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
