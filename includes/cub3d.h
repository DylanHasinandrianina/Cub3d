/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/15 20:02:43 by mgodawat         ###   ########.fr       */
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
void			draw_circle(t_circle *circle);
void			draw_rect(t_minimap *minimap);
void			find_player_position(t_game *game);
void			draw_player_direction_line(t_game *game);

/** Mock parser function until Dylan gives the real thing */
t_game			*init_mock_data(void);

/** Mem utils and cleaning up*/
int				cleanup(t_game *game);
void			err_exit(char *msg, t_game *game);

#endif
