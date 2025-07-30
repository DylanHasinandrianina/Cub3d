/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:41:59 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/30 15:42:34 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

t_identifier	is_texture_or_color_line(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "NO", 2) && ft_isspace(line[i + 2]))
		return (ID_NORTH);
	else if (!ft_strncmp(&line[i], "SO", 2) && ft_isspace(line[i + 2]))
		return (ID_SOUTH);
	else if (!ft_strncmp(&line[i], "WE", 2) && ft_isspace(line[i + 2]))
		return (ID_WEST);
	else if (!ft_strncmp(&line[i], "EA", 2) && ft_isspace(line[i + 2]))
		return (ID_EAST);
	else if (line[i] == 'F' && ft_isspace(line[i + 1]))
		return (ID_FLOOR);
	else if ((line[i] == 'C') && ft_isspace(line[i + 1]))
		return (ID_CEILING);
	return (ID_ERROR);
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

char	**list_to_array(t_list *lst)
{
	char	**array;
	int		i;
	t_list	*tmp;

	array = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!array)
		return (NULL);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		array[i] = ft_strdup((char *)tmp->content);
		if (!array[i])
		{
			free_split(array);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
