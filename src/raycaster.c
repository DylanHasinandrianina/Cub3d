/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:26:49 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/22 15:52:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
Step						Description
Locate map square			Find which map cell the ray starts in
Compute delta distances		Compute how far to next grid lines in both direcs
Set step direction			Decide if stepping in x/y is +1 or -1 [x]
Calculate side distances	Initial distances to the first x/y gridlines [x]

Determine Step Direction and Initial Side Distances:
* Figure out in which direction (positive or negative along x and y) the ray
will step through the grid based on its direction components.

* Calculate the distance from the ray’s current position to the first vertical
and horizontal grid boundaries (side_dist_x, side_dist_y) the ray will
encounter.

* Set step_x and step_y to +1 or -1 depending on the direction of ray_dir_x
and ray_dir_y. */
static void	calculate_step_and_side_distance(t_cub3d *cub3d)
{
	if (cub3d->raydir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_dist_x = (cub3d->ppos_x / cub3d->tile_size - cub3d->map_x)
			* cub3d->delta_dis_x;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_dist_x = (cub3d->map_x + 1.0 - cub3d->ppos_x
				/ cub3d->tile_size) * cub3d->delta_dis_x;
	}
	if (cub3d->raydir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_dist_y = (cub3d->ppos_y / cub3d->tile_size - cub3d->map_y)
			* cub3d->delta_dis_y;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_dist_y = (cub3d->map_y + 1.0 - cub3d->ppos_y
				/ cub3d->tile_size) * cub3d->delta_dis_y;
	}
}

/**
Step						Description
Locate map square			Find which map cell the ray starts in [x]
Compute delta distances		Compute how far to next grid lines in both direcs[x]
Set step direction			Decide if stepping in x/y is +1 or -1
Calculate side distances	Initial distances to the first x/y gridlines
*/
static void	calculate_delta_distance(t_cub3d *cub3d)
{
	cub3d->map_x = (int)(cub3d->ppos_x / cub3d->tile_size);
	cub3d->map_y = (int)(cub3d->ppos_y / cub3d->tile_size);
	if (cub3d->raydir_x == 0)
		cub3d->delta_dis_x = 1e30;
	else
		cub3d->delta_dis_x = fabs(1 / cub3d->raydir_x);
	if (cub3d->raydir_y == 0)
		cub3d->delta_dis_y = 1e30;
	else
		cub3d->delta_dis_y = fabs(1 / cub3d->raydir_y);
}

/** Once you have determined the ray direction for each column of the screen
in your raycasting algorithm, the next step is to prepare for and perform the
Digital Differential Analyzer (DDA) traversal. This step will allow you to find
which wall (or map cell) your ray hits.

Step						Description
Locate map square			Find which map cell the ray starts in
Compute delta distances		Compute how far to next grid lines in both direcs
Set step direction			Decide if stepping in x/y is +1 or -1
Calculate side distances	Initial distances to the first x/y gridlines
DDA loop					Marches the ray forward one gird square at a time
							until it collides with a wall

							DDA LOOP
1. Marches the ray forward one grid square at a time until it hits a
wall. It uses the side_dist and delta_dist variables to determine the
next square to check.
2. Check if the ray will hit a vertical or horizontal grid line next
	if so side is 0 indicating that the ray hit an east-west wall
	else side is 1 indicating that the ray hit a north-south wall
3. After stepping, check if the new grid square is a wall
*/
static void	dda(t_cub3d *cub3d)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (cub3d->side_dist_x < cub3d->side_dist_y)
		{
			cub3d->side_dist_x += cub3d->delta_dis_x;
			cub3d->map_x += cub3d->step_x;
			cub3d->side = 0;
		}
		else
		{
			cub3d->side_dist_y += cub3d->delta_dis_y;
			cub3d->map_y += cub3d->step_y;
			cub3d->side = 1;
		}
		if (cub3d->map[cub3d->map_y][cub3d->map_x] > 0)
			hit = 1;
	}
}

/** This function you calculate the ray direction for each vertical column of
the screen to determine which direction the ray will travel from the player's
position. The crucial variable to compute is the ray direction for each screen
column, often named rayDir or similar.

cameraX = 2 * x / double(w) - 1;
This transforms the screen coordinate x to camera space, mapping the range
[0, w-1] to [-1, 1].

Variable	Purpose										Formula
cameraX		pos on the screen in camera space (-1 to 1) 2×x/width−12×x/width−1

rayDir.X	X component of ray direction for column x	dirX+planeX×cameraXdirX+
														planeX×cameraX

rayDir.Y	Y component of ray direction for column x	dirY+planeY×cameraXdirY
														+planeY×cameraX
*/
static void	calculate_ray_directions(t_cub3d *cub3d, int x)
{
	cub3d->camera_x = 2 * x / (double)SIZE_W - 1;
	cub3d->raydir_x = cub3d->pdir_x + cub3d->plane_x * cub3d->camera_x;
	cub3d->raydir_y = cub3d->pdir_y + cub3d->plane_y * cub3d->camera_x;
	return ;
}
/**
Raycasting is a method that we use to fake a 3d world in a 2d map.

as a starter to see whats infront of your vector you can directly cast ONE RAY
until it hits a wall and then you calculate the distance

now instead of one ray your program should do this for EVERY SINGLE VERTICLE
COLUMN OF PIXELS. For each column it sends out one ray and get the distance
measurement

Then the program uses a simple rule to draw verticle line in each screen column
	* if a ray travels SHORT DISTANCE it draws a TALL LINE
	* if a ray travels LONG DISTANCE it draws a SHORT LINE

When your computer does this for all the SIZE_W columns of your screen, those
individual verticle lines blend together to create the final illusion of walls,
corridors and depth


DDA (Digital Difference Analysis) algorithm is responsible for FINDING WHICH
WALL A RAY HITS

-> calculate ray directions
-> perform DDA algorithm
*/
void	perform_raycaster(t_cub3d *ptr)
{
	int	x;

	x = -1;
	while (++x < SIZE_W)
	{
		calculate_ray_directions(ptr, x);
		calculate_delta_distance(ptr);
		calculate_step_and_side_distance(ptr);
		dda(ptr);
		calculate_wall_height(ptr);
		calculate_textures(ptr);
		draw_slice(ptr, x);
	}
	return ;
}
