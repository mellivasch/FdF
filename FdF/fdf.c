/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:32:05 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:59:45 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include <time.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*buff;
	t_fdf	*map;

	map = NULL;
	buff = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || read(fd, buff, 0) < 0 || line_fdf(argv[1]) != 1 ||
		get_next_line(fd, &buff) != 1)
	{
		write(1, "Error\n", 6);
		free(buff);
		return (0);
	}
	map = start(map);
	set_value(map->rot);
	parse(fd, buff, map);
	put_arr(map);
	draw(map);
	button(map);
	mlx_loop(map->mlx_ptr);
}
