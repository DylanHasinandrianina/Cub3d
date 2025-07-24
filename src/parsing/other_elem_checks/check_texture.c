/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:51:07 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/24 14:51:17 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	assign_texture(t_mapinfo *info, int id, char *path)
{
	if (id == 1)
		info->north_texture_path = ft_strdup(path);
	else if (id == 2)
		info->south_texture_path = ft_strdup(path);
	else if (id == 3)
		info->west_texture_path = ft_strdup(path);
	else if (id == 4)
		info->east_texture_path = ft_strdup(path);
	free(path);
	if ((id == 1 && !info->north_texture_path) || (id == 2
			&& !info->south_texture_path) || (id == 3
			&& !info->west_texture_path) || (id == 4
			&& !info->east_texture_path))
		return (0);
	return (1);
}

static int	check_texture_line_validity(char **split, int id, t_mapinfo *info)
{
	int		fd;
	char	*path;

	if (!split[1] || !ft_strcmp(split[1], "\n") || split[2])
		return (ft_putstr_fd("Error\nTexture must have 2 tokens\n", 2), 0);
	path = ft_strtrim(split[1], " \t\r\n");
	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid texture path: ", 2);
		ft_putendl_fd(path, 2);
		return (free(path), 0);
	}
	close(fd);
	return (assign_texture(info, id, path));
}

int	check_texture_path(char **file, t_mapinfo *info)
{
	int		i;
	char	**split;
	int		id;

	i = 0;
	while (file[i])
	{
		if (!is_empty_line(file[i]))
		{
			id = is_texture_or_color_line(file[i]);
			if (id > 0 && id < 5)
			{
				split = ft_split(file[i], ' ');
				if (!split || !check_texture_line_validity(split, id, info))
					return (free_split(split), 1);
				free_split(split);
			}
		}
		i++;
	}
	return (0);
}
