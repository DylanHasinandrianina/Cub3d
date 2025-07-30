/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:43:33 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/30 15:44:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	parse_and_set_color(char *line, t_identifier id, t_mapinfo *info)
{
	int		i;
	char	**rgb_split;
	t_rgb	color;

	i = 0;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	rgb_split = ft_split(&line[i], ',');
	if (!rgb_split || !rgb_split[0] || !rgb_split[1] || !rgb_split[2]
		|| rgb_split[3])
		return (free_split(rgb_split), 0);
	if (!ft_atoi_strict(rgb_split[0], &color.r) || !ft_atoi_strict(rgb_split[1],
			&color.g) || !ft_atoi_strict(rgb_split[2], &color.b))
		return (free_split(rgb_split), 0);
	free_split(rgb_split);
	if (id == ID_FLOOR)
		info->floor_color = convert_rgb_to_int(color.r, color.g, color.b);
	else
		info->ceiling_color = convert_rgb_to_int(color.r, color.g, color.b);
	return (1);
}

int	check_color_validity(char **file, t_mapinfo *info)
{
	int				i;
	t_identifier	id;
	int				j;

	i = 0;
	while (file[i])
	{
		id = is_texture_or_color_line(file[i]);
		if (id == ID_FLOOR || id == ID_CEILING)
		{
			j = 0;
			while (ft_isspace(file[i][j]))
				j++;
			if (!parse_and_set_color(&file[i][j], id, info))
			{
				ft_putstr_fd("Error\ninvalid color format\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
