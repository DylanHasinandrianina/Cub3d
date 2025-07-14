/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:20:24 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/12 15:05:12 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_map(t_game *game)
{
	game->map[0] = ft_strdup("11111111");
	game->map[1] = ft_strdup("10000101");
	game->map[2] = ft_strdup("10N00101");
	game->map[3] = ft_strdup("10000001");
	game->map[4] = ft_strdup("11111111");
	game->map[5] = NULL;
}

static void	init_player(t_game *game)
{
	game->player->x = 2.5;
	game->player->y = 2.5;
	game->player->dir = -M_PI / 2;
}

static void	init_textures(t_game *game)
{
	game->texture->no = ft_strdup("textures/wall_n.xpm");
	game->texture->so = ft_strdup("textures/wall_s.xpm");
	game->texture->we = ft_strdup("textures/wall_w.xpm");
	game->texture->ea = ft_strdup("textures/wall_e.xpm");
}

static void	init_colors(t_game *game)
{
	game->color->floor = 0xDC6400;
	game->color->ceiling = 0xE11E00;
}

t_game	*init_mock_data(void)
{
	t_game	*game;

	game = calloc(1, sizeof(t_game));
	if (!game)
		return (ft_putendl_fd("error: malloc, init_mock_data", 2), NULL);
	game->player = calloc(1, sizeof(t_player));
	game->texture = calloc(1, sizeof(t_texture));
	game->color = calloc(1, sizeof(t_color));
	game->map = calloc(6, sizeof(char *));
	if (!game->player || !game->texture || !game->color || !game->map)
	{
		free(game->player);
		free(game->texture);
		free(game->color);
		free(game->map);
		free(game);
		return (ft_putendl_fd("error: malloc, init_mock_data", 2), NULL);
	}
	init_map(game);
	init_player(game);
	init_textures(game);
	init_colors(game);
	game->mlx = NULL;
	game->img = NULL;
	return (game);
}
