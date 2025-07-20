/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrowkeys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:13:26 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/20 15:31:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/** this function otates the player's direction and camera plane vectors.
rot_speed The rotation angle in radians. A positive value rotates
left, and a negative value rotates right. */
static void	rotate_player(t_cub3d *cub3d, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->pdir_x;
	cub3d->pdir_x = cub3d->pdir_x * cos(rot_speed) - cub3d->pdir_y
		* sin(rot_speed);
	cub3d->pdir_y = old_dir_x * sin(rot_speed) + cub3d->pdir_y * cos(rot_speed);
	old_plane_x = cub3d->plane_x;
	cub3d->plane_x = cub3d->plane_x * cos(rot_speed) - cub3d->plane_y
		* sin(rot_speed);
	cub3d->plane_y = old_plane_x * sin(rot_speed) + cub3d->plane_y
		* cos(rot_speed);
}

/** Handles left and right arrow key presses for player rotation. */
void	handle_arrow_keys(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_RIGHT)
		rotate_player(cub3d, -ROTATION_SPEED);
	if (keycode == KEY_LEFT)
		rotate_player(cub3d, ROTATION_SPEED);
}
