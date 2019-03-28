/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:34:16 by mivasche          #+#    #+#             */
/*   Updated: 2018/12/04 15:47:27 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i1;
	int		i2;

	i1 = -1;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	if ((out = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
	{
		while (s1[++i1])
			out[i1] = s1[i1];
		while (s2[i2])
		{
			out[i1] = s2[i2];
			i1++;
			i2++;
		}
		out[i1] = '\0';
		return (out);
	}
	return (0);
}
