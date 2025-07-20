/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 00:11:21 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/20 15:44:59 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/** Draws a single cell of the map with a margin to create a grid effect.
The color to draw the cell (e.g., BLACK for walls, WHITE for floor). */
static void	draw_cell(t_cub3d *ptr, int x, int y, int color)
{
	int	tile_y;
	int	tile_x;
	int	margin;
	int	offset_x;
	int	offset_y;

	offset_x = 0;
	offset_y = (SIZE_H - (ptr->info->map_height * ptr->tile_size)) / 2;
	margin = 1;
	tile_y = y * ptr->tile_size + margin - 1;
	while (++tile_y < (y * ptr->tile_size) + ptr->tile_size - margin)
	{
		tile_x = x * ptr->tile_size + margin - 1;
		while (++tile_x < (x * ptr->tile_size) + ptr->tile_size - margin)
		{
			ft_pixel_put(ptr->mlx->img, offset_x + tile_x, offset_y + tile_y,
				color);
		}
	}
}

/** Draws the 2D map grid by iterating through every cell.
Calls	draw_cell(void) with different colors for walls and empty spaces. */
void	draw_map(t_cub3d *ptr)
{
	int	y;
	int	x;

	y = -1;
	while (++y < ptr->info->map_height)
	{
		x = -1;
		while (++x < ptr->info->map_width)
		{
			if (ptr->map[y][x] == 1)
				draw_cell(ptr, x, y, BLACK);
			else
				draw_cell(ptr, x, y, WHITE);
		}
	}
}

void	draw_player(t_cub3d *ptr)
{
	int		x;
	int		y;
	double	player_size;
	int		offsets[2];
	int		i;

	offsets[0] = 0;
	offsets[1] = (SIZE_H - (ptr->info->map_height * ptr->tile_size)) / 2;
	player_size = ptr->tile_size / 10.0;
	y = ptr->ppos_y - (player_size / 2);
	while (y < ptr->ppos_y + (player_size / 2))
	{
		x = ptr->ppos_x - (player_size / 2);
		while (x < ptr->ppos_x + (player_size / 2))
		{
			ft_pixel_put(ptr->mlx->img, offsets[0] + x, offsets[1] + y, GREEN);
			x++;
		}
		y++;
	}
	i = -1;
	while (++i < ptr->tile_size / 2)
		ft_pixel_put(ptr->mlx->img, offsets[0] + ptr->ppos_x + ptr->pdir_x * i,
			offsets[1] + ptr->ppos_y + ptr->pdir_y * i, RED);
}
