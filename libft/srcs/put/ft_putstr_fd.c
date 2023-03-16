/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:42:52 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:42:43 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ((void )s);
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

// int main()
// {
// 	int fd;
// 	char *str;

// 	fd = open("text.txt", O_WRONLY);
// 	printf("%d\n",fd);
// 	ft_putstr_fd("abcde", fd);
// }