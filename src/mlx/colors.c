/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:32:05 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/13 12:36:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	ft_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dest;

	dest = game->img->addr + (y * game->img->line_len + x
			* (game->img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
