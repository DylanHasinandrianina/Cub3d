/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:45:31 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/19 13:45:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_frame(t_cub3d *ptr)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SIZE_H)
	{
		x = -1;
		while (++x < SIZE_W)
			ft_pixel_put(ptr->mlx->img, x, y, GRAY);
	}
	draw_player(ptr);
	mlx_put_image_to_window(ptr->mlx->mlx_ptr, ptr->mlx->win_ptr,
		ptr->mlx->img->img, 0, 0);
	return (0);
}
