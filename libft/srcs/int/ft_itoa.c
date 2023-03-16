/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:07:09 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/26 17:14:24 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			digit;
	char		*mk;
	long int	i;

	i = n;
	if (!n)
		return (ft_strdup("0"));
	digit = ft_digit(n);
	mk = (char *)malloc((digit + 1) * (sizeof(char)));
	if (!mk)
		return (NULL);
	mk[digit--] = '\0';
	if (i < 0)
	{
		mk[0] = '-';
		i = i * -1;
	}
	while (i > 0)
	{
		mk[digit] = (i % 10) + '0';
		i = i / 10;
		digit--;
	}
	return (mk);
}
