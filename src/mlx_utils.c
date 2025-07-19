/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 00:20:10 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/20 00:21:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static int	is_wall(t_cub3d *cub3d, int x, int y)
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

static int	key_hook(int keycode, t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;
	double	hitbox_padding;

	if (keycode == KEY_ESC)
		error_exit("Closing game.", cub3d);
	new_x = cub3d->ppos_x;
	new_y = cub3d->ppos_y;
	hitbox_padding = cub3d->tile_size / 8.0;
	if (keycode == W)
		new_y -= PLAYER_SPEED;
	if (keycode == S)
		new_y += PLAYER_SPEED;
	if (keycode == A)
		new_x -= PLAYER_SPEED;
	if (keycode == D)
		new_x += PLAYER_SPEED;
	if (is_wall(cub3d, new_x + hitbox_padding, new_y + hitbox_padding)
		|| is_wall(cub3d, new_x + hitbox_padding, new_y - hitbox_padding)
		|| is_wall(cub3d, new_x - hitbox_padding, new_y + hitbox_padding)
		|| is_wall(cub3d, new_x - hitbox_padding, new_y - hitbox_padding))
		return (0);
	cub3d->ppos_x = new_x;
	cub3d->ppos_y = new_y;
	return (0);
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
