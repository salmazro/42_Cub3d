/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:24:26 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:44:32 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t m)
{
	size_t	dsize;
	size_t	srsize;

	dsize = ft_strlen(dst);
	srsize = ft_strlen(src);
	if (m < dsize)
		dsize = m;
	if (dsize == m)
		return (dsize + srsize);
	if (srsize < (m - dsize))
	{
		ft_memcpy(dst + dsize, src, srsize);
		dst[dsize + srsize] = '\0';
	}
	else
	{
		ft_memcpy(dst + dsize, src, m - dsize - 1);
		dst[m - 1] = '\0';
	}
	return (dsize + srsize);
}

// int main()
// {
//     char dst[] = "dsdfs";
//     char src[] = "iijio";
//     size_t a = 13;
//     printf("%zu\n", ft_strlcat(dst, src, a));
//     printf("%s\n", dst);
//     printf("%lu\n", strlcat(dst, src, a));
//     printf("%s\n", dst);
// }