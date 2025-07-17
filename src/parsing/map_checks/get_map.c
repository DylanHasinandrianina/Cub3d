/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:26:01 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/15 19:51:40 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*trim_line(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static int	count_map_lines(char **file, int start)
{
	int	count;

	count = 0;
	while (file[start])
	{
		count++;
		start++;
	}
	return (count);
}

static int	skip_headers(char **file)
{
	int	i;

	i = 0;
	while (file[i] && (is_empty_line(file[i])
			|| is_texture_or_color_line(file[i])))
		i++;
	return (i);
}

static char	**alloc_and_fill_map(char **file, int start, int len)
{
	char	**map;
	int		k;

	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	k = 0;
	while (k < len)
	{
		map[k] = ft_strdup(file[start + k]);
		if (!map[k])
		{
			while (--k >= 0)
				free(map[k]);
			free(map);
			return (NULL);
		}
		trim_line(map[k]);
		k++;
	}
	map[k] = NULL;
	return (map);
}

char	**get_map(char **file)
{
	int	start;
	int	len;

	start = skip_headers(file);
	len = count_map_lines(file, start);
	return (alloc_and_fill_map(file, start, len));
}
