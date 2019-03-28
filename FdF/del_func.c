/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:02:57 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:04:41 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_win(t_fdf *new_map)
{
	ft_bzero(new_map->addr_ptr, (new_map->bits_per_pix / 8) *
		(WIN_SIZE * WIN_SIZE));
	mlx_destroy_window(new_map->mlx_ptr, new_map->new_window);
}
