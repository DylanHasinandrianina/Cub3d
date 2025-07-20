/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:26:49 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/20 19:28:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calculate_ray_directions(t_cub3d *cub3d, int x)
{
	cub3d->camera_x = 2 * x / (double)SIZE_W - 1;
	cub3d->raydir_x = cub3d->pdir_x + cub3d->plane_x * cub3d->camera_x;
	cub3d->raydir_y = cub3d->pdir_y + cub3d->plane_y * cub3d->camera_x;
	cub3d->map_x = (int)(cub3d->ppos_x / cub3d->tile_size);
	cub3d->map_y = (int)(cub3d->ppos_y / cub3d->tile_size);
}

static void	calculate_delta_distance(t_cub3d *cub3d)
{
	if (cub3d->raydir_x == 0)
		cub3d->delta_dis_x = 1e30;
	else
		cub3d->delta_dis_x = fabs(1 / cub3d->raydir_x);
	if (cub3d->raydir_y == 0)
		cub3d->delta_dis_y = 1e30;
	else
		cub3d->delta_dis_y = fabs(1 / cub3d->raydir_y);
}

void	draw_world(t_cub3d *ptr)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = -1;
	while (++x < SIZE_W)
	{
		calculate_ray_directions(ptr, x);
	}
	return ;
}
