/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:40:29 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:45:45 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*ned;
	size_t	m;
	size_t	k;

	hay = (char *)haystack;
	ned = (char *)needle;
	k = 0;
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	while (hay[k] && k < len)
	{
		m = 0;
		if (hay[k] == ned[m])
		{
			while (ned[m] == hay[k + m] && (k + m) < len)
			{
				m++;
				if (ned[m] == '\0')
					return ((char *)hay + k);
			}
		}
		k++;
	}
	return (NULL);
}

// int main()
// {
//     printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15));
//     printf("%s\n", strnstr("lorem ipsum dolor sit amet", "lorem", 15));
// }