/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:02:36 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:43:22 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	m;

	m = (char)c;
	str = (char *)s;
	while (*str != m)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

// int main()
// {
//     char s[] = "3ttwe";
//     char c;
//     int m = 't';
//     printf("%s\n", ft_strchr(s, m));

// }
