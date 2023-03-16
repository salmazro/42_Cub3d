/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:08:18 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_walls(t_ms *game)
{
	int	i;

	i = -1;
	while (game->p->map_sp[++i])
		if ((game->p->map_sp[i][0] != '1' && game->p->map_sp[i][0] != ' ')
			|| (game->p->map_sp[i][ft_strlen(game->p->map_sp[i]) - 1] != '1'
				&& game->p->map_sp[i][ft_strlen(game->p->map_sp[i]) - 1] \
					!= ' '))
			ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
	i = -1;
	while (++i < (int)ft_strlen(game->p->map_sp[0]))
		if (game->p->map_sp[0][i] != '1' && game->p->map_sp[0][i] != ' ')
			ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
	i = -1;
	while (++i < (int)ft_strlen(game->p->map_sp[ft_strlenn(game->p->map_sp) \
			- 1]))
		if (game->p->map_sp[ft_strlenn(game->p->map_sp) - 1][i] != '1'
			&& game->p->map_sp[ft_strlenn(game->p->map_sp) - 1][i] != ' ')
			ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
}

static void	check_space_norm(t_ms *game, int *i, int *a)
{
	if (game->p->map_sp[*a][*i + 1] && \
			(game->p->map_sp[*a][*i + 1] != '1' \
			&& game->p->map_sp[*a][*i + 1] != ' '))
		ft_error("Invalid map", "map is open on space", 1, game);
	if (i != 0 && game->p->map_sp[*a][*i - 1] && (game->p->map_sp[*a][*i
			- 1] != '1' && game->p->map_sp[*a][*i - 1] != ' '))
		ft_error("Invalid map", "map is open on space", 1, game);
	if (game->p->map_sp[*a + 1] && game->p->map_sp[*a + 1][*i]
		&& (game->p->map_sp[*a + 1][*i] != '1' && game->p->map_sp[*a
			+ 1][*i] != ' '))
		ft_error("Invalid map", "map is open on space", 1, game);
	if (a != 0 && game->p->map_sp[*a - 1] && \
		game->p->map_sp[*a - 1][*i]
		&& (game->p->map_sp[*a - 1][*i] != '1' && game->p->map_sp[*a
			- 1][*i] != ' '))
		ft_error("Invalid map", "map is open on space", 1, game);
}

void	check_space(t_ms *game, int i, int a)
{
	while (game->p->map_sp[++a])
	{
		i = -1;
		while (game->p->map_sp[a][++i])
		{
			if (game->p->map_sp[a][i] == ' ')
				check_space_norm(game, &i, &a);
		}
	}
}

static void	check_zero_norm(t_ms *game, int *i, int *a)
{
	if (!game->p->map_sp[*a][*i + 1] || (game->p->map_sp[*a][*i + 1] == ' '))
		ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
	if (i != 0 && (!game->p->map_sp[*a][*i - 1] || game->p->map_sp[*a][*i
		- 1] == ' '))
		ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
	if (game->p->map_sp[*a + 1] && (!game->p->map_sp[*a + 1][*i]
		|| game->p->map_sp[*a + 1][*i] == ' '))
		ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
	if (a != 0 && game->p->map_sp[*a - 1] && (!game->p->map_sp[*a - 1][*i]
		|| (game->p->map_sp[*a - 1][*i] == ' ')))
		ft_error("Invalid map", "map is open", EXIT_FAILURE, game);
}

void	check_zero(t_ms *game)
{
	int	i;
	int	a;

	a = -1;
	while (game->p->map_sp[++a])
	{
		i = -1;
		while (game->p->map_sp[a][++i])
		{
			if (game->p->map_sp[a][i] == '0')
				check_zero_norm(game, &i, &a);
		}
	}
}
