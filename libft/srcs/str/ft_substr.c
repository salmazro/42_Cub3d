/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:41:25 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/26 17:35:25 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *m, unsigned int start, size_t len)
{
	char	*mk;

	if (!m)
		return (NULL);
	if (ft_strlen(m) < start)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > ft_strlen(m))
		len = ft_strlen(m) - start;
	mk = (char *)malloc((len + 1) * (sizeof(char)));
	if (!mk)
		return (NULL);
	ft_strlcpy(mk, m + start, len + 1);
	return (mk);
}
