/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_sec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:50 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:07:24 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *map)
{
	if (key == 69)
		map->rot->zoom += 0.25;
	else if (key == 78 && map->rot->zoom > 1)
		map->rot->zoom -= 0.25;
}

void	over_x(int key, t_fdf *new_map)
{
	if (key == 126)
		new_map->rot->rx -= 0.25;
	else if (key == 125)
		new_map->rot->rx += 0.25;
}

void	over_y(int key, t_fdf *new_map)
{
	if (key == 123)
		new_map->rot->ry -= 0.25;
	else if (key == 124)
		new_map->rot->ry += 0.25;
}

void	move_z(int key, t_fdf *new_map)
{
	if (key == 116)
		new_map->rot->dz += 1;
	else if (key == 121)
		new_map->rot->dz -= 1;
}

void	new_color(int key, t_fdf *new_map)
{
	int	ind;

	ind = -1;
	if (key == 15)
	{
		if (new_map->move_color->red != 7)
			plus_color(50000000, new_map, 1);
		else
			minus_color(50000000, new_map, 1);
	}
	else if (key == 5)
	{
		if (new_map->move_color->green != 7)
			plus_color(50000, new_map, 2);
		else
			minus_color(50000, new_map, 2);
	}
	else if (key == 11)
	{
		if (new_map->move_color->blue != 7)
			plus_color(50, new_map, 3);
		else
			minus_color(50, new_map, 3);
	}
}
