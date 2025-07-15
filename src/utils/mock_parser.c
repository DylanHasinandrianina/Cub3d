/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:20:24 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 17:39:13 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	game->minimap = calloc(1, sizeof(t_minimap));
	if (!game->player || !game->texture || !game->color || !game->map
		|| !game->minimap)
	{
		free(game->player);
		free(game->texture);
		free(game->color);
		free(game->map);
		free(game);
		return (ft_putendl_fd("error: malloc, init_mock_data", 2), NULL);
	}
	init_map(game);
	find_player_position(game);
	init_textures(game);
	init_colors(game);
	return (game);
}
