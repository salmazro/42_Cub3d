/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:30:17 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/24 17:43:23 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*m;

	if (lst)
	{
		if (*lst)
		{
			m = ft_lstlast(*lst);
			m->next = new;
		}
		else
			*lst = new;
	}
}
