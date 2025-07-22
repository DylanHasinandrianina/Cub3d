/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:19:40 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/22 16:25:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_single_texture(t_cub3d *cub3d, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->img)
		error_exit("failed to load texture", cub3d);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}

void	load_textures(t_cub3d *cub3d)
{
	load_single_texture(cub3d, &cub3d->textures[0],
		cub3d->info->north_texture_path);
	load_single_texture(cub3d, &cub3d->textures[1],
		cub3d->info->south_texture_path);
	load_single_texture(cub3d, &cub3d->textures[2],
		cub3d->info->west_texture_path);
	load_single_texture(cub3d, &cub3d->textures[3],
		cub3d->info->east_texture_path);
	return ;
}
