/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:57:14 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:41:47 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n--)
	{
		*ds++ = *sr++;
	}
	return (dst);
}

// int main()
// {
//     unsigned char dst[] = "Meera";
//     unsigned char src[] = "Meera";
//     size_t n = 0;
//     printf("%s\n", dst);
//     ft_memcpy(dst,src,n);
//     printf("%s\n", dst);
// }