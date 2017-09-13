/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:48:29 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 16:14:08 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	add_orig(t_lem *env)
{
	t_output *tmp;
	t_output *tmp2;

	tmp = env->out;
	tmp2 = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		tmp->orig = tmp2;
		tmp2 = tmp;
		tmp = tmp->next;
	}
}

void	ending(t_lem *env, t_queue *q, t_list_li *end)
{
	t_queue *tmp;
	t_queue *tmp2;

	add_maillon_end3(&env->que, create_maillon_queue(q, end));
	tmp2 = env->que;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	while (ft_strcmp(tmp->room->name, env->start_n) != 0)
	{
		add_maillon_beg(&env->out, create_maillon_output(tmp->room->name));
		tmp = tmp->prev;
	}
}

int		check_links(t_lem *env, t_queue *q)
{
	t_list_tube *tmp;

	tmp = q->room->link;
	while (tmp && q)
	{
		if (tmp->addr->end)
		{
			ending(env, q, tmp->addr);
			env->nb_line = 1;
			env->nb_room = lst_count(env);
			env->aff = env->nb_fmi * env->nb_room;
			printer(env, env->out);
			freedom(env);
			return (1);
		}
		else if (!tmp->addr->seen)
		{
			add_maillon_end3(&env->que,
					create_maillon_queue(q, tmp->addr));
			tmp->addr->seen = 1;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		change_cursor(t_lem *env, t_queue *cur)
{
	while (cur)
	{
		if (check_links(env, cur))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int		solver(t_lem *env)
{
	t_list_li		*cur;
	t_list_tube		*cur_l;
	t_queue			*q;
	int				i;

	i = 0;
	cur = init_solver(env);
	if (!cur)
		return (0);
	cur_l = cur->link;
	cur->seen = 1;
	add_maillon_end3(&env->que, create_maillon_queue(NULL, cur));
	if (!(q = env->que))
		return (0);
	if (!change_cursor(env, q))
		return (0);
	return (1);
}
