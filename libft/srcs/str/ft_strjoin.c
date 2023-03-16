/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:25:53 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:44:17 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		mk;
	int		ab;
	char	*str;

	mk = 0;
	ab = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[mk])
		str[ab++] = s1[mk++];
	mk = 0;
	while (s2[mk])
		str[ab++] = s2[mk++];
	str[ab] = '\0';
	return (str);
}
