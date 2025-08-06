/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:16:16 by shasinan          #+#    #+#             */
/*   Updated: 2025/08/06 11:10:41 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_texture(t_mapinfo *info)
{
	free(info->north_texture_path);
	free(info->south_texture_path);
	free(info->east_texture_path);
	free(info->west_texture_path);
}

int	check_error(char **file, t_mapinfo *info)
{
	if (check_element_validity(file))
		return (1);
	if (check_missing_element(file))
		return (1);
	if (check_map_position(file))
		return (1);
	if (check_duplicate_elements(file))
		return (1);
	if (check_texture_path(file, info))
		return (1);
	if (check_color_validity(file, info))
		return (1);
	if (check_map_validity(file, info))
		return (1);
	return (0);
}
