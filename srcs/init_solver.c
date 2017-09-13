/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:16:44 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/05 11:24:31 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_list_li	*start_cursor(t_lem *env)
{
	t_list_li *tmp;

	tmp = env->lst;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->start == 1)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_list_li	*end_cursor(t_lem *env)
{
	t_list_li *tmp;

	tmp = env->lst;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->end == 1)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_list_li	*start_end(t_lem *env)
{
	t_list_li	*start;
	t_list_li	*end;
	t_list_tube	*lst_l;
	t_list_tube	*lst_e;

	start = start_cursor(env);
	end = end_cursor(env);
	if (!start || !end)
		return (NULL);
	lst_l = start->link;
	lst_e = end->link;
	if (!lst_l || !lst_e)
		return (NULL);
	return (start);
}

t_list_li	*init_solver(t_lem *env)
{
	t_list_li *tmp;

	env->cur = start_end(env);
	if (!env->cur)
		return (NULL);
	if (!env->cur->link)
		return (NULL);
	tmp = env->cur;
	return (env->cur);
}
