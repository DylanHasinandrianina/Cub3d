/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:49:39 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/19 14:07:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	malloc_structures(t_cub3d **cub3d)
{
	*cub3d = calloc(1, sizeof(t_cub3d));
	if (!*cub3d)
		error_exit("init_structures(), cub3d malloc", *cub3d);
	(*cub3d)->mlx = calloc(1, sizeof(t_mlx));
	if (!(*cub3d)->mlx)
		error_exit("init_structures(), cub3d->mlx malloc", *cub3d);
	(*cub3d)->mlx->img = calloc(1, sizeof(t_img));
	if (!(*cub3d)->mlx->img)
		error_exit("init_structures(), cub3d->mlx->img malloc", *cub3d);
}

int	main(void)
{
	t_cub3d	*cub3d;

	/** 1. Allocate mem for the main structure */
	cub3d = NULL;
	malloc_structures(&cub3d);
	/** 2. Parse the map file */
	parse_map_file(cub3d);
	/** 3. Init the game stage from the parsed data */
	initialize_game(cub3d);
	/** 4. Run the game */
	setup_hooks(cub3d);
	mlx_loop_hook(cub3d->mlx->mlx_ptr, render_frame, cub3d);
	mlx_loop(cub3d->mlx->mlx_ptr);
	/** 5. Clean memory */
	cleanup(cub3d);
	return (0);
}
