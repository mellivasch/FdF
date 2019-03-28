/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:47:10 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:47:09 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_x(int len_y, int len_x, t_newp *p1, t_fdf *map)
{
	int		x;
	int		y;

	x = p1->x;
	y = p1->y;
	map->pixel->pd = -len_x;
	map->len_pixel++;
	while (map->len_pixel--)
	{
		pix_put(map, x, y, p1->color);
		x += map->pixel->dx;
		map->pixel->pd += 2 * len_y;
		if (map->pixel->pd > 0)
		{
			map->pixel->pd -= 2 * len_x;
			y += map->pixel->dy;
		}
	}
}

void	pixel_y(int len_y, int len_x, t_newp *p1, t_fdf *map)
{
	int		x;
	int		y;

	x = p1->x;
	y = p1->y;
	map->pixel->pd = -len_y;
	map->len_pixel++;
	while (map->len_pixel--)
	{
		pix_put(map, x, y, p1->color);
		y += map->pixel->dy;
		map->pixel->pd += 2 * len_x;
		if (map->pixel->pd > 0)
		{
			map->pixel->pd -= 2 * len_y;
			x += map->pixel->dx;
		}
	}
}

void	set_pixel(t_newp *p1, t_newp *p2, t_fdf *map)
{
	int		len_x;
	int		len_y;

	len_x = abs(p2->x - p1->x);
	len_y = abs(p2->y - p1->y);
	map->len_pixel = len_x > len_y ? len_x : len_y;
	map->pixel->dx = (p2->x - p1->x >= 0 ? 1 : -1);
	map->pixel->dy = (p2->y - p1->y >= 0 ? 1 : -1);
	if (map->len_pixel == 0)
		pix_put(map, p1->x, p1->y, p1->color);
	if (len_y <= len_x)
		pixel_x(len_y, len_x, p1, map);
	else
		pixel_y(len_y, len_x, p1, map);
	free(p1);
	free(p2);
}

t_newp	*new_point(int ind, t_fdf *map)
{
	t_newp	*out;

	out = (t_newp *)ft_memalloc(sizeof(t_newp));
	out->x = map->arr_dir[0][ind];
	out->y = map->arr_dir[1][ind];
	out->z = map->arr_dir[2][ind];
	out->color = map->arr_dir[3][ind];
	out->x -= map->len_map / 2;
	out->y -= map->heig_map / 2;
	out->x = (out->x + map->rot->dx) * map->rot->zoom;
	out->y = (out->y + map->rot->dy) * map->rot->zoom;
	if (map->arr_dir[2][ind] > 0)
		out->z = (out->z + map->rot->dz) * map->rot->zoom;
	rot_x(map, out);
	rot_y(map, out);
	rot_z(map, out);
	if (map->iso == 1)
		iso_project(&out->x, &out->y, out->z);
	out->x += WIN_SIZE / 2;
	out->y += WIN_SIZE / 2;
	return (out);
}

void	draw(t_fdf *map)
{
	int		ind;

	ind = 0;
	while (ind < ((map->len_map * map->heig_map)))
	{
		if (map->arr_dir[0][ind] % (map->len_map - 1) != 0 ||
			map->arr_dir[0][ind] == 0)
			set_pixel(new_point(ind, map), new_point(ind + 1, map), map);
		if (map->arr_dir[1][ind] < map->heig_map - 1)
			set_pixel(new_point(ind, map), new_point(ind + map->len_map, map),
			map);
		ind++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->new_window, map->img_ptr, 0, 0);
}
