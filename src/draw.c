/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:29:33 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/18 20:35:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_cub3d *ptr)
{
	int	x;
	int	y;
	int	player_size;

	player_size = 12;
	y = ptr->ppos_y - (player_size / 2);
	while (y < ptr->ppos_y + (player_size / 2))
	{
		x = ptr->ppos_x - (player_size / 2);
		while (x < ptr->ppos_x + (player_size / 2))
		{
			ft_pixel_put(ptr->mlx->img, x, y, GREEN);
			x++;
		}
		y++;
	}
}
