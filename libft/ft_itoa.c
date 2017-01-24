/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:53:12 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/05 13:26:05 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		y;
	char	tmp;

	y = ft_intlen(n);
	if (!(tab = (char *)malloc(sizeof(char) * (y + 1))))
		return (NULL);
	tab[y] = '\0';
	i = y - 1;
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
		tab[0] = '-';
	while (n != 0)
	{
		tmp = n % 10;
		if (n < 0)
			tmp = -tmp;
		tab[i--] = tmp + 48;
		n = n / 10;
	}
	return (tab);
}
