/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:50:10 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:44:55 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	button(t_fdf *map)
{
	mlx_hook(map->new_window, 17, 0, exit_func, (void *)map);
	mlx_hook(map->new_window, 2, 0, key_button, (void *)map);
	mlx_hook(map->new_window, 3, 0, isometric, (void *)map);
}

void	set_value(t_rot *rot)
{
	rot->dx = 0;
	rot->dy = 0;
	rot->dz = 0;
	rot->zoom = 2;
	rot->rx = 0;
	rot->ry = 0;
	rot->rz = 0;
}

void	move(int key, t_fdf *map)
{
	if (key == 0)
		map->rot->dx -= 1;
	else if (key == 2)
		map->rot->dx += 1;
	else if (key == 1)
		map->rot->dy += 1;
	else if (key == 13)
		map->rot->dy -= 1;
}

int		key_button(int key, void *map)
{
	t_fdf	*new_map;

	new_map = (t_fdf *)map;
	if ((key >= 0 && key <= 2) || key == 13)
		move(key, new_map);
	else if (key == 78 || key == 69)
		zoom(key, new_map);
	else if (key >= 125 && key <= 126)
		over_x(key, new_map);
	else if (key >= 123 && key <= 124)
		over_y(key, new_map);
	else if (key == 116 || key == 121)
		move_z(key, new_map);
	else if (key == 53)
	{
		del_win(new_map);
		exit(0);
	}
	else if (key == 15 || key == 5 || key == 11)
		new_color(key, new_map);
	ft_bzero(new_map->addr_ptr, (new_map->bits_per_pix / 8) *
		(WIN_SIZE * WIN_SIZE));
	draw(new_map);
	return (1);
}

int		exit_func(void *map)
{
	(void)map;
	exit(0);
	return (0);
}
