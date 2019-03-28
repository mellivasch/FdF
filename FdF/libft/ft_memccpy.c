/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:57:33 by mivasche          #+#    #+#             */
/*   Updated: 2018/10/30 18:29:39 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*out;
	unsigned char	*sour;

	i = 0;
	out = dest;
	sour = (unsigned char *)src;
	while (i < n)
	{
		out[i] = sour[i];
		if ((unsigned char)c == sour[i])
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
