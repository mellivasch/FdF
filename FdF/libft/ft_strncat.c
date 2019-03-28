/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:40:39 by mivasche          #+#    #+#             */
/*   Updated: 2018/10/30 19:29:25 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		i2;
	size_t	check;

	i = 0;
	i2 = 0;
	check = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[i2] != '\0' && check < n)
	{
		s1[i] = s2[i2];
		i2++;
		i++;
		check++;
	}
	s1[i] = '\0';
	return (s1);
}
