/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:51:38 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/11 18:27:53 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_list_tube	*create_maillon_tub(t_list_li *tmp)
{
	t_list_tube *maillon;

	maillon = (t_list_tube*)ft_memalloc(sizeof(t_list_tube));
	if (!maillon)
		return (NULL);
	maillon->addr = tmp;
	maillon->next = NULL;
	return (maillon);
}

void		add_maillon_end2(t_list_tube **begin_list, t_list_tube *data)
{
	t_list_tube *tmp;
	t_list_tube *tmp2;

	tmp = *begin_list;
	tmp2 = NULL;
	if (!(*begin_list))
		*begin_list = data;
	else
	{
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			tmp2->next = data;
		else
		{
			tmp2->next = data;
			data->next = tmp;
		}
	}
}
