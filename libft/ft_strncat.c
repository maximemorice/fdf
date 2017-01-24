/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:53:58 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 17:31:53 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (dest[i] != 0)
		i++;
	while (src[y] != 0 && y < n)
	{
		dest[i] = src[y];
		y++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
