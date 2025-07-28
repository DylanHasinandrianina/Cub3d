/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:19:40 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/28 15:56:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_texture_x(t_cub3d *cub3d)
{
	if (cub3d->side == 0)
		cub3d->wall_x = (cub3d->ppos_y / cub3d->tile_size) + cub3d->wall_dist
			* cub3d->raydir_y;
	else
		cub3d->wall_x = (cub3d->ppos_x / cub3d->tile_size) + cub3d->wall_dist
			* cub3d->raydir_x;
	cub3d->wall_x -= floor(cub3d->wall_x);
	cub3d->tex_x = (int)(cub3d->wall_x * (double)TEXTURE_WIDTH);
	if (cub3d->side == 0 && cub3d->raydir_x > 0)
		cub3d->tex_x = TEXTURE_WIDTH - cub3d->tex_x - 1;
	if (cub3d->side == 1 && cub3d->raydir_y < 0)
		cub3d->tex_x = TEXTURE_WIDTH - cub3d->tex_x - 1;
}

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
