/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:30:17 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 22:58:42 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tab;
	int		y;

	i = 0;
	y = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
		{
			y++;
			tab = (char *)&s[i];
		}
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	if (y == 0)
		return (0);
	return (tab);
}
