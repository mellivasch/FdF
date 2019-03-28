/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:32:24 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:44:40 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "./minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WIN_SIZE 1000

typedef struct		s_pixel
{
	int				pd;
	int				dx;
	int				dy;
}					t_pixel;

typedef struct		s_rot
{
	int				dx;
	int				dy;
	int				dz;
	float			zoom;
	double			ry;
	double			rz;
	double			rx;
}					t_rot;

typedef struct		s_newp
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_newp;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
	struct s_point	*end;
}					t_point;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_fdf
{
	int				len_map;
	int				iso;
	int				color;
	int				heig_map;
	int				len_pixel;
	void			*img_ptr;
	unsigned char	*addr_ptr;
	int				bits_per_pix;
	int				size_line;
	int				endian;
	int				**arr_dir;
	void			*mlx_ptr;
	void			*new_window;
	struct s_point	*points;
	struct s_rot	*rot;
	struct s_pixel	*pixel;
	struct s_color	*move_color;
}					t_fdf;

void				set_pixel(t_newp *p1, t_newp *p2, t_fdf *map);
void				draw(t_fdf *map);
void				button(t_fdf *map);
int					exit_func(void *map);
int					key_button(int key, void *map);
void				set_value(t_rot *rot);
void				zoom(int key, t_fdf *map);
void				rot_x(t_fdf *map, t_newp *new_point);
void				rot_y(t_fdf *map, t_newp *new_point);
void				rot_z(t_fdf *map, t_newp *new_point);
void				over_x(int key, t_fdf *new_map);
void				over_y(int key, t_fdf *new_map);
void				move_z(int key, t_fdf *new_map);
int					return_color(char *str, t_fdf *map);
void				ft_del_str_all(char **str, char *buff);
void				pix_put(t_fdf *map, int x, int y, int color);
int					line_fdf(char *str);
void				new_color(int key, t_fdf *new_map);
void				plus_color(int plus, t_fdf *new_map, int color);
void				minus_color(int minus, t_fdf *new_map, int color);
void				put_arr(t_fdf *map);
void				parse(int fd, char *buff, t_fdf *map);
t_fdf				*find_comma(char **split_buff, int y, t_fdf *map);
t_fdf				*create_elem(char *str, t_fdf *map, int n, int y);
int					num_color(char c);
t_fdf				*start(t_fdf *map);
void				del_win(t_fdf *new_map);
void				iso_project(int *x, int *y, int z);
int					isometric(int key, t_fdf *new_map);

#endif
