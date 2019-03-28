/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:53:35 by mivasche          #+#    #+#             */
/*   Updated: 2018/10/30 18:05:38 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*out;

	i = 0;
	out = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == out[i])
			return ((void *)&out[i]);
		i++;
	}
	return (0);
}
