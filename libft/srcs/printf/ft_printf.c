/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:41:40 by mealjnei          #+#    #+#             */
/*   Updated: 2022/07/14 15:47:48 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_check(va_list m, char c)
{
	int	i;

	i = 0;
	if (c == 's')
		i = ft_putstr(va_arg(m, char *));
	else if (c == 'c')
		i = ft_putchar(va_arg(m, int));
	else if (c == 'd')
		i = ft_putnbr(va_arg(m, int));
	else if (c == 'i')
		i = ft_putnbr(va_arg(m, int));
	else if (c == 'u')
		i = ft_putnbr_un(va_arg(m, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(m, unsigned int), c, &i);
	else if (c == 'p')
		ft_puthex(va_arg(m, unsigned long long), c, &i);
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	check_in(int a)
{
	if (a == 's' || a == 'c' || a == 'd' || a == 'u'
		|| a == 'i' || a == 'x' || a == 'X' || a == '%' || a == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	m;
	int		j;

	j = 0;
	va_start(m, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (check_in(str[i + 1]))
				j += p_check(m, str[i + 1]);
			i++;
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(m);
	return (j);
}

// #include <limits.h>
// int	main()
// {
// 	// int x = 0;
// 	char *str = NULL;
// 	int x = ft_printf("%p \n", -1);
// 	int i= printf("%p \n", -1);
// 	printf("%d %d \n", x, i);
// }