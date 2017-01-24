/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:28:44 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/06 21:06:28 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	char	*tab;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	if (len < i)
		return (ft_strdup(""));
	if (!(tab = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
	{
		tab[y] = s[i++];
		y++;
	}
	tab[y] = '\0';
	return (tab);
}
