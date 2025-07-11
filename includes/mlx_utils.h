/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:20:12 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/11 00:58:47 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../minilibx-linux/mlx.h"

# define STEP 10.0
# define ZOOM_FACTOR 1.2
# define SIZE_W 960
# define SIZE_H 540

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

#endif