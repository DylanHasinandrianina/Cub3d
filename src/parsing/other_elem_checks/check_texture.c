/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:42:55 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/30 15:43:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	assign_texture(t_mapinfo *info, t_identifier id, char *path)
{
	if (id == ID_NORTH)
		info->north_texture_path = path;
	else if (id == ID_SOUTH)
		info->south_texture_path = path;
	else if (id == ID_WEST)
		info->west_texture_path = path;
	else if (id == ID_EAST)
		info->east_texture_path = path;
	else
	{
		free(path);
		return (0);
	}
	return (1);
}

static int	validate_and_assign_path(char *line, t_identifier id,
		t_mapinfo *info)
{
	int		i;
	int		fd;
	char	*path;

	i = 0;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (ft_putstr_fd("Error\nMissing texture path\n", 2), 0);
	path = ft_strtrim(&line[i], " \t\r\n");
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
	int				i;
	t_identifier	id;
	int				j;

	i = 0;
	while (file[i])
	{
		id = is_texture_or_color_line(file[i]);
		if (id >= ID_NORTH && id <= ID_EAST)
		{
			j = 0;
			while (ft_isspace(file[i][j]))
				j++;
			if (!validate_and_assign_path(&file[i][j], id, info))
				return (1);
		}
		i++;
	}
	return (0);
}
