/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:08:41 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	replace_texture(t_ms *game, char *direction, int a)
{
	char	*tmp;
	int		i;

	i = 3;
	tmp = NULL;
	if (ft_strncmp(game->p->text_sp[a], direction, 3))
		ft_error("Invalid texture", "Not found in map", EXIT_FAILURE, game);
	while (game->p->text_sp[a][i] == ' ')
		i++;
	tmp = ft_substr(game->p->text_sp[a], i, ft_strlen(game->p->text_sp[a]));
	if (!tmp)
		return ;
	free(game->p->text_sp[a]);
	game->p->text_sp[a] = ft_strdup(tmp);
	free(tmp);
}

int	fd_open(t_ms *game, char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	if (fd < 0)
		ft_error("Invalid texture", str, EXIT_FAILURE, game);
	return (fd);
}

void	texture(t_ms *game)
{
	size_t	i;
	int		rd;

	i = 0;
	rd = 0;
	replace_texture(game, "NO ", 0);
	replace_texture(game, "SO ", 1);
	replace_texture(game, "WE ", 2);
	replace_texture(game, "EA ", 3);
	while (i < 4)
	{
		rd = fd_open(game, game->p->text_sp[i]);
		close(rd);
		i++;
	}
	rd = fd_open(game, "Imgs/flower-idle.xpm");
	close(rd);
	rd = fd_open(game, "Imgs/flower-spark.xpm");
	close(rd);
}
