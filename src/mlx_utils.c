/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:11:51 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/18 20:46:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	key_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
	{
		cleanup(cub3d);
		exit(0);
	}
	if (keycode == W)
		cub3d->ppos_y -= PLAYER_SPEED;
	if (keycode == S)
		cub3d->ppos_y += PLAYER_SPEED;
	if (keycode == A)
		cub3d->ppos_x -= PLAYER_SPEED;
	if (keycode == D)
		cub3d->ppos_x += PLAYER_SPEED;
	return (0);
}

static int	mouse_close(t_cub3d *cub3d)
{
	cleanup(cub3d);
	exit(0);
	return (0);
}

void	setup_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx->win_ptr, KEY_PRESS, 1L << 0, key_hook, cub3d);
	mlx_hook(cub3d->mlx->win_ptr, CLOSE_BUTTON, 1L << 17, mouse_close, cub3d);
}
