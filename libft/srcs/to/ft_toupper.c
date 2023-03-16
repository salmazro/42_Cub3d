/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:59:09 by mealjnei          #+#    #+#             */
/*   Updated: 2022/04/19 22:47:01 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper(char mk)
{
	if (mk >= 97 && mk <= 122)
	{
		mk = mk - 32;
	}
	return (mk);
}