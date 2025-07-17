/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:16:16 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/16 18:10:16 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_game *game)
{
	free(game->texture->no);
	free(game->texture->so);
	free(game->texture->ea);
	free(game->texture->we);
}

int	check_error(char **file, t_game *game)
{
	if (check_element_validity(file))
		return (1);
	if (check_missing_element(file))
		return (1);
	if (check_map_position(file))
		return (1);
	if (check_duplicate_elements(file))
		return (1);
	if (check_texture_path(file, game))
		return (1);
	if (check_color_validity(file, game))
	{
		ft_putstr_fd("Error\ninvalid color format\n", 2);
		free_texture(game);
		return (1);
	}
	if (check_map_validity(file, game))
	{
		free_texture(game);
		return (1);
	}
	return (0);
}
