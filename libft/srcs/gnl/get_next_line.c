/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:21:51 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ret_next_line(char *a)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*a)
		return (NULL);
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	while (*a != '\0' && *a != '\n')
		str[j++] = *a++;
	if (*a == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*first_check(int fd, char *a)
{
	char	*str;
	ssize_t	i;
	size_t	m;

	m = BUFFER_SIZE;
	str = malloc(m + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (!ft_strchr_gnl(a) && i)
	{
		i = read(fd, str, m);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		a = ft_strjoin_gnl(a, str);
	}
	free(str);
	return (a);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*a;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	a = first_check(fd, a);
	if (!a)
		return (NULL);
	str = ret_next_line(a);
	a = ft_new_line(a);
	return (str);
}

// int main()
// {
//     int fd;

//     fd = open("test.txt", O_RDONLY);
//     printf("%s", get_next_line(fd));
// }