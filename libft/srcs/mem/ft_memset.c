/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:56:48 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:50:28 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (len--)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

// int main()
// {
//     unsigned char str[] = "Meera";
//     size_t len = 2;
//     int c = 'y';
//     printf("%s\n", str);
//     ft_memset(str, c, len);
//     printf("%s\n", str);
// }