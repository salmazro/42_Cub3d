/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:59:06 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:46:43 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_tolower(char mk)
{
	if (mk >= 65 && mk <= 90)
	{
		mk = mk + 32;
	}
	return (mk);
}

// int main()
// {
//     char *str = "MEERA";
//     int i = 0;
//     while (str[i] != '\0')
//     {
//         printf("%c\n", ft_tolower(str[i]));
//         i++;
//     }
// }