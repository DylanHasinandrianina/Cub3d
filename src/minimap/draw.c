/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:56:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 20:15:24 by mgodawat         ###   ########.fr       */
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

static void	draw_line(t_line *line)
{
	double	dx;
	double	dy;
	int		steps;
	double	x_inc;
	double	y_inc;
	double	current_x;
	double	current_y;
	int		i;

	dx = line->x2 - line->x1;
	dy = line->y2 - line->y1;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / (double)steps;
	y_inc = dy / (double)steps;
	current_x = line->x1;
	current_y = line->y1;
	i = 0;
	while (i <= steps)
	{
		put_pixel_to_img(line->img, round(current_x), round(current_y),
			line->color);
		current_x += x_inc;
		current_y += y_inc;
		i++;
	}
}

void	draw_player_direction_line(t_game *game)
{
	t_line	player_dir;

	player_dir.img = game->img;
	player_dir.color = 0xFF0000;
	player_dir.x1 = game->player->x * MINIMAP_SCALE;
	player_dir.y1 = game->player->y * MINIMAP_SCALE;
	player_dir.x2 = (game->player->x * cos(game->player->dir)) * MINIMAP_SCALE;
	player_dir.y2 = (game->player->y * cos(game->player->dir)) * MINIMAP_SCALE;
	draw_line(&player_dir);
}
