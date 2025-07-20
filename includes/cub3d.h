/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/20 19:23:45 by mgodawat         ###   ########.fr       */
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

# define PI 3.14159

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
	int			tile_size;

	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_dis_x;
	double		delta_dis_y;
	int			map_x;
	int			map_y;

}				t_cub3d;

/** Main functions */
void			parse_map_file(t_cub3d *ptr);
void			initialize_game(t_cub3d *cub3d);

/* Drawing functions */
void			draw_player(t_cub3d *ptr);
void			draw_map(t_cub3d *ptr);
int				is_wall(t_cub3d *cub3d, int x, int y);
void			draw_world(t_cub3d *ptr);

void			ft_pixel_put(t_img *img, int x, int y, int color);
void			setup_hooks(t_cub3d *cub3d);
int				render_frame(t_cub3d *ptr);

/* Key hooks functions and key controls */
int				key_hook(int keycode, t_cub3d *cub3d);
void			handle_wasd(int keycode, t_cub3d *cub3d);
void			handle_arrow_keys(int keycode, t_cub3d *cub3d);

void			cleanup(t_cub3d *ptr);
void			error_exit(char *msg, t_cub3d *ptr);

#endif