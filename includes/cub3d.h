/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/11 18:54:49 by mgodawat         ###   ########.fr       */
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

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

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

	t_player	*player;
	t_texture	*texture;
	t_color		*color;
}				t_game;

/** MLX and utils functions */
void			init_mlx(t_game *game);
void			setup_hooks(t_game *game);
int				cleanup(t_game *game);
void			err_exit(char *msg, t_game *game);

/** Mock parser function until Dylan gives the real thing */
t_game			*init_mock_data(void);

#endif
