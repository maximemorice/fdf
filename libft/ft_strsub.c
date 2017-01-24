/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:43:26 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/06 20:59:47 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len != 0)
	{
		tab[i] = s[start];
		start++;
		i++;
		len--;
	}
	tab[i] = '\0';
	return (tab);
}
