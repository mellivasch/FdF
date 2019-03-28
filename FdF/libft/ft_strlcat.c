/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:54:50 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/20 17:47:09 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t ides;
	size_t isrc;

	ides = ft_strlen(dest);
	isrc = ft_strlen((char *)src);
	if (ides < destsize)
		ft_strncat(dest, src, destsize - ides - 1);
	else
		ides = destsize;
	return (ides + isrc);
}
