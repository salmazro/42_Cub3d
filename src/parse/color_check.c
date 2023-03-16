/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:00:50 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_replace(char *new, char *old)
{
	if (!new)
		return (NULL);
	if (old)
	{
		free(old);
		old = NULL;
	}
	return (ft_strdup(new));
}

int	ft_find_index(char **str, char *s, int len, t_ms *game)
{
	int	i;

	i = 0;
	while (str[i] && i < 6)
	{
		if (ft_strncmp(str[i], s, len) == 0)
			return (i);
		i++;
	}
	free_double(str);
	ft_error("Invalid map Missing:", s, EXIT_FAILURE, game);
	return (-1);
}

void	prepare_dir_color(t_ms *game)
{
	char	**tmp;

	tmp = ft_strdupp(game->p->parse_sp, 0, 6);
	game->p->parse_sp[0] = ft_replace(tmp[ft_find_index(tmp, "NO", 2, game)],
			game->p->parse_sp[0]);
	game->p->parse_sp[1] = ft_replace(tmp[ft_find_index(tmp, "SO", 2, game)],
			game->p->parse_sp[1]);
	game->p->parse_sp[2] = ft_replace(tmp[ft_find_index(tmp, "WE", 2, game)],
			game->p->parse_sp[2]);
	game->p->parse_sp[3] = ft_replace(tmp[ft_find_index(tmp, "EA", 2, game)],
			game->p->parse_sp[3]);
	game->p->parse_sp[4] = ft_replace(tmp[ft_find_index(tmp, "F", 1, game)],
			game->p->parse_sp[4]);
	game->p->parse_sp[5] = ft_replace(tmp[ft_find_index(tmp, "C", 1, game)],
			game->p->parse_sp[5]);
	free_double(tmp);
	game->p->text_sp = ft_strdupp(game->p->parse_sp, 0, 4);
	game->p->color_sp = ft_strdupp(game->p->parse_sp, 4, 2);
	game->p->map_sp = ft_strdupp(game->p->parse_sp, 6, \
		ft_strlenn(game->p->parse_sp) - 6);
}
