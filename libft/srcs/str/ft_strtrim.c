/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:01:00 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:46:20 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	mk;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	mk = ft_strlen(s1);
	while (ft_strchr(set, s1[mk]) && mk)
		mk--;
	str = ft_substr(s1, 0, mk + 1);
	return (str);
}

// int main()
// {
//     printf("%s\n",ft_strtrim("aheallo this is aameera", "aaa"));
// }