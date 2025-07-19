/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/19 16:51:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "err.h"
# include "minimap.h"
# include "mlx_utils.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mapinfo
{
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;

	int			floor_color;
	int			ceiling_color;

	t_list		*map_lines;
	int			map_width;
	int			map_height;
}				t_mapinfo;

typedef struct s_cub3d
{
	t_mlx		*mlx;

	double		ppos_y;
	double		ppos_x;

	double		pdir_y;
	double		pdir_x;
	double		plane_y;
	double		plane_x;

	t_mapinfo	*info;
	int			**map;
}				t_cub3d;

/** Main functions */
void			parse_map_file(t_cub3d *ptr);
void			initialize_game(t_cub3d *cub3d);

void			ft_pixel_put(t_img *img, int x, int y, int color);
void			setup_hooks(t_cub3d *cub3d);
void			draw_player(t_cub3d *ptr);
int				render_frame(t_cub3d *ptr);

void			cleanup(t_cub3d *ptr);
void			error_exit(char *msg, t_cub3d *ptr);

#endif
