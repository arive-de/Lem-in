/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:24:53 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/11 18:27:41 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_output	*create_maillon_output(char *str)
{
	t_output *maillon;

	maillon = (t_output*)ft_memalloc(sizeof(t_output));
	if (!maillon)
		return (NULL);
	maillon->name = str;
	maillon->next = NULL;
	return (maillon);
}

void		add_maillon_beg(t_output **begin_list, t_output *data)
{
	t_output *tmp;

	tmp = *begin_list;
	if (!(*begin_list))
		*begin_list = data;
	else
	{
		tmp = data;
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
}

t_output	*last(t_output *tmp)
{
	t_output *tmp2;

	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}

int			lst_count(t_lem *env)
{
	int			i;
	t_output	*tmp;

	i = 0;
	tmp = env->out;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
