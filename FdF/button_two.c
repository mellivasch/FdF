/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:32:36 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:50:22 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		isometric(int key, t_fdf *new_map)
{
	if (key == 34 && new_map->iso == 0)
		new_map->iso = 1;
	else if (key == 34 && new_map->iso == 1)
		new_map->iso = 0;
	ft_bzero(new_map->addr_ptr, (new_map->bits_per_pix / 8) *
		(WIN_SIZE * WIN_SIZE));
	draw(new_map);
	return (1);
}
