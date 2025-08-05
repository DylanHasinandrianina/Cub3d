/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:45:31 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/05 13:31:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(t_cub3d *cub3d, int x, int y)
{
	int	map_x;
	int	map_y;

	if (cub3d->tile_size == 0)
		return (1);
	map_x = x / cub3d->tile_size;
	map_y = y / cub3d->tile_size;
	if (map_x < 0 || map_x >= cub3d->info->map_width || map_y < 0
		|| map_y >= cub3d->info->map_height)
		return (1);
	return (cub3d->map[map_y][map_x] == 1);
}

int	render_frame(t_cub3d *ptr)
{
	perform_raycaster(ptr);
	draw_minimap_background(ptr);
	draw_map(ptr);
	draw_player(ptr);
	mlx_put_image_to_window(ptr->mlx->mlx_ptr, ptr->mlx->win_ptr,
		ptr->mlx->img->img, 0, 0);
	return (0);
}
