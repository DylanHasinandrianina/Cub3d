/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:37:28 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/16 21:15:23 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// In cleanup.c

#include "../includes/cub3d.h"

void	error_exit(char *msg, t_cub3d *ptr)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
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
	free(ptr);
}
