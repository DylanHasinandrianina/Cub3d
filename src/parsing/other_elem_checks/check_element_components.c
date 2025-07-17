/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_components.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:17:13 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/17 13:28:43 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture_line_validity(char **split, int id, t_game *game)
{
	int		fd;
	char	*path;

	if (!split[1] || !ft_strcmp (split[1], "\n") || split[2])
		return (ft_putstr_fd("Error\nTexture must have 2 tokens\n", 2), 0);
	path = split[1];
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid texture path: ", 2);
		return (ft_putstr_fd(path, 2), 0);
	}
	close(fd);
	if (id == 1)
		game->texture->no = ft_strdup(path);
	else if (id == 2)
		game->texture->so = ft_strdup(path);
	else if (id == 3)
		game->texture->we = ft_strdup(path);
	else if (id == 4)
		game->texture->ea = ft_strdup(path);
	if ((id == 1 && !game->texture->no) || (id == 2 && !game->texture->so)
		|| (id == 3 && !game->texture->we) || (id == 4 && !game->texture->ea))
		return (0);
	return (1);
}

int	check_texture_path(char **file, t_game *game)
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
				if (!split || !check_texture_line_validity(split, id, game))
					return (free_split(split), 1);
				free_split(split);
			}
		}
		i++;
	}
	return (0);
}

static int	parse_rgb_components(char *line, char **comp)
{
	int		i;
	int		idx;
	int		len;
	char	*start;

	i = 0;
	idx = 0;
	while (idx < 3)
	{
		i = skip_spaces(line, i);
		if (line[i] == 'F' || line[i] == 'C')
			i++;
		i = skip_spaces(line, i);
		start = &line[i];
		while (ft_isdigit(line[i]))
			i++;
		len = &line[i] - start;
		comp[idx++] = ft_strndup(start, len);
		if (len == 0 || !comp[idx - 1])
			return (0);
		i = skip_spaces(line, i);
		if (idx < 3 && line[i++] != ',')
			return (0);
	}
	return (line[i] == '\n' || line[i] == '\0');
}

static int	set_game_color(t_game *game, int id, char **comp)
{
	t_color_elem	*color;

	color = malloc(sizeof(t_color_elem));
	if (!color || !ft_atoi_strict(comp[0], &color->r)
		|| !ft_atoi_strict(comp[1], &color->g) || !ft_atoi_strict(comp[2],
			&color->b))
		return (free(color), 0);
	if (id == 5)
		game->color->floor = convert_rgb_to_int(color->r, color->g, color->b);
	else
		game->color->ceiling = convert_rgb_to_int(color->r, color->g, color->b);
	free(color);
	return (1);
}

int	check_color_validity(char **file, t_game *game)
{
	int		i;
	int		j;
	char	*comp[3];
	int		id;

	i = 0;
	while (file[i])
	{
		id = is_texture_or_color_line(file[i]);
		if (!is_empty_line(file[i])
			&& (id == 5 || id == 6))
		{
			j = 0;
			while (j < 3)
				comp[j++] = NULL;
			if (!parse_rgb_components(file[i], comp) || !set_game_color(game,
					id, comp))
				return (free(comp[0]), free(comp[1]), free(comp[2]), 1);
			free(comp[0]);
			free(comp[1]);
			free(comp[2]);
		}
		i++;
	}
	return (0);
}
