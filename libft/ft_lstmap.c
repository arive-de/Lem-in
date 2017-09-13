/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:04:33 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 15:50:46 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	first = (*f)(ft_lstnew(lst->content, lst->content_size));
	new = first;
	while ((lst = lst->next))
	{
		new->next = (*f)(ft_lstnew(lst->content, lst->content_size));
		new = new->next;
	}
	return (first);
}
