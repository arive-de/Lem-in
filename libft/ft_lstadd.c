/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:33:58 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 15:13:30 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		*alst = new;
		new->next = tmp;
	}
}
