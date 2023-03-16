/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:39:50 by mealjnei          #+#    #+#             */
/*   Updated: 2022/07/14 15:27:35 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int m)
{
	int		i;
	long	n;

	i = 0;
	n = (long)m;
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putnbr_un(unsigned int n)
{
	int		i;
	long	m;

	i = 0;
	m = (long)n;
	if (m > 9)
	{
		i += ft_putnbr_un(m / 10);
		i += ft_putchar(m % 10 + '0');
	}
	else
		i += ft_putchar(m + '0');
	return (i);
}

void	ft_puthex(unsigned long long nbr, char c, int *i)
{
	char	*b;

	b = "0123456789abcdef";
	if (c == 'X')
		b = "0123456789ABCDEF";
	if (c == 'p' && !*i)
	{
		*i += ft_putstr("0x");
		if (nbr == 0)
		{
			*i += ft_putchar('0');
			return ;
		}
	}
	if (nbr > 15)
		ft_puthex(nbr / 16, c, i);
	*i += ft_putchar(b[nbr % 16]);
}
