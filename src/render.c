/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:23:18 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/14 16:07:27 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_frame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < SIZE_H)
	{
		x = 0;
		while (x < SIZE_W)
		{
			if (y < SIZE_H / 2)
				put_pixel_to_img(game->img, x, y, game->color->ceiling);
			else
				put_pixel_to_img(game->img, x, y, game->color->floor);
			x++;
		}
		y++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->img->img_ptr, 0, 0);
	return (0);
}
