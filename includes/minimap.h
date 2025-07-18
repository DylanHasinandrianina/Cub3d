/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:12:08 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/14 18:44:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "mlx_utils.h"

# define MINIMAP_SCALE 50

typedef struct s_line
{
	t_img	*img;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		color;
}			t_line;

typedef struct s_circle
{
	t_img	*img;
	int		center_x;
	int		center_y;
	int		radius;
	int		color;
}			t_circle;

typedef struct s_minimap
{
	t_img	*img;
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_minimap;

#endif
