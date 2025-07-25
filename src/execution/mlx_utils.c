/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 00:20:10 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/25 14:41:59 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SIZE_W && y >= 0 && y < SIZE_H)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

static int	mouse_close(t_cub3d *cub3d)
{
	error_exit("Closing game via window button.", cub3d);
	return (0);
}

void	setup_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx->win_ptr, KEY_PRESS, 1L << 0, key_hook, cub3d);
	mlx_hook(cub3d->mlx->win_ptr, CLOSE_BUTTON, 1L << 17, mouse_close, cub3d);
}
