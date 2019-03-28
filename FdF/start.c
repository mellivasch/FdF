/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:49:40 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 17:00:13 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*start(t_fdf *map)
{
	map = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	map->mlx_ptr = mlx_init();
	map->new_window = mlx_new_window(map->mlx_ptr, WIN_SIZE, WIN_SIZE, "FdF");
	map->rot = (t_rot *)ft_memalloc(sizeof(t_rot));
	map->pixel = (t_pixel *)ft_memalloc(sizeof(t_pixel));
	map->move_color = (t_color *)ft_memalloc(sizeof(t_color));
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIN_SIZE, WIN_SIZE);
	map->addr_ptr = (unsigned char *)mlx_get_data_addr(map->img_ptr,
		&(map->bits_per_pix), &(map->size_line), &(map->endian));
	map->color = 105105105;
	map->move_color->red = 0;
	map->move_color->green = 0;
	map->move_color->blue = 0;
	map->iso = 1;
	return (map);
}
