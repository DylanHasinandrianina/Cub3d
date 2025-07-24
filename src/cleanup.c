/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:37:28 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/24 13:50:17 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_map_info(t_mapinfo *info)
{
	if (!info)
		return ;
	free(info->north_texture_path);	
	free(info->south_texture_path);
	free(info->west_texture_path);
	free(info->east_texture_path);
	ft_lstclear(&info->map_lines, free);
	free(info);
}

static void	free_map_grid(t_cub3d *ptr)
{
	int	y;

	if (!ptr->map)
		return ;
	y = 0;
	while (y < ptr->info->map_height)
	{
		free(ptr->map[y]);
		y++;
	}
	free(ptr->map);
}

void	error_exit(char *msg, t_cub3d *ptr)
{
	if (msg)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(msg, 2);
	}
	cleanup(ptr);
	exit(1);
}

void	cleanup(t_cub3d *ptr)
{
	if (!ptr)
		return ;
	if (ptr->mlx)
	{
		if (ptr->mlx->mlx_ptr)
		{
			if (ptr->mlx->img && ptr->mlx->img->img)
				mlx_destroy_image(ptr->mlx->mlx_ptr, ptr->mlx->img->img);
			if (ptr->mlx->win_ptr)
				mlx_destroy_window(ptr->mlx->mlx_ptr, ptr->mlx->win_ptr);
			mlx_destroy_display(ptr->mlx->mlx_ptr);
			free(ptr->mlx->mlx_ptr);
		}
		if (ptr->mlx->img)
			free(ptr->mlx->img);
		free(ptr->mlx);
	}
	free_map_grid(ptr);
	free_map_info(ptr->info);
	free(ptr);
}
