/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:49 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:44:57 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	mk;

	mk = 0;
	while (s[mk] != '\0')
	{
		mk++;
	}
	return (mk);
}

// int main()
// {
//    printf("%zu\n", ft_strlen("3ttwe bu ras\n"));
// }