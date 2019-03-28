/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:10:35 by mivasche          #+#    #+#             */
/*   Updated: 2018/12/03 18:25:13 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*out;
	int				a;
	int				i;
	unsigned int	num;

	i = 0;
	num = n;
	ft_check_neg(&i, &num, n);
	a = ft_len_int(num) + i;
	if ((out = (char *)malloc(sizeof(char) * (a + 1))))
	{
		out[a] = '\0';
		(num == 0) ? out[0] = 0 + '0' : 0;
		while (num != 0)
		{
			out[--a] = (num % 10) + '0';
			num = num / 10;
		}
		(i == 1) ? out[0] = '-' : 0;
		return (out);
	}
	return (0);
}
