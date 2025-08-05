/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:18:09 by shasinan          #+#    #+#             */
/*   Updated: 2025/08/05 11:36:16 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	flood_fill(char **map, int **visited, int y, int x)
{
	if (y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
	{
		ft_putstr_fd("Error\nunclosed map\n", 2);
		return (0);
	}
	if (visited[y][x] || map[y][x] == '1' || map[y][x] == ' ')
		return (1);
	visited[y][x] = 1;
	return (flood_fill(map, visited, y + 1, x) && flood_fill(map, visited, y
			- 1, x) && flood_fill(map, visited, y, x + 1) && flood_fill(map,
			visited, y, x - 1));
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	free_split_int(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
