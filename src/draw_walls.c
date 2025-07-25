/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:04:11 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/25 13:42:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap_background(t_cub3d *ptr)
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	offset_x;
	int	offset_y;

	offset_x = 20;
	offset_y = 20;
	width = ptr->info->map_width * ptr->tile_size;
	height = ptr->info->map_height * ptr->tile_size;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			ft_pixel_put(ptr->mlx->img, offset_x + x, offset_y + y, 0x80000000);
	}
}

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
	t_texture	*texture;
	int			y;
	int			tex_y;
	int			color;
	double		step;
	double		tex_pos;

	if (cub3d->side == 0 && cub3d->raydir_x < 0)
		texture = &cub3d->textures[2];
	else if (cub3d->side == 0 && cub3d->raydir_x >= 0)
		texture = &cub3d->textures[3];
	else if (cub3d->side == 1 && cub3d->raydir_y < 0)
		texture = &cub3d->textures[0];
	else
		texture = &cub3d->textures[1];
	step = 1.0 * texture->height / cub3d->line_height;
	tex_pos = (cub3d->draw_start - (double)SIZE_H / 2
			+ (double)cub3d->line_height / 2) * step;
	y = -1;
	while (++y < SIZE_H)
	{
		if (y < cub3d->draw_start)
			ft_pixel_put(cub3d->mlx->img, x, y, cub3d->info->ceiling_color);
		else if (y < cub3d->draw_end)
		{
			tex_y = (int)tex_pos % texture->height;
			tex_pos += step;
			color = *(unsigned int *)(texture->addr + (tex_y
						* texture->line_length + cub3d->tex_x
						* (texture->bits_per_pixel / 8)));
			ft_pixel_put(cub3d->mlx->img, x, y, color);
		}
		else
			ft_pixel_put(cub3d->mlx->img, x, y, cub3d->info->floor_color);
	}
}
