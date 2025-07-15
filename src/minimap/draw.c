/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:56:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 13:40:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <unistd.h>

/*
#define MINIMAP_SCALE 8

typedef struct s_minimap
{
	t_img	*img;
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_minimap;
*/

static void	draw_circle(void)
{
	t_circle	circle;
}

static void	draw_rect(t_minimap *minimap)
{
	int	curr_y;
	int	curr_x;

	curr_y = minimap->y;
	while (curr_y < minimap->y + minimap->height)
	{
		curr_x = minimap->x;
		while (curr_x < minimap->x + minimap->width)
		{
			if (curr_x >= 0 && curr_x < SIZE_W && curr_y >= 0
				&& curr_y < SIZE_H)
			{
				put_pixel_to_img(minimap->img, curr_x, curr_y, minimap->color);
			}
			curr_x++;
		}
		curr_y++;
	}
}

void	draw_minimap(t_game *game)
{
	int	map_y;
	int	map_x;

	map_y = 0;
	while (game->map[map_y])
	{
		map_x = 0;
		while (game->map[map_y][map_x])
		{
			if (game->map[map_y][map_x] == '1')
				game->minimap->color = 0x333333;
			else
				game->minimap->color = 0xCCCCCC;
			game->minimap->x = map_x * MINIMAP_SCALE;
			game->minimap->y = map_y * MINIMAP_SCALE;
			game->minimap->width = MINIMAP_SCALE;
			game->minimap->height = MINIMAP_SCALE;
			draw_rect(game->minimap);
			map_x++;
		}
		map_y++;
	}
}
