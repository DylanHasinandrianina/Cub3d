/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:16:44 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/14 18:31:32 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

static int	close_btn(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

void	free_mem(t_game *game)
{
	if (game->mlx)
	{
		free(game->mlx->mlx_ptr);
		free(game->mlx->win_ptr);
	}
}

void	err_exit(char *msg, t_game *game)
{
	free_mem(game);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	init_mlx(t_game *game)
{
	game->mlx->mlx_ptr = mlx_init();
	if (!game->mlx->mlx_ptr)
		err_exit("Failed to initialize MiniLibX", game);
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, 1920, 1080,
			"Cub3D");
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx->win_ptr, KEY_PRESS, 1L << 0, key_hook,
		&game->mlx->mlx_ptr);
	mlx_hook(game->mlx->win_ptr, CLOSE_BUTTON, 1L << 0, close_btn,
		&game->mlx->win_ptr);
}
