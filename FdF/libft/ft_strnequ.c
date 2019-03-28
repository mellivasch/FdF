/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:35:43 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/26 16:28:51 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}
