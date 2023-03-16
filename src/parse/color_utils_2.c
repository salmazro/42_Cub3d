/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:00:58 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_char(char *dest, char src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}

void	ft_putnbr_base(int nbr, int nbase, char *num_base, char *base)
{
	if (nbr >= nbase)
	{
		ft_putnbr_base((nbr / nbase), nbase, num_base, base);
	}
	ft_char(num_base, base[nbr % nbase]);
}

char	*ft_put_nbr(int nbr, char *base, int sign, int i)
{
	int		nbase;
	int		pbase;
	char	*num;

	nbase = ft_strlen(base);
	pbase = ft_lnbr(nbr, nbase);
	if (sign % 2 != 0 && nbr != 0)
	{
		num = malloc((pbase + 2) * sizeof(char));
		if (!num)
			return (0);
		while (++i < pbase + 2)
			num[i] = '\0';
		num[0] = '-';
	}
	else
	{
		num = malloc((pbase + 1) * sizeof(char));
		if (!num)
			return (0);
		while (++i < pbase + 1)
			num[i] = '\0';
	}
	ft_putnbr_base(nbr, nbase, num, base);
	return (num);
}
