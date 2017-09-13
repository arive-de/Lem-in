/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:00:29 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/11 19:17:41 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_list_li	*create_maillon_li(t_lem *env)
{
	t_list_li *maillon;

	maillon = (t_list_li*)ft_memalloc(sizeof(t_list_li));
	if (!maillon)
		return (NULL);
	if (env->flag == 1)
	{
		env->flag = 0;
		maillon->start = 1;
	}
	if (env->flag == 2)
	{
		env->flag = 0;
		maillon->end = 1;
	}
	maillon->name = ft_strdup(env->name);
	free(env->name);
	maillon->x = env->x;
	maillon->y = env->y;
	maillon->next = NULL;
	return (maillon);
}

void		add_maillon_end(t_list_li **begin_list, t_list_li *data)
{
	t_list_li *tmp;
	t_list_li *tmp2;

	tmp = *begin_list;
	tmp2 = NULL;
	if (!(*begin_list) && (*begin_list = data))
		return ;
	while (tmp && ft_strcmp(tmp->name, data->name) < 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		tmp2->next = data;
	else if (!tmp2)
	{
		data->next = *begin_list;
		*begin_list = data;
	}
	else
	{
		tmp2->next = data;
		data->next = tmp;
	}
}

void		freedom2(t_lem *env)
{
	t_queue		*tmp_que;
	t_output	*tmp_out;

	while (env->que)
	{
		tmp_que = env->que;
		env->que = env->que->next;
		free(tmp_que);
	}
	free(env->que);
	while (env->out)
	{
		tmp_out = env->out;
		env->out = env->out->next;
		free(tmp_out);
	}
	free(env->out);
}

void		freedom3(t_lem *env)
{
	free(env->line);
	free(env->tub);
	free(env->lst);
	free(env->start_n);
	free(env);
}

void		freedom(t_lem *env)
{
	t_list_tube *test;
	t_list_tube	*tmp_tub;
	t_list_li	*tmp_li;

	freedom2(env);
	tmp_li = env->lst;
	while (tmp_li)
	{
		test = tmp_li->link;
		while (test)
		{
			tmp_tub = test;
			test = test->next;
			free(tmp_tub);
		}
		tmp_li = tmp_li->next;
	}
	while (env->lst)
	{
		tmp_li = env->lst;
		env->lst = env->lst->next;
		ft_strdel(&tmp_li->name);
		free(tmp_li);
	}
	freedom3(env);
}
