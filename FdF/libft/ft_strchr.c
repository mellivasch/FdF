/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:21:52 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/20 19:14:30 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cha;

	i = 0;
	cha = c;
	while (i < ft_strlen((char *)s) && cha != s[i])
		i++;
	if (cha == (char)s[i])
		return ((char *)&s[i]);
	return (0);
}
