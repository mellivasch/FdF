/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:26:19 by mivasche          #+#    #+#             */
/*   Updated: 2018/12/03 18:26:12 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		out[i] = f(i, s[i]);
		i++;
	}
	out[i++] = '\0';
	return (out);
}
