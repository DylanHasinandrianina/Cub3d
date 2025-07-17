/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:48:41 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/16 18:05:27 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_element_validity(char **file)
{
	int	i;
	int	in_map;

	i = 0;
	in_map = 0;
	while (file[i])
	{
		if (is_empty_line(file[i]))
		{
			i++;
			continue ;
		}
		if (is_map_elem(file[i]))
			in_map = 1;
		if (!in_map && !is_map_elem(file[i])
			&& !is_texture_or_color_line(file[i]))
		{
			ft_putstr_fd("Error\ninvalid element: ", 2);
			return (ft_putstr_fd(file[i], 2), 1);
		}
		i++;
	}
	return (0);
}

int	check_missing_element(char **file)
{
	int	i;
	int	count_elem;

	i = 0;
	count_elem = 0;
	while (file[i])
	{
		if (is_empty_line(file[i]))
		{
			i++;
			continue ;
		}
		if (is_texture_or_color_line(file[i]))
			count_elem++;
		i++;
	}
	if (count_elem < 6)
	{
		ft_putstr_fd("Error\nmissing one or many elements\n", 2);
		return (1);
	}
	return (0);
}

static void	update_seen_element(char *line, int *seen)
{
	int	j;

	j = 0;
	while (ft_isspace(line[j]))
		j++;
	if (!ft_strncmp(&line[j], "NO", 2) && ft_isspace(line[j + 2]))
		seen[0]++;
	else if (!ft_strncmp(&line[j], "SO", 2) && ft_isspace(line[j + 2]))
		seen[1]++;
	else if (!ft_strncmp(&line[j], "WE", 2) && ft_isspace(line[j + 2]))
		seen[2]++;
	else if (!ft_strncmp(&line[j], "EA", 2) && ft_isspace(line[j + 2]))
		seen[3]++;
	else if (line[j] == 'F' && ft_isspace(line[j + 1]))
		seen[4]++;
	else if (line[j] == 'C' && ft_isspace(line[j + 1]))
		seen[5]++;
}

int	check_duplicate_elements(char **file)
{
	int	i;
	int	seen[6];

	i = 0;
	while (i < 6)
		seen[i] = 0;
	i = 0;
	while (file[i])
	{
		if (!is_empty_line(file[i]))
			update_seen_element(file[i], seen);
		i++;
	}
	if (seen[0] > 1 || seen[1] > 1 || seen[2] > 1 || seen[3] > 1 || seen[4] > 1
		|| seen[5] > 1)
	{
		ft_putstr_fd("Error\nduplicate element detected\n", 2);
		return (1);
	}
	return (0);
}
