/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:45:31 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/19 23:46:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_background(t_cub3d *ptr)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SIZE_H)
	{
		x = -1;
		while (++x < SIZE_W / 2)
			ft_pixel_put(ptr->mlx->img, x, y, 0x222222);
		while (x < SIZE_W)
		{
			ft_pixel_put(ptr->mlx->img, x, y, GRAY);
			x++;
		}
	}
}

int	render_frame(t_cub3d *ptr)
{
	draw_background(ptr);
	draw_map(ptr);
	draw_player(ptr);
	mlx_put_image_to_window(ptr->mlx->mlx_ptr, ptr->mlx->win_ptr,
		ptr->mlx->img->img, 0, 0);
	return (0);
}
