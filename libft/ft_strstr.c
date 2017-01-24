/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:44:33 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 21:38:49 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int			i;
	int			y;
	const char	*tab;

	y = 0;
	if (!*big && !*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (big[y] != 0)
	{
		i = 0;
		if (little[i] == big[y] || little[i] == 0)
		{
			tab = &big[y];
			while (little[i] == big[y + i] && little[i] != 0 && big[y + i] != 0)
			{
				i++;
			}
			if (little[i] == 0)
				return ((char *)tab);
		}
		y++;
	}
	return (0);
}
