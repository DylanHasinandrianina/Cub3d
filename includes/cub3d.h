/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/28 15:51:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "err.h"
# include "mlx_utils.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define PI 3.14159
# define NUM_TEXTURES 4
# define TEXTURE_WIDTH 128
# define TEXTURE_HEIGHT 64
# define MINIMAP_SCALE_FACTOR 5.0

typedef struct s_color_elem
{
	int			r;
	int			g;
	int			b;
}				t_color_elem;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;

}				t_texture;

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

	int			step_x;
	int			step_y;

	double		side_dist_x;
	double		side_dist_y;
	int			side;

	double		wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;

	t_texture	textures[4];
	double		wall_x;
	int			tex_x;

	int			keys[65536];

}				t_cub3d;

/***************parsing functions**************/
/*utils functions*/
int				is_empty_line(char *s);
int				is_texture_or_color_line(char *line);
int				is_map_elem(char *line);
int				is_player(char c);
int				convert_rgb_to_int(int r, int g, int b);
int				ft_atoi_strict(char *str, int *out);
int				skip_spaces(char *str, int i);
void			free_split(char **split);
void			free_partial_lines(char **content, int i);
char			**list_to_array(t_list *lst);

/*map functions*/
t_list			*get_map(char **file);
char			**normalize_map(char **map);
int				get_max_width(t_list *map_lines);

/*all checks*/
int				check_file(int ac, char **av);
int				check_element_validity(char **file);
int				check_missing_element(char **file);
int				check_map_position(char **file);
int				check_duplicate_elements(char **file);
int				check_texture_path(char **file, t_mapinfo *info);
int				check_color_validity(char **file, t_mapinfo *info);
int				check_map_validity(char **file, t_mapinfo *info);
int				check_error(char **file, t_mapinfo *info);

/*the parsing function*/
int				parsing(int ac, char **av, t_mapinfo *info);

/********************************************************************/

/** Main functions */
void			parse_map_file(int ac, char **av, t_cub3d *cub3d);
void			initialize_game(t_cub3d *cub3d);

/* Drawing functions */
void			draw_minimap_background(t_cub3d *ptr);
void			draw_player(t_cub3d *ptr);
void			draw_map(t_cub3d *ptr);
int				is_wall(t_cub3d *cub3d, int x, int y);

/* Raycaster and related functions */
void			perform_raycaster(t_cub3d *ptr);
void			calculate_wall_height(t_cub3d *cub3d);

/* Texture functions */
void			load_textures(t_cub3d *cub3d);
void			calculate_texture_x(t_cub3d *cub3d);
void			draw_slice(t_cub3d *cub3d, int x);

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