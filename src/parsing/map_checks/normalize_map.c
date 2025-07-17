/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:45:44 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/15 20:44:54 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_max_map_len(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static int	add_spac(char *dest, char *src, int max_len)
{
	int	k;

	k = 0;
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	while (k < max_len)
		dest[k++] = ' ';
	dest[k] = '\0';
	return (1);
}

char	**normalize_map(char **map)
{
	int		i;
	int		j;
	int		max_len;
	char	**map_normalized;

	i = 0;
	max_len = get_max_map_len(map);
	while (map[i])
		i++;
	map_normalized = malloc(sizeof(char *) * (i + 1));
	if (!map_normalized)
		return (NULL);
	j = 0;
	while (j < i)
	{
		map_normalized[j] = malloc(max_len + 1);
		if (!map_normalized[j] || !add_spac(map_normalized[j], map[j], max_len))
		{
			while (--j >= 0)
				free(map_normalized[j]);
			return (free(map_normalized), NULL);
		}
		j++;
	}
	return (map_normalized[i] = NULL, map_normalized);
}
