/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:04:11 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/22 15:47:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Calculate distance projected on camera direction (Euclidean distance would
give fisheye effect!)
Calculate height of line to draw on screen
Calculate lowest and highest pixel to fill in current stripe */
void	calculate_wall_height(t_cub3d *cub3d)
{
	if (cub3d->side == 0)
		cub3d->wall_dist = (cub3d->side_dist_x - cub3d->delta_dis_x);
	else
		cub3d->wall_dist = (cub3d->side_dist_y - cub3d->delta_dis_y);
	cub3d->line_height = (int)(SIZE_H / cub3d->wall_dist);
	cub3d->draw_start = -cub3d->line_height / 2 + SIZE_H / 2;
	if (cub3d->draw_start < 0)
		cub3d->draw_start = 0;
	cub3d->draw_end = cub3d->line_height / 2 + SIZE_H / 2;
	if (cub3d->draw_end >= SIZE_H)
		cub3d->draw_end = SIZE_H - 1;
}

/** Draw ceiling, draw the wall slice, draw floor */
void	draw_slice(t_cub3d *cub3d, int x)
{
	int	y;

	y = 0;
	while (y < cub3d->draw_end)
	{
		ft_pixel_put(cub3d->mlx->img, x, y, cub3d->info->ceiling_color);
		y++;
	}
	while (y < cub3d->draw_end)
	{
		if (cub3d->side == 1)
			ft_pixel_put(cub3d->mlx->img, x, y, RED);
		else
			ft_pixel_put(cub3d->mlx->img, x, y, BLUE);
		y++;
	}
	while (y < SIZE_H)
	{
		ft_pixel_put(cub3d->mlx->img, x, y, cub3d->info->floor_color);
		y++;
	}
}
