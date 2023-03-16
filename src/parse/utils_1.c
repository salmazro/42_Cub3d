/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:08:33 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error(char *str, char *err, int status, t_ms *game)
{
	ft_printf("Error: %s\t", str);
	ft_putendl_fd(err, 2);
	if (game)
	{
		if (game->p->map_path)
			free(game->p->map_path);
		if (game->p->map)
			free(game->p->map);
		if (game->p->parse_sp)
			free_double(game->p->parse_sp);
		if (game->p->color_sp)
			free_double(game->p->color_sp);
		if (game->p->text_sp)
			free_double(game->p->text_sp);
		if (game->p->map_sp)
			free_double(game->p->map_sp);
	}
	game = NULL;
	exit(status);
}

static void	set(t_config *config)
{
	if (config->checker == 2)
	{
		config->dirx = 1;
		config->diry = 0;
		config->planex = 0;
		config->planey = -0.66;
	}
	if (config->checker == 3)
	{
		config->dirx = 0;
		config->diry = -1;
		config->planex = -0.66;
		config->planey = 0;
	}
}

void	set_config(t_config *config)
{
	if (config->checker == 0)
	{
		config->dirx = -1;
		config->diry = 0;
		config->planex = 0;
		config->planey = 0.66;
	}
	if (config->checker == 1)
	{
		config->dirx = 0;
		config->diry = 1;
		config->planex = 0.66;
		config->planey = 0;
	}
	set(config);
}

void	init_structs(t_ms *game, t_parse *parse, t_mlx *mlx, t_config *config)
{
	ft_bzero(game, sizeof(t_ms));
	ft_bzero(parse, sizeof(t_parse));
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(config, sizeof(t_config));
	set_config(config);
	game->config = config;
	game->mlx = mlx;
	game->p = parse;
}
