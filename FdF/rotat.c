/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:13:37 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:40:32 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_fdf *map, t_newp *new_point)
{
	int	new_y;

	new_y = new_point->y;
	new_point->y = new_y * cos(map->rot->rx) + new_point->z * sin(map->rot->rx);
	new_point->z = -new_y * sin(map->rot->rx) + new_point->z *
		cos(map->rot->rx);
}

void	rot_y(t_fdf *map, t_newp *new_point)
{
	int	new_x;

	new_x = new_point->x;
	new_point->x = new_x * cos(map->rot->ry) + new_point->z * sin(map->rot->ry);
	new_point->z = -new_x * sin(map->rot->ry) + new_point->z *
		cos(map->rot->ry);
}

void	rot_z(t_fdf *map, t_newp *new_point)
{
	int	new_y;
	int	new_x;

	new_x = new_point->x;
	new_y = new_point->y;
	new_point->x = new_x * cos(map->rot->rz) - new_y * sin(map->rot->rz);
	new_point->y = new_x * sin(map->rot->rz) + new_y * cos(map->rot->rz);
}

void	pix_put(t_fdf *map, int x, int y, int color)
{
	int	i;

	if (x > 0 && x < WIN_SIZE && y > 0 && y < WIN_SIZE)
	{
		i = ((x * map->bits_per_pix / 8) + (y * map->size_line));
		*((unsigned int *)&map->addr_ptr[i]) = color;
	}
}

void	iso_project(int *x, int *y, int z)
{
	int	start_x;
	int	start_y;

	start_x = *x;
	start_y = *y;
	*x = (start_x - start_y) * cos(0.523599);
	*y = -z + (start_x + start_y) * sin(0.523599);
}
