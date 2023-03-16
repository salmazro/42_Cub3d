/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:57:47 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:31:44 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int				mk;
	unsigned int	ab;
	int				sign;

	mk = 0;
	ab = 0;
	sign = 1;
	while (s[mk] == ' ' || s[mk] == '\n' || s[mk] == '\f' || s[mk] == '\t' || \
			s[mk] == '\r' || s[mk] == '\v')
		mk++;
	if (s[mk] == '-' || s[mk] == '+')
	{
		if (s[mk] == '-')
			sign *= -1;
		mk++;
	}
	while (s[mk] >= '0' && s[mk] <= '9')
		ab = ab * 10 + (s[mk++] - '0');
	if (ab > 2147483647 && sign == 1)
		return (-1);
	if (ab > 2147483648 && sign == -1)
		return (0);
	return (ab * sign);
}
