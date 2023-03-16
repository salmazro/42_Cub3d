/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:51:45 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:46:06 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	m;
	int		i;

	m = (char)c;
	str = (char *)s;
	i = ft_strlen(str);
	if (c == '\0')
		return (str + i);
	while (i--)
	{
		if (str[i] == m)
			return (&str[i]);
	}
	return (NULL);
}

// int main()
// {
//     char s[] = "3ttwe";
//     int m = '3';
//     printf("%s\n", ft_strrchr(s, m));
//     printf("%s\n", strrchr(s, m));

// }