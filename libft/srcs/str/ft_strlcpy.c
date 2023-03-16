/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:36:33 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:44:42 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;

	a = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[a] != '\0' && a < (dstsize - 1))
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (ft_strlen(src));
}

// int main()
// {
//     char dst[] = "dsdfs";
//     char src[] = "";
//     size_t a = 4;
//     printf("%zu\n", ft_strlcpy(dst, src, a));
//     printf("%lu\n", strlcpy(dst, src, a));
// }