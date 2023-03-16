/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:14:22 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:41:15 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				k;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	k = 0;
	while (n--)
	{
		if (str1[k] != str2[k])
			return (str1[k] - str2[k]);
		k++;
	}
	return (0);
}

// int main()
// {
//     unsigned char dst[] = "Meerz";
//     unsigned char src[] = "Meera";
//     size_t n = 5;
//     printf("%d", ft_memcmp(dst,src,n));
// }