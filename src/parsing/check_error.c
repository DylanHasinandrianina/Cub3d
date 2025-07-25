/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:16:16 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/25 13:26:28 by mgodawat         ###   ########.fr       */
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
	{
		ft_putstr_fd("Error\ninvalid color format\n", 2);
		return (1);
	}
	if (check_map_validity(file, info))
		return (1);
	return (0);
}
