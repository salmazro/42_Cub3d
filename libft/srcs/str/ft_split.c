/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:31:09 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**mk(char **split, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && end < ft_strlen(s))
			end++;
		split[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *str, char seprator)
{
	char	**split;

	if (!str)
		return (NULL);
	split = (char **)malloc((count_words(str, seprator) + 1) * sizeof(char *));
	if (!split)
		return (0);
	split = mk(split, str, seprator);
	return (split);
}
