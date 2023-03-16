/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:49:31 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:42:35 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	m;

	m = (long)n;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	if (m > 9)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putchar_fd(m % 10 + '0', fd);
	}
	else
		ft_putchar_fd(m + '0', fd);
}
