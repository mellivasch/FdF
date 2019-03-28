/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:32:11 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 17:00:49 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse(int fd, char *buff, t_fdf *map)
{
	char	**split_buff;
	int		y;

	y = 0;
	while (get_next_line(fd, &buff))
	{
		split_buff = ft_strsplit(buff, ' ');
		map = find_comma(split_buff, y, map);
		free(split_buff);
		free(buff);
		y++;
	}
	map->heig_map = y;
}

t_fdf	*find_comma(char **split_buff, int y, t_fdf *map)
{
	int		arr_index;

	arr_index = 0;
	while (split_buff[arr_index])
	{
		map = create_elem(split_buff[arr_index], map, arr_index, y);
		free(split_buff[arr_index]);
		arr_index++;
	}
	map->len_map = arr_index;
	return (map);
}

t_fdf	*create_elem(char *str, t_fdf *map, int n, int y)
{
	if (!map->points)
	{
		map->points = (t_point *)ft_memalloc(sizeof(t_point));
		map->points->z = ft_atoi(str);
		map->points->x = n;
		map->points->y = y;
		map->points->color = return_color(str, map);
		map->points->next = NULL;
		map->points->end = map->points;
	}
	else
	{
		map->points->end->next = (t_point*)ft_memalloc(sizeof(t_point));
		map->points->end = map->points->end->next;
		map->points->end->z = ft_atoi(str);
		map->points->end->x = n;
		map->points->end->y = y;
		map->points->end->color = return_color(str, map);
		map->points->end->next = NULL;
	}
	return (map);
}

void	put_arr(t_fdf *map)
{
	int		ind_num;
	t_point	*new_point;
	int		len;

	new_point = map->points;
	len = map->len_map * map->heig_map;
	map->arr_dir = (int**)malloc(sizeof(int*) * 3);
	ind_num = 0;
	if (!map)
		return ;
	map->arr_dir[0] = (int*)malloc(sizeof(int) * len);
	map->arr_dir[1] = (int*)malloc(sizeof(int) * len);
	map->arr_dir[2] = (int*)malloc(sizeof(int) * len);
	map->arr_dir[3] = (int*)malloc(sizeof(int) * len);
	while (new_point)
	{
		map->arr_dir[0][ind_num] = new_point->x;
		map->arr_dir[1][ind_num] = new_point->y;
		map->arr_dir[2][ind_num] = new_point->z / 3;
		map->arr_dir[3][ind_num] = new_point->color;
		new_point = new_point->next;
		ind_num++;
	}
}

int		return_color(char *str, t_fdf *map)
{
	int		ind;
	int		out;
	double	mult;
	char	*ret_ch;

	ind = 2;
	out = 0;
	ret_ch = ft_strchr(str, ',');
	if (str == NULL || ret_ch == NULL || ret_ch[0] != ',')
		return (map->color);
	mult = (double)(ft_strlen(ret_ch) - 4);
	while (ret_ch[++ind])
	{
		if ((ret_ch[ind] - '0') >= 0 && (ret_ch[ind] - '0') <= 9)
			out += (ret_ch[ind] - '0') * pow(16, mult);
		else if ((ret_ch[ind] >= 'A' && ret_ch[ind] <= 'F') ||
			(ret_ch[ind] >= 'a' && ret_ch[ind] <= 'f'))
			out += (num_color(ret_ch[ind]) * pow(16, mult));
		mult--;
	}
	if (out > 0)
		return (out);
	return (map->color);
}
