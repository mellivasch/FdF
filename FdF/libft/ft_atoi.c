/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:14:11 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/20 17:55:15 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	i;
	int				n;
	long long int	out;

	i = 0;
	n = 1;
	out = 0;
	while (str[i] == '\r' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && out >= 0)
		out = out * 10 + str[i++] - '0';
	if (out < 0)
	{
		if (n == -1)
			return (0);
		return (-1);
	}
	return ((int)out * n);
}
