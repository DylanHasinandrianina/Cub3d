/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:28:20 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/15 19:42:24 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_element_or_map(char *line, int *in_map, int *count_elem)
{
	if (is_texture_or_color_line(line))
	{
		if (*in_map)
			return (ft_putstr_fd("Error\nelement after map\n", 2), 1);
		(*count_elem)++;
	}
	else if (is_map_elem(line))
	{
		if (*count_elem < 6)
			return (ft_putstr_fd("Error\nmap before elements\n", 2), 1);
		*in_map = 1;
	}
	return (0);
}

int	check_map_position(char **file)
{
	int	i;
	int	in_map;
	int	count_elem;

	i = 0;
	in_map = 0;
	count_elem = 0;
	while (file[i])
	{
		if (!is_empty_line(file[i]))
		{
			if (handle_element_or_map(file[i], &in_map, &count_elem))
				return (1);
		}
		i++;
	}
	if (!in_map)
		return (ft_putstr_fd("Error\nmissing map\n", 2), 1);
	return (0);
}
