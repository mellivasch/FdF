/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:28:36 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/28 15:44:11 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i1;
	size_t	len;

	i1 = 0;
	if (!s)
		return (0);
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	if (s[i1] == '\0')
		return (ft_strnew(0));
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len)
		len--;
	return (ft_strsub(s, i1, len - i1 + 1));
}
