/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:54:34 by mivasche          #+#    #+#             */
/*   Updated: 2018/11/20 17:15:34 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	tmp = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!tmp)
		{
			tmp = f(lst);
			new = tmp;
		}
		else
		{
			new->next = f(lst);
			new = new->next;
		}
		lst = lst->next;
	}
	new->next = NULL;
	return (tmp);
}
