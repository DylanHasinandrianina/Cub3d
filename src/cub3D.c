/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:50:56 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/14 16:16:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	*game;

	game = init_mock_data();
	if (!game)
		return (ft_putendl_fd("error: main", 2), 1);
	init_mlx(game);
	init_minimap(game);
	setup_hooks(game);
	mlx_loop_hook(game->mlx->mlx_ptr, render_frame, game);
	mlx_pixel_put(game->mlx->mlx_ptr, game->mlx->win_ptr, SIZE_W / 2, SIZE_H
		/ 2, 0xFFFFFF);
	mlx_loop(game->mlx->mlx_ptr);
}
