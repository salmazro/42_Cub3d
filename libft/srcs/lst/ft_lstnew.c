/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:48:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/24 16:45:20 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *mk)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = mk;
	new->next = NULL;
	return (new);
}

// int main()
// {
//     t_list *l; 

//     l =  NULL;
//     l = ft_lstnew((void*)"1");
//     printf("%s\n", l->content);
//     //l = l->next;
//     //l = ft_lstnew((void*)2);
// }
