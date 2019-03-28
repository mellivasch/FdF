/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:52:56 by mivasche          #+#    #+#             */
/*   Updated: 2018/12/03 18:27:04 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*out;

	i = 0;
	if (!s || !f)
		return (0);
	len = (int)ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	while (s[i])
	{
		out[i] = f(s[i]);
		i++;
	}
	out[i++] = '\0';
	return (out);
}
