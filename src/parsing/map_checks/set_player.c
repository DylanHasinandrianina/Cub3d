/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:29:27 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/17 13:01:30 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_direction(t_game *game, char c)
{
	if (c == 'N')
		game->player->dir = -M_PI_2;
	else if (c == 'S')
		game->player->dir = M_PI_2;
	else if (c == 'E')
		game->player->dir = 0;
	else if (c == 'W')
		game->player->dir = M_PI;
}

void	set_player_position(t_game *game, char **map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				game->player->x = x + 0.5;
				game->player->y = y + 0.5;
				c = map[y][x];
				set_player_direction(game, c);
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
