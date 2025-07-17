/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/17 13:05:18 by shasinan         ###   ########.fr       */
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

typedef struct s_color_elem
{
	int			r;
	int			g;
	int			b;
}				t_color_elem;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;

}				t_player;

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_texture;

typedef struct s_color
{
	int			floor;
	int			ceiling;
}				t_color;

typedef struct s_game
{
	t_mlx		*mlx;
	t_img		*img;

	char		**map;
	t_minimap	*minimap;

	t_player	*player;
	t_texture	*texture;
	t_color		*color;
}				t_game;

/***************parsing functions**************/
/*utils functions*/
int				is_empty_line(char *s);
int				is_texture_or_color_line(char *line);
int				is_map_elem(char *line);
int				convert_rgb_to_int(int r, int g, int b);
int				ft_atoi_strict(char *str, int *out);
int				skip_spaces(char *str, int i);
void			free_split(char **split);
void			free_partial_lines(char **content, int i);

/*map functions*/
char			**get_map(char **file);
char			**normalize_map(char **map);
void	set_player_position(t_game *game, char **map);

/*all checks*/
void	check_file(int ac, char **av);
int				check_element_validity(char **file);
int				check_missing_element(char **file);
int				check_map_position(char **file);
int				check_duplicate_elements(char **file);
int				check_texture_path(char **file, t_game *game);
int				check_color_validity(char **file, t_game *game);
int				check_map_validity(char **file, t_game *game);
int				check_error(char **file, t_game *game);

/*the parsing function*/
int				parsing(int ac, char **av, t_game *game);

/********************************************************************/

/** MLX and utils functions */
void			init_mlx(t_game *game);
void			setup_hooks(t_game *game);
int				rgb_to_int(double r, double g, double b);
void			put_pixel_to_img(t_img *img, int x, int y, int color);

/** Struct init functions */
void			init_minimap(t_game *game);
void			init_map(t_game *game);
void			init_player(t_game *game);
void			init_textures(t_game *game);
void			init_colors(t_game *game);

/** Rendering function */
int				render_frame(t_game *game);

/** Minimap function */
void			draw_minimap(t_game *game);

/** Mock parser function until Dylan gives the real thing */
t_game			*init_mock_data(void);

/** Mem utils and cleaning up*/
int				cleanup(t_game *game);
void			err_exit(char *msg, t_game *game);

#endif
