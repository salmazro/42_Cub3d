/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:42:42 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/24 16:58:34 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// void printList(t_list *node)
// {
//     while (node) {
//         printf("%d\n", (int)(node->content));
//         node = node->next;
//     }
//     write(1, "new print\n", 11);
// }

// int main()
// {
//     t_list *l; 

//     l =  NULL;
//   	ft_lstadd_front(&l, ft_lstnew((void*)1));
// 	     printList(l);

// 	ft_lstadd_front(&l, ft_lstnew((void*)2));
// 	   printList(l);

// 	ft_lstadd_front(&l, ft_lstnew((void*)3));

//    printList(l);
//     //l = l->next;
//     //l = ft_lstnew((void*)2);
// }