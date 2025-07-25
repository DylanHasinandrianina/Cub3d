/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:12:32 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/25 14:42:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	keycode_w(double *new_x, double *new_y, int move_speed,
		t_cub3d *cub3d)
{
	*new_x += cub3d->pdir_x * move_speed;
	*new_y += cub3d->pdir_y * move_speed;
}

static void	keycode_s(double *new_x, double *new_y, int move_speed,
		t_cub3d *cub3d)
{
	*new_x -= cub3d->pdir_x * move_speed;
	*new_y -= cub3d->pdir_y * move_speed;
}

static void	keycode_d(double *new_x, double *new_y, int move_speed,
		t_cub3d *cub3d)
{
	*new_x += cub3d->plane_x * move_speed;
	*new_y += cub3d->plane_y * move_speed;
}
static void	keycode_a(double *new_x, double *new_y, int move_speed,
		t_cub3d *cub3d)
{
	*new_x -= cub3d->plane_x * move_speed;
	*new_y -= cub3d->plane_y * move_speed;
}

void	handle_wasd(int keycode, t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = PLAYER_SPEED * 1.5;
	new_x = cub3d->ppos_x;
	new_y = cub3d->ppos_y;
	if (keycode == W)
		keycode_w(&new_x, &new_y, move_speed, cub3d);
	if (keycode == S)
		keycode_s(&new_x, &new_y, move_speed, cub3d);
	if (keycode == D)
		keycode_d(&new_x, &new_y, move_speed, cub3d);
	if (keycode == A)
		keycode_a(&new_x, &new_y, move_speed, cub3d);
	if (!is_wall(cub3d, new_x, cub3d->ppos_y))
		cub3d->ppos_x = new_x;
	if (!is_wall(cub3d, cub3d->ppos_x, new_y))
		cub3d->ppos_y = new_y;
	return ;
}
