/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:50:27 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/05 11:18:39 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_max_width(t_list *map_lines)
{
	int		max_width;
	int		current_width;
	t_list	*current;

	max_width = 0;
	current = map_lines;
	while (current)
	{
		current_width = ft_strlen((char *)current->content);
		if (current_width > max_width)
			max_width = current_width;
		current = current->next;
	}
	return (max_width);
}
