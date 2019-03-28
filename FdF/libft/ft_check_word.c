/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:41:35 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/30 12:41:57 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_word(char const *s, char c)
{
	int		i;
	int		word;

	i = 1;
	word = 0;
	if (s[0] != c && s[0])
		word++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}
