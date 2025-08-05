/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:35:29 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/05 13:36:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	process_player_direction(t_cub3d *cub3d, int x, int y, char *line)
{
	cub3d->map[y][x] = 0;
	cub3d->ppos_x = (x * cub3d->tile_size) + (cub3d->tile_size / 2.0);
	cub3d->ppos_y = (y * cub3d->tile_size) + (cub3d->tile_size / 2.0);
	if (line[x] == 'N')
	{
		cub3d->pdir_y = -1;
		cub3d->plane_x = 0.66;
	}
	else if (line[x] == 'S')
	{
		cub3d->pdir_y = 1;
		cub3d->plane_x = -0.66;
	}
	else if (line[x] == 'W')
	{
		cub3d->pdir_x = -1;
		cub3d->plane_y = -0.66;
	}
	else if (line[x] == 'E')
	{
		cub3d->pdir_x = 1;
		cub3d->plane_y = 0.66;
	}
}

/**
 * Processes a single row of the map, converting characters to integers.
 * This function iterates through each character of a map line, converting
 * '0', '1', and player characters into their corresponding integer values
 * in the game's `int**` map grid. Spaces (' ') and any out-of-bounds
 * areas are treated as walls ('1').
 */
void	process_map_line(t_cub3d *cub3d, char *line, int y)
{
	int		x;
	size_t	len;

	len = ft_strlen(line);
	cub3d->map[y] = ft_calloc(cub3d->info->map_width, sizeof(int));
	if (!cub3d->map[y])
		error_exit("malloc, process_map_line()", cub3d);
	x = -1;
	while (++x < cub3d->info->map_width)
	{
		if (x < (int)len && line[x] == ' ')
			cub3d->map[y][x] = 1;
		else if (x < (int)len && ft_isdigit(line[x]))
			cub3d->map[y][x] = line[x] - '0';
		else if (x < (int)len && is_player(line[x]))
			process_player_direction(cub3d, x, y, line);
		else
			cub3d->map[y][x] = 1;
	}
}
