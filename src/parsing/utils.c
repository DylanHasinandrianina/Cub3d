/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:45:45 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/15 19:26:49 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_texture_or_color_line(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "NO", 2) && ft_isspace(line[i + 2]))
		return (1);
	else if (!ft_strncmp(&line[i], "SO", 2) && ft_isspace(line[i + 2]))
		return (2);
	else if (!ft_strncmp(&line[i], "WE", 2) && ft_isspace(line[i + 2]))
		return (3);
	else if (!ft_strncmp(&line[i], "EA", 2) && ft_isspace(line[i + 2]))
		return (4);
	else if (line[i] == 'F' && ft_isspace(line[i + 1]))
		return (5);
	else if ((line[i] == 'C') && ft_isspace(line[i + 1]))
		return (6);
	return (0);
}

int	is_map_elem(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	free_partial_lines(char **content, int i)
{
	while (--i >= 0)
		free(content[i]);
	free(content);
}
