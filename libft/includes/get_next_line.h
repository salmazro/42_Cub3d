/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:32:14 by salmazro          #+#    #+#             */
/*   Updated: 2023/03/16 18:35:36 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *a);
char	*ret_next_line(char *a);
char	*first_check(int fd, char *s);
char	*ft_strchr_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_new_line(char *s);

#endif
