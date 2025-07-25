/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:26:01 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/25 13:27:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

t_list	*alloc_and_fill_map(char **file, int start, int len)
{
	t_list	*list;
	t_list	*new_node;
	int		k;
	char	*current_line;

	list = NULL;
	new_node = NULL;
	k = 0;
	while (k < len)
	{
		current_line = ft_strdup(file[start + k]);
		if (!current_line)
			return (ft_lstclear(&list, free), NULL);
		trim_line(current_line);
		new_node = ft_lstnew(current_line);
		if (!new_node)
		{
			ft_lstclear(&list, free);
			return (free(current_line), NULL);
		}
		ft_lstadd_back(&list, new_node);
		k++;
	}
	return (list);
}

t_list	*get_map(char **file)
{
	int	start;
	int	len;

	start = skip_headers(file);
	len = count_map_lines(file, start);
	return (alloc_and_fill_map(file, start, len));
}
