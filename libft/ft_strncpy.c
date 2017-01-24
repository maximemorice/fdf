/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:08:59 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/05 16:28:01 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = 0;
	while (src[i] != 0 && n != 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	while (n-- != 0)
		dest[i++] = 0;
	return (dest);
}
