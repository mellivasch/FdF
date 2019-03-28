/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:37:12 by mivasche          #+#    #+#             */
/*   Updated: 2018/12/17 14:48:53 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[i + start])
	{
		out[i] = s[i + start];
		i++;
	}
	out[len] = '\0';
	return (out);
}
