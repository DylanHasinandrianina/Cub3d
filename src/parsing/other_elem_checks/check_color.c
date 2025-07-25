/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:17:13 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/25 13:26:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

static int	set_game_color(t_mapinfo *info, int id, char **comp)
{
	t_color_elem	*color;

	color = malloc(sizeof(t_color_elem));
	if (!color || !ft_atoi_strict(comp[0], &color->r)
		|| !ft_atoi_strict(comp[1], &color->g) || !ft_atoi_strict(comp[2],
			&color->b))
		return (free(color), 0);
	if (id == 5)
		info->floor_color = convert_rgb_to_int(color->r, color->g, color->b);
	else
		info->ceiling_color = convert_rgb_to_int(color->r, color->g, color->b);
	free(color);
	return (1);
}

int	check_color_validity(char **file, t_mapinfo *info)
{
	int		i;
	int		j;
	char	*comp[3];
	int		id;

	i = 0;
	while (file[i])
	{
		id = is_texture_or_color_line(file[i]);
		if (!is_empty_line(file[i]) && (id == 5 || id == 6))
		{
			j = 0;
			while (j < 3)
				comp[j++] = NULL;
			if (!parse_rgb_components(file[i], comp) || !set_game_color(info,
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
