/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:53:44 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 19:38:03 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	i;
	size_t	lenorig;

	i = 0;
	lendst = ft_strlen(dst);
	if (size <= lendst)
	{
		return (size + ft_strlen(src));
	}
	size = size - lendst;
	lenorig = lendst;
	while (i < size - 1)
	{
		dst[lendst] = src[i];
		i++;
		lendst++;
	}
	dst[lendst] = 0;
	return (lenorig + ft_strlen(src));
}
