/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_elem_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:31:11 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/15 19:17:59 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	ft_atoi_strict(char *str, int *out)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		n = n * 10 + (str[i++] - '0');
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	if (n < 0 || n > 255)
		return (0);
	*out = (int)n;
	return (1);
}

int	skip_spaces(char *str, int i)
{
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
