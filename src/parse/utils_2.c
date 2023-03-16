/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:08:25 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strjoin_freeall(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	k = -1;
	i = -1;
	if (!s2)
		return (s1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++k])
		str[i++] = s2[k];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*ft_joinchar(char *s1, char c)
{
	char	*str;
	int		i;

	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = c;
	str[i + 1] = '\0';
	free(s1);
	return (str);
}

char	**ft_strdupp(char **str, int start, int size)
{
	char	**new;
	int		i;
	int		j;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = start;
	j = 0;
	while ((i < (start + size)) && str[i])
		new[j++] = ft_strdup(str[i++]);
	new[j] = NULL;
	return (new);
}

size_t	ft_strlenn(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	**free_double(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s[i]);
	free(s);
	s = NULL;
	return (NULL);
}
