/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:57:51 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:33:24 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t m)
{
	char	*str;
	size_t	mk;

	mk = 0;
	str = (char *)s;
	while (mk < m)
	{
		str[mk++] = 0;
	}
	return (s);
}

// int main()
// {
//     char s[10] = "Meera";
//     size_t m = 4;
//     printf("%s\n", s);
//     ft_bzero(s, 5);
//     printf("%c\n", s[0]);
//     printf("%c\n", s[1]);
//     printf("%c\n", s[2]);
//     printf("%c\n", s[3]);
//     printf("%c\n", s[4]);
// }