/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:31:28 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/21 17:23:36 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	if (!s1 && !s2 && !n)
		return (0);
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	while (a1[i] == a2[i] && i < (n - 1) && a1)
		i++;
	if (i == n)
		return (0);
	else
		return (a1[i] - a2[i]);
}
