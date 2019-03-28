/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:14:47 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/19 19:05:39 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if ((list = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
		{
			list->content = malloc(content_size);
			list->content = ft_strncpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		else
		{
			list->content_size = 0;
			list->content = NULL;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
