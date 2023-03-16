/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:56:54 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:42:06 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst + len;
	sr = (unsigned char *)src + len;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
	{
		*--ds = *--sr;
	}
	return (dst);
}

// int main()
// {
//     unsigned char dst[] = "Meera";
//     unsigned char src[] = "3ttwe";
//     unsigned char ds[] = "Meera";
//     unsigned char sr[] = "3ttwe";
//     size_t n = 5;
//     printf("%s\n", dst);
//     ft_memmove(dst,src,n);
//     printf("%s\n", dst);
//     printf("%s\n", ds);
//     memmove(ds,sr,n);
//     printf("%s\n", ds);
// }