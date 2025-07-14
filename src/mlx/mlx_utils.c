/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:45:08 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/13 12:32:27 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		cleanup(game);
		exit(0);
	}
	return (0);
}

static int	close_btn(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

void	init_mlx(t_game *game)
{
	game->mlx = calloc(1, sizeof(t_mlx));
	if (!game->mlx)
		err_exit("malloc, game->mlx at init_mlx", game);
	game->mlx->mlx_ptr = mlx_init();
	if (!game->mlx->mlx_ptr)
		err_exit("Failed to initialize MiniLibX", game);
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, SIZE_W, SIZE_H,
			"Cub3D");
	if (!game->mlx->win_ptr)
		err_exit("Failed to initialize MiniLibX window", game);
	game->img = calloc(1, sizeof(t_img));
	if (!game->img)
		err_exit("malloc, game->img at init_mlx", game);
	game->img->img_ptr = mlx_new_image(game->mlx->mlx_ptr, SIZE_W, SIZE_H);
	if (!game->img->img_ptr)
		err_exit("Failed to create image", game);
	game->img->addr = mlx_get_data_addr(game->img->img_ptr,
			&game->img->bits_per_pixel, &game->img->line_len,
			&game->img->endian);
	if (!game->img->addr)
		err_exit("Failed to get image address", game);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx->win_ptr, KEY_PRESS, 1L << 0, key_hook, game);
	mlx_hook(game->mlx->win_ptr, CLOSE_BUTTON, 1L << 17, close_btn, game);
}
