/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:16:16 by mealjnei          #+#    #+#             */
/*   Updated: 2022/05/09 14:20:27 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mk;
	t_list	*ab;

	if (!lst)
		return (NULL);
	mk = NULL;
	while (lst)
	{
		ab = ft_lstnew(f(lst->content));
		if (!ab)
		{
			ft_lstclear(&ab, del);
			return (mk);
		}
		ft_lstadd_back(&mk, ab);
		lst = lst->next;
	}
	return (mk);
}
