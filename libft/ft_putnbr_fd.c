/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:26:55 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/06 17:28:02 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n > 9 || n < -9)
	{
		ft_putnbr_fd(((n < 0) ? -1 : 1) * (n / 10), fd);
		ft_putnbr_fd(((n < 0) ? -1 : 1) * (n % 10), fd);
	}
	if (n < 10 && n > -10)
	{
		if (n < 0)
			ft_putchar_fd(-n + 48, fd);
		else
			ft_putchar_fd(n + 48, fd);
	}
}
