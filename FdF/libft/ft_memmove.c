/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:36:44 by mivasche          #+#    #+#             */
/*   Updated: 2018/10/30 17:55:00 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int			i;
	const char	*sour;
	char		*out;

	i = -1;
	sour = src;
	out = dest;
	if (out > sour)
	{
		while (len--)
			out[len] = sour[len];
	}
	else
	{
		while (++i < (int)len)
			out[i] = sour[i];
	}
	return (dest);
}
