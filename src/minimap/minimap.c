/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:18:43 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 20:03:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	find_wall(t_game *game, int map_x, int map_y)
{
	if (game->map[map_y][map_x] == '1')
		game->minimap->color = 0x333333;
	else
		game->minimap->color = 0xCCCCCC;
	game->minimap->x = map_x * MINIMAP_SCALE;
	game->minimap->y = map_y * MINIMAP_SCALE;
	game->minimap->width = MINIMAP_SCALE;
	game->minimap->height = MINIMAP_SCALE;
	return ;
}

static void	draw_player_dot(t_game *game, t_circle *player_dot)
{
	player_dot->img = game->img;
	player_dot->center_x = game->player->x * MINIMAP_SCALE;
	player_dot->center_y = game->player->y * MINIMAP_SCALE;
	player_dot->radius = 5;
	player_dot->color = 0xFF0000;
	draw_circle(player_dot);
	return ;
}

void	draw_minimap(t_game *game)
{
	int			map_y;
	int			map_x;
	t_circle	player_dot;

	map_y = 0;
	while (game->map[map_y])
	{
		map_x = 0;
		while (game->map[map_y][map_x])
		{
			find_wall(game, map_x, map_y);
			draw_rect(game->minimap);
			map_x++;
		}
		map_y++;
	}
	draw_player_dot(game, &player_dot);
	draw_player_direction_line(game);
}
