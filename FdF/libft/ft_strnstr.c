/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:24:49 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/21 17:41:43 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i1;
	size_t		i2;

	i1 = 0;
	i2 = 0;
	while (str1[i1] && (i1 < len))
	{
		while ((str1[i1 + i2] == str2[i2]) && str2[i2] && ((i1 + i2) < len))
			i2++;
		if (!str2[i2])
			return ((char *)&str1[i1]);
		i2 = 0;
		i1++;
	}
	if (!str2[0])
		return ((char *)&str1[i1]);
	return (0);
}
