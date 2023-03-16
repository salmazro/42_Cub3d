/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:37:56 by mealjnei          #+#    #+#             */
/*   Updated: 2022/07/14 15:23:19 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putnbr_un(unsigned int n);
int		p_check(va_list m, char c);
void	ft_puthex(unsigned long long nbr, char c, int *i);

#endif
