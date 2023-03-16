/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:57:35 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:39:12 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (!n)
		return (0);
	if (*str == (unsigned char)c)
		return ((char *)str);
	while (n--)
	{
		if (*str == (unsigned char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

// int main()
// {
//     char str[] = "Meera";
//     int c = 'e';
//     size_t n = 0;
//     printf("%s\n", ft_memchr(str, c, n));
// }