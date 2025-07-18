/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:20:12 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/18 18:50:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../minilibx-linux/mlx.h"

# define SIZE_W 1024
# define SIZE_H 512
# define TITLE_SIZE 30
# define FIELD_OF_VIEW 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_MOVE 6
# define CLOSE_BUTTON 17

# define W 119
# define A 97
# define S 115
# define D 100

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_NUM_PLUS 65451
# define KEY_MINUS 45
# define KEY_NUM_MINUS 65453
# define KEY_F1 65470
# define KEY_F2 65471
# define KEY_F3 65472

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define ORANGE 0x00FFA500
# define PURPLE 0x00800080
# define GRAY 0x00808080
# define BROWN 0x00A52A2A

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;

	t_img	*img;
}			t_mlx;

#endif
