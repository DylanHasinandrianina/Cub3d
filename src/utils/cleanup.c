/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:34:21 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/14 15:37:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_textures(t_texture *ptr)
{
	if (!ptr)
		return ;
	free(ptr->no);
	free(ptr->so);
	free(ptr->we);
	free(ptr->ea);
	free(ptr);
}

int	cleanup(t_game *game)
{
	if (!game)
		return (0);
	free_textures(game->texture);
	free_map(game->map);
	free(game->player);
	free(game->color);
	if (game->mlx && game->mlx->mlx_ptr)
	{
		if (game->img && game->img->img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->img->img_ptr);
		if (game->mlx->win_ptr)
			mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		mlx_destroy_display(game->mlx->mlx_ptr);
	}
	free(game->img);
	free(game->mlx);
	free(game->minimap);
	free(game);
	return (0);
}

void	err_exit(char *msg, t_game *game)
{
	if (msg)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(msg, 2);
	}
	cleanup(game);
	exit(1);
}
