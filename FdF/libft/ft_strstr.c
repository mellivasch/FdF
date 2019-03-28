/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:33:52 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/02 15:01:53 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*hay;
	unsigned char	*nee;
	size_t			len;

	hay = (unsigned char *)haystack;
	nee = (unsigned char *)needle;
	len = ft_strlen((char *)nee);
	if (*nee == '\0')
		return ((char *)hay);
	if (*hay)
	{
		while (*hay)
		{
			if (ft_strncmp((const char *)hay, (const char *)nee, len) == 0)
				return ((char *)hay);
			hay++;
		}
	}
	return (0);
}
