/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:29:04 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/28 15:55:47 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx->mlx_ptr = mlx_init();
	cub3d->mlx->win_ptr = mlx_new_window(cub3d->mlx->mlx_ptr, SIZE_W, SIZE_H,
			"Cub3D");
	cub3d->mlx->img->img = mlx_new_image(cub3d->mlx->mlx_ptr, SIZE_W, SIZE_H);
	cub3d->mlx->img->addr = mlx_get_data_addr(cub3d->mlx->img->img,
			&cub3d->mlx->img->bits_per_pixel, &cub3d->mlx->img->line_length,
			&cub3d->mlx->img->endian);
}

void	parse_map_file(int ac, char **av, t_cub3d *cub3d)
{
	cub3d->info = ft_calloc(1, sizeof(t_mapinfo));
	if (!cub3d->info)
		error_exit("malloc, parse_map_file()", cub3d);
	if (!parsing(ac, av, cub3d->info))
		error_exit(NULL, cub3d);
}

static void	process_player_direction(t_cub3d *cub3d, int x, int y, char *line)
{
	cub3d->map[y][x] = 0;
	cub3d->ppos_x = (x * cub3d->tile_size) + (cub3d->tile_size / 2.0);
	cub3d->ppos_y = (y * cub3d->tile_size) + (cub3d->tile_size / 2.0);
	if (line[x] == 'N')
	{
		cub3d->pdir_y = -1;
		cub3d->plane_x = 0.66;
	}
	else if (line[x] == 'S')
	{
		cub3d->pdir_y = 1;
		cub3d->plane_x = -0.66;
	}
	else if (line[x] == 'W')
	{
		cub3d->pdir_x = -1;
		cub3d->plane_y = -0.66;
	}
	else if (line[x] == 'E')
	{
		cub3d->pdir_x = 1;
		cub3d->plane_y = 0.66;
	}
}

static void	iterate_map_lines(t_cub3d *cub3d, char *line, int *x, int *y)
{
	t_list	*current;
	size_t	len;

	current = cub3d->info->map_lines;
	*y = 0;
	while (current)
	{
		line = (char *)current->content;
		len = ft_strlen(line);
		cub3d->map[*y] = ft_calloc(cub3d->info->map_width, sizeof(int));
		if (!cub3d->map[*y])
			error_exit("malloc, initialize_game()", cub3d);
		*x = -1;
		while (++(*x) < cub3d->info->map_width)
		{
			if (*x < (int)len && ft_isdigit(line[*x]))
				cub3d->map[*y][*x] = line[*x] - '0';
			else if (*x < (int)len && is_player(line[*x]))
				process_player_direction(cub3d, *x, *y, line);
			else
				cub3d->map[*y][*x] = 0;
		}
		current = current->next;
		(*y)++;
	}
}

/* This function takes the raw data from the t_mapinfo structure that Dylan will
parse and process them to into creating the initial 2D **map.

right now our map is a linked list structure that looks like this

[111111] -> [100101] -> [101001] -> [1100N1] -> [111111]

1. We have to find the x and y of this map, to find x we can get the strlen of a
node, to find the y we can get the linked list size
2. Once I have the dimensions right I have to allocate mem for a 2D array
3. Then we iterate through the linked list map_lines */

void	initialize_game(t_cub3d *cub3d)
{
	char	*line;
	int		y;
	int		x;
	double	tile_w;
	double	tile_h;

	line = NULL;
	cub3d->info->map_width = get_max_width(cub3d->info->map_lines);
	cub3d->info->map_height = ft_lstsize(cub3d->info->map_lines);
	tile_w = (SIZE_W / MINIMAP_SCALE_FACTOR) / cub3d->info->map_width;
	tile_h = (SIZE_H / MINIMAP_SCALE_FACTOR) / cub3d->info->map_height;
	if (tile_w < tile_h)
		cub3d->tile_size = tile_w;
	else
		cub3d->tile_size = tile_h;
	cub3d->map = ft_calloc(cub3d->info->map_height, sizeof(int *));
	if (!cub3d->map)
		error_exit("malloc cub3d->map, initialize_game()", cub3d);
	iterate_map_lines(cub3d, line, &x, &y);
	init_mlx(cub3d);
	load_textures(cub3d);
}
