/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:14:42 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 10:45:30 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_queue	*create_maillon_queue(t_queue *cur, t_list_li *addr)
{
	t_queue *maillon;

	maillon = (t_queue*)ft_memalloc(sizeof(t_queue));
	if (!maillon)
		return (NULL);
	maillon->prev = cur;
	maillon->room = addr;
	maillon->next = NULL;
	return (maillon);
}

void	add_maillon_end3(t_queue **begin_list, t_queue *data)
{
	t_queue *tmp;
	t_queue *tmp2;

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
