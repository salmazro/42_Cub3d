/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:40 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:43:40 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		mk;

	mk = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[mk] != '\0')
	{
		s2[mk] = s1[mk];
		mk++;
	}
	s2[mk] = '\0';
	return (s2);
}

// int main()
// {
//     char *s1 = "meera";
//     char *s2 = "3ttwe";
//     printf("%s\n", s1);
//     s1 = ft_strdup(s2);
//     printf("%s\n", s1);
// }
