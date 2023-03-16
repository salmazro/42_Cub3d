/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:45:24 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (s1[k] && s2[k] && s1[k] == s2[k] && k < n)
		k++;
	if (k < n)
		return ((unsigned char)s1[k] - (unsigned char)s2[k]);
	return (0);
}

// int main()
// {
//     char s1[] = "abcd";
//     char s2[] = "abcm";
//     size_t n = 3;
//     printf("%d\n", ft_strncmp(s1, s2, n));
// }