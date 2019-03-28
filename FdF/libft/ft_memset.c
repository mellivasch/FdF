/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:32:14 by mivasche          #+#    #+#             */
/*   Updated: 2018/10/25 19:16:43 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t len)
{
	size_t	i;
	char	*out;

	i = -1;
	out = a;
	while (++i < len)
		*(out + i) = c;
	return (a);
}
