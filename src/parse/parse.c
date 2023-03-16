/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:08:46 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_extension(char *str, t_ms *game)
{
	int	fd;

	fd = -1;
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		return (ft_putstr_fd("Error : Invalid file extension (must be .cub)\n",
				2), exit(EXIT_FAILURE));
	else
		game->p->map_path = ft_strdup(str);
	fd = open(game->p->map_path, O_RDWR);
	if (fd == -1)
		return (ft_error("Invalid file", game->p->map_path, EXIT_FAILURE,
				game));
	close(fd);
}

void	read_map(t_ms *game)
{
	int		fd;
	char	*line;

	fd = open(game->p->map_path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Could not open map file (fd = -1)\n",
				2), ft_putendl_fd(game->p->map_path, 2),
			exit(EXIT_FAILURE));
	line = "";
	game->p->map = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		game->p->map = ft_strjoin_freeall(game->p->map, line);
	}
	free(line);
	close(fd);
	game->p->map = ft_joinchar(game->p->map, '\n');
	game->p->parse_sp = ft_split(game->p->map, '\n');
}

void	parsing(t_ms *game)
{
	read_map(game);
	prepare_dir_color(game);
	ft_color_parse(game);
	ft_map_valid_char(game, -1, 0);
	if (game->config->i == 0)
		ft_error("Invalid map", "No char found in map", EXIT_FAILURE, game);
	check_walls(game);
	check_zero(game);
	texture(game);
	player_position(game);
}
