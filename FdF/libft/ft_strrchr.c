/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:27:46 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/20 19:15:29 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cha;

	i = 0;
	cha = c;
	while (i < ft_strlen((char *)s))
		i++;
	while (cha != s[i] && i != 0)
		i--;
	if (cha == (char)s[i])
		return ((char *)&s[i]);
	return (0);
}
