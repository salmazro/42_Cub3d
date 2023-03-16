/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:22:17 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/24 17:28:25 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*a;

	if (lst)
	{
		while (lst)
		{
			if (lst->next == NULL)
				a = lst;
			lst = lst->next;
		}
		return (a);
	}
	return (NULL);
}
