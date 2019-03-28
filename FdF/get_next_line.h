/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:00:09 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/13 16:03:05 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 500
# define MAX_FD_NUM 4096

# include "./libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
