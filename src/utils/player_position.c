/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:40:29 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 17:41:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_player_data(t_game *game, int map_y, int map_x)
{
	game->player->x = map_x + 0.5;
	game->player->y = map_y + 0.5;
	if (game->map[map_y][map_x] == 'N')
		game->player->dir = -M_PI / 2;
	else if (game->map[map_y][map_x] == 'S')
		game->player->dir = M_PI / 2;
	else if (game->map[map_y][map_x] == 'W')
		game->player->dir = M_PI;
	else if (game->map[map_y][map_x] == 'E')
		game->player->dir = 0;
	game->map[map_y][map_x] = '0';
}

void	find_player_position(t_game *game)
{
	int map_y;
	int map_x;

	map_y = 0;
	while (game->map[map_y])
	{
		map_x = 0;
		while (game->map[map_y][map_x])
		{
			if (game->map[map_y][map_x] == 'N' || game->map[map_y][map_x] == 'S'
				|| game->map[map_y][map_x] == 'W'
				|| game->map[map_y][map_x] == 'E')
			{
				set_player_data(game, map_y, map_x);
				return ;
			}
			map_x++;
		}
		map_y++;
	}
}