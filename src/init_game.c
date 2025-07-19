/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:29:04 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/19 16:58:20 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

/* This function simulates parsing the file valid_map.cub */
void	parse_map_file(t_cub3d *cub3d)
{
	cub3d->info = calloc(1, sizeof(t_mapinfo)); // TODO: free me
	if (!cub3d->info)
		error_exit("malloc, parse_map_file()", cub3d);
	/* TODO: for Dylan
	here we should do the procees of opening a file and finding a
	lines from the valid_map.cub, without using strdup to hardcode a path. */
	cub3d->info->north_texture_path = ft_strdup("../textures/wall_n.xpm");
	cub3d->info->south_texture_path = ft_strdup("../textures/wall_s.xpm");
	cub3d->info->west_texture_path = ft_strdup("../textures/wall_w.xpm");
	cub3d->info->east_texture_path = ft_strdup("../textures/wall_e.xpm");
	/* TODO: for Dylan
	same goes here, we should access the colors from the file */
	cub3d->info->floor_color = 0xAAAAAA;
	cub3d->info->ceiling_color = 0x555555;
	cub3d->info->map_lines = NULL;
	/* TODO: for Dylan
	here we should access these map data from the file as well, for the moment
	I am hard coding it an pusing them into the t_list *map_lines. You can
	parse these data from the map and push them to the same *map_lines structure
	so the rest of the program does not break*/
	ft_lstadd_back(&cub3d->info->map_lines, ft_lstnew(ft_strdup("111111")));
	ft_lstadd_back(&cub3d->info->map_lines, ft_lstnew(ft_strdup("100101")));
	ft_lstadd_back(&cub3d->info->map_lines, ft_lstnew(ft_strdup("101001")));
	ft_lstadd_back(&cub3d->info->map_lines, ft_lstnew(ft_strdup("1100N1")));
	ft_lstadd_back(&cub3d->info->map_lines, ft_lstnew(ft_strdup("111111")));
}

static void	process_player_direction(t_cub3d *cub3d, int x, int y, char *line)
{
	cub3d->map[y][x] = 0;
	cub3d->ppos_x = (x * TITLE_SIZE) + (TITLE_SIZE / 2.0);
	cub3d->ppos_y = (y * TITLE_SIZE) + (TITLE_SIZE / 2.0);
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
	return ;
}

static void	iterate_map_lines(t_cub3d *cub3d, char *line, int *x, int *y)
{
	t_list	*current;

	current = cub3d->info->map_lines;
	y = 0;
	while (current)
	{
		line = (char *)current->content;
		cub3d->map[*y] = calloc(cub3d->info->map_width, sizeof(int));
		if (!cub3d->map[*y])
			error_exit("malloc, initialize_game()", cub3d);
		*x = -1;
		while (++(*x) < cub3d->info->map_width)
		{
			if (ft_isdigit(line[*x]))
				cub3d->map[*y][*x] = line[*x] - '0';
			else if (line[*x] == 'N' || line[*x] == 'S' || line[*x] == 'W'
				|| line[*x] == 'E')
				process_player_direction(cub3d, *x, *y, line);
			else
				cub3d->map[*y][*x] = 0;
		}
		(*y)++;
	}
	return ;
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

	cub3d->info->map_width = ft_strlen(cub3d->info->map_lines->content);
	cub3d->info->map_height = ft_lstsize(cub3d->info->map_lines);
	cub3d->map = ft_calloc(cub3d->info->map_height, sizeof(int *));
	if (!cub3d->map)
		error_exit("malloc cub3d->map, initialize_game()", cub3d);
	iterate_map_lines(cub3d, line, &x, &y);
	init_mlx(cub3d);
}
