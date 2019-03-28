/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:18:38 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/11 16:21:54 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		i1;
	int		i2;
	int		i3;

	i1 = 0;
	if (!s || !c)
		return (NULL);
	i3 = ft_check_word(s, c);
	out = (char **)malloc(sizeof(char *) * (i3 + 1));
	if (!out)
		return (NULL);
	while (i1 < i3)
	{
		while (*s && *s == c)
			s++;
		i2 = 0;
		out[i1] = (char *)malloc(sizeof(char) * (ft_len_word(s, c) + 1));
		while (*s && *s != c)
			out[i1][i2++] = *s++;
		out[i1++][i2] = '\0';
	}
	out[i1] = 0;
	return (out);
}
