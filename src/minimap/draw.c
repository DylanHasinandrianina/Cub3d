/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:56:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
#define MINIMAP_SCALE 8

typedef struct s_minimap
{
	t_img	*img;
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_minimap;

typedef struct s_circle
{
	double	center_x;
	double	center_y;
	double	radius;
	int		color;
}			t_circle;
*/

void	draw_circle(t_circle *circle)
{
	int	y;
	int	x;
	int	radius;
	int	dist_squared;

	radius = circle->radius * circle->radius;
	y = circle->center_y - circle->radius;
	while (y <= circle->center_y + radius)
	{
		x = circle->center_x - circle->radius;
		while (x <= circle->center_x + radius)
		{
			dist_squared = (x - circle->center_x) * (x - circle->center_x) + (y
					- circle->center_y) * (y - circle->center_y);
			if (dist_squared <= radius)
			{
				if (x >= 0 && x < SIZE_W && y >= 0 && y < SIZE_H)
					put_pixel_to_img(circle->img, x, y, circle->color);
			}
			x++;
		}
		y++;
	}
}

void	draw_rect(t_minimap *minimap)
{
	int	curr_y;
	int	curr_x;

	curr_y = minimap->y;
	while (curr_y < minimap->y + minimap->height)
	{
		curr_x = minimap->x;
		while (curr_x < minimap->x + minimap->width)
		{
			if (curr_x >= 0 && curr_x < SIZE_W && curr_y >= 0
				&& curr_y < SIZE_H)
			{
				put_pixel_to_img(minimap->img, curr_x, curr_y, minimap->color);
			}
			curr_x++;
		}
		curr_y++;
	}
}
