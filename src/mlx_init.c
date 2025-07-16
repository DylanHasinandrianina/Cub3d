/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:12:27 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/16 20:26:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_cub3d *cub3d)
{
	int	y;
	int	x;

	cub3d->mlx->mlx_ptr = mlx_init();
	cub3d->mlx->win_ptr = mlx_new_window(cub3d->mlx->mlx_ptr, SIZE_W, SIZE_H,
			"Cub3D");
	cub3d->mlx->img->img = mlx_new_image(cub3d->mlx->mlx_ptr, SIZE_W, SIZE_H);
	cub3d->mlx->img->addr = mlx_get_data_addr(cub3d->mlx->img->img,
			&cub3d->mlx->img->bits_per_pixel, &cub3d->mlx->img->line_length,
			&cub3d->mlx->img->endian);
	y = -1;
	while (++y < SIZE_H)
	{
		x = -1;
		while (++x < SIZE_W)
			ft_pixel_put(cub3d->mlx->img, x, y, GRAY);
	}
	mlx_put_image_to_window(cub3d->mlx->mlx_ptr, cub3d->mlx->win_ptr,
		cub3d->mlx->img->img, 0, 0);
}
