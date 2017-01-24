/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:22:10 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 17:25:15 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;

	tmp2 = (char *)src;
	tmp = (char *)dest;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if (tmp[i] == (char)c)
			return (tmp + i + 1);
		i++;
	}
	return (0);
}
