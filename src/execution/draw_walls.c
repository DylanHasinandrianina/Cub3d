/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:49:29 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/25 14:50:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/** Draws a solid background rectangle for the minimap.*/
void	draw_minimap_background(t_cub3d *ptr)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = ptr->info->map_width * ptr->tile_size;
	height = ptr->info->map_height * ptr->tile_size;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			ft_pixel_put(ptr->mlx->img, 20 + x, 20 + y, 0x80000000);
	}
}

/** Calculates the wall's projected distance, its height on screen,
and the start/end drawing coordinates for the vertical slice. */
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

/** Selects the correct wall texture (N, S, E, W). */
static t_texture	*get_wall_texture(t_cub3d *cub3d)
{
	if (cub3d->side == 0 && cub3d->raydir_x < 0)
		return (&cub3d->textures[2]);
	else if (cub3d->side == 0 && cub3d->raydir_x >= 0)
		return (&cub3d->textures[3]);
	else if (cub3d->side == 1 && cub3d->raydir_y < 0)
		return (&cub3d->textures[0]);
	else
		return (&cub3d->textures[1]);
}

/** Draws the pixels for the ceiling, wall, and floor. */
static void	draw_ceiling_wall_floor(t_cub3d *cub3d, t_texture *tex, int x)
{
	double	step;
	double	tex_pos;
	int		y;

	step = 1.0 * tex->height / cub3d->line_height;
	tex_pos = (cub3d->draw_start - (double)SIZE_H / 2
			+ (double)cub3d->line_height / 2) * step;
	y = -1;
	while (++y < SIZE_H)
	{
		if (y < cub3d->draw_start)
			ft_pixel_put(cub3d->mlx->img, x, y, cub3d->info->ceiling_color);
		else if (y < cub3d->draw_end)
		{
			*(unsigned int *)(cub3d->mlx->img->addr + (y
						* cub3d->mlx->img->line_length + x
						* (cub3d->mlx->img->bits_per_pixel
							/ 8))) = *(unsigned int *)(tex->addr
					+ (((int)tex_pos % tex->height) * tex->line_length
						+ cub3d->tex_x * (tex->bits_per_pixel / 8)));
			tex_pos += step;
		}
		else
			ft_pixel_put(cub3d->mlx->img, x, y, cub3d->info->floor_color);
	}
}

/** Orchestrates the drawing of a single vertical slice. */
void	draw_slice(t_cub3d *cub3d, int x)
{
	t_texture	*texture;

	texture = get_wall_texture(cub3d);
	draw_ceiling_wall_floor(cub3d, texture, x);
}
