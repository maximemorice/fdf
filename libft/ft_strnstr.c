/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:12:36 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/07 22:24:53 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			i;
	int			y;
	const char	*tab;

	y = 0;
	if (!*big && !*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (big[y] != 0 && len != 0)
	{
		i = 0;
		if (little[i] == big[y] || little[i] == 0)
		{
			tab = &big[y];
			while (little[i] == big[y + i] && little[i] != 0
					&& big[y + i] != 0 && (len - i) != 0)
				i++;
			if (little[i] == 0)
				return ((char *)tab);
		}
		len--;
		y++;
	}
	return (0);
}
