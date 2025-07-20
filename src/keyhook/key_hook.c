/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:57:30 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/20 15:23:27 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
		error_exit("Closing game.", cub3d);
	handle_wasd(keycode, cub3d);
	handle_arrow_keys(keycode, cub3d);
	return (0);
}
