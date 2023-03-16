/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:08:08 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_position(t_ms *game)
{
	int	x;
	int	y;
	int	flag;

	y = -1;
	flag = 0;
	x = 0;
	while (game->p->map_sp[++y])
	{
		x = -1;
		while (game->p->map_sp[y][++x])
		{
			if (game->p->map_sp[y][x] == 'E' || game->p->map_sp[y][x] == 'S'
				|| game->p->map_sp[y][x] == 'W' || game->p->map_sp[y][x] == 'N')
			{
				game->p->map_sp[y][x] = 'P';
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	game->config->posy = (double)y + 0.5;
	game->config->posx = (double)x + 0.5;
}

void	ft_map_valid_structure(t_ms *game, int *i, size_t *nl)
{
	while (game->p->map[++(*i)] && *nl < 7)
	{
		if (game->p->map[*i] == '\n')
			*i = *i + 1;
		else if (game->p->map[*i] != '\n')
		{
			*nl = *nl + 1;
			while (game->p->map[*i] != '\n')
				*i = *i + 1;
		}
	}
}

static void	check_(char c, t_ms *game)
{
	if (c == 'S')
	{
		game->config->dir_fun = c;
		game->config->checker = 2;
		set_config(game->config);
		game->config->i++;
	}
	if (c == 'W')
	{
		game->config->dir_fun = c;
		game->config->checker = 3;
		set_config(game->config);
		game->config->i++;
	}
	if (game->config->i > 1)
		ft_error("Invalid map", NULL, EXIT_FAILURE, game);
}

void	check_pos(char c, t_ms *game)
{
	if (c == 'N')
	{
		game->config->dir_fun = c;
		game->config->checker = 0;
		set_config(game->config);
		game->config->i++;
	}
	if (c == 'E')
	{
		game->config->dir_fun = c;
		game->config->checker = 1;
		set_config(game->config);
		game->config->i++;
	}
	check_(c, game);
}

void	ft_map_valid_char(t_ms *game, int i, size_t nl)
{
	ft_map_valid_structure(game, &i, &nl);
	while (game->p->map[i])
	{
		if (game->p->map[i] == '1' || game->p->map[i] == '0'
			|| game->p->map[i] == 'N' || game->p->map[i] == 'S'
			|| game->p->map[i] == 'E' || game->p->map[i] == 'W'
			|| game->p->map[i] == ' ' || game->p->map[i] == '\n')
		{
			check_pos(game->p->map[i], game);
			if (game->p->map[i] == '\n' && game->p->map[i + 1] == '\n'
				&& game->p->map[i + 2])
				ft_error("Invalid map", NULL, EXIT_FAILURE, game);
		}
		else
			ft_error("Invalid char in map", NULL, EXIT_FAILURE, game);
		i++;
	}
}
