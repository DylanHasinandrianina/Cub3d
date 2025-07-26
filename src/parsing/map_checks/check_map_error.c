/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:22:16 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/26 11:30:49 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	is_map_closed(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_player(map[y][x]))
			{
				if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1])
					return (ft_putstr_fd("Error\nunclosed map\n", 2), 0);
				if (map[y + 1][x] == ' ' || map[y - 1][x] == ' ' || map[y][x
					+ 1] == ' ' || map[y][x - 1] == ' ')
					return (ft_putstr_fd("Error\nunclosed map\n", 2), 0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	is_one_player(char **map)
{
	int	x;
	int	y;
	int	found;

	y = 0;
	found = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
				found++;
			x++;
		}
		y++;
	}
	if (found != 1)
		return (0);
	return (1);
}

static int	is_valid_map_elem(char **map)
{
	int	x;
	int	y;
	int	empty_line_started;

	empty_line_started = 0;
	y = 0;
	while (map[y])
	{
		if (is_empty_line(map[y]))
			empty_line_started = 1;
		else if (empty_line_started)
			return (0);
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' '
				&& !is_player(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map_validity(char **file, t_mapinfo *info)
{
	char	**map;
	char	**array;

	info->map_lines = get_map(file);
	if (!info->map_lines)
		return (1);
	array = list_to_array(info->map_lines);
	if (!array)
		return (1);
	map = normalize_map(array);
	if (!map)
		return (free_split(array), 1);
	if (is_map_closed(map) == 0)
		return (free_split(map), free_split(array), 1);
	if (is_one_player(map) == 0)
	{
		ft_putstr_fd("Error\nmissing or more than one player\n", 2);
		return (free_split(array), free_split(map), 1);
	}
	if (is_valid_map_elem(map) == 0)
	{
		ft_putstr_fd("Error\ninvalid map character or empty line in map\n", 2);
		return (free_split(array), free_split(map), 1);
	}
	return (free_split(array), free_split(map), 0);
}
