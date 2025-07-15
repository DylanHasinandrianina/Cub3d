/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:22:24 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/15 20:18:28 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_game *game)
{
	game->map[0] = ft_strdup("11111111");
	game->map[1] = ft_strdup("10000101");
	game->map[2] = ft_strdup("10100S01");
	game->map[3] = ft_strdup("10000001");
	game->map[4] = ft_strdup("11111111");
	game->map[5] = NULL;
}

void	init_textures(t_game *game)
{
	game->texture->no = ft_strdup("textures/wall_n.xpm");
	game->texture->so = ft_strdup("textures/wall_s.xpm");
	game->texture->we = ft_strdup("textures/wall_w.xpm");
	game->texture->ea = ft_strdup("textures/wall_e.xpm");
}

void	init_colors(t_game *game)
{
	game->color->floor = 0xDC6400;
	game->color->ceiling = 0xE11E00;
}

/* WARNING: remeber to adjust the map width and height connected to the init_map
 * function*/
void	init_minimap(t_game *game)
{
	game->minimap->img = game->img;
	game->minimap->x = MINIMAP_SCALE;
	game->minimap->y = MINIMAP_SCALE;
	game->minimap->color = 0xFF0000;
}
