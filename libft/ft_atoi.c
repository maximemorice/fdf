/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:19:18 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/04 18:50:36 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int	i;
	int	multi;
	int	resultat;

	multi = 1;
	resultat = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		multi = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		resultat = resultat * 10;
		resultat = resultat + str[i] - 48;
		i++;
	}
	resultat = resultat * multi;
	return (resultat);
}
