/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:07:02 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:11:45 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plus_color(int plus, t_fdf *new_map, int color)
{
	int ind;

	ind = -1;
	while (new_map->arr_dir[3][++ind])
		new_map->arr_dir[3][ind] += plus;
	if (color == 1)
		new_map->move_color->red += 1;
	else if (color == 2)
		new_map->move_color->green += 1;
	else if (color == 3)
		new_map->move_color->blue += 1;
}

void	minus_color(int minus, t_fdf *new_map, int color)
{
	int ind;

	ind = -1;
	while (new_map->arr_dir[3][++ind])
		new_map->arr_dir[3][ind] -= minus * 6;
	if (color == 1)
		new_map->move_color->red = 0;
	else if (color == 2)
		new_map->move_color->green = 0;
	else if (color == 3)
		new_map->move_color->blue = 0;
}

int		num_color(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}
