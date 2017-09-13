/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:24:06 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 16:13:26 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		parser(t_lem *env, char *str)
{
	if (is_fmi(env, str))
		return (1);
	if (!env->nb_fmi)
		return (0);
	if (salle(env, str))
	{
		ft_strdel(&env->tab[0]);
		ft_strdel(&env->tab[1]);
		ft_strdel(&env->tab[2]);
		free(env->tab);
		return (2);
	}
	else if (comment(env, str))
		return (3);
	else if (tube(env, str))
		return (4);
	return (0);
}

void	get2(t_lem *env)
{
	if (checker(env))
		ft_putchar('\n');
	else
		error();
}

void	add_link(t_lem *env)
{
	t_list_li	*tub1;
	t_list_li	*tub2;

	tub1 = env->lst;
	if (!tub1)
		return ;
	while (tub1)
	{
		if (ft_strcmp(env->tab2[0], tub1->name) == 0)
			break ;
		tub1 = tub1->next;
	}
	tub2 = env->lst;
	if (!tub2)
		return ;
	while (tub2)
	{
		if (ft_strcmp(env->tab2[1], tub2->name) == 0)
			break ;
		tub2 = tub2->next;
	}
	add_maillon_end2(&tub1->link, create_maillon_tub(tub2));
	add_maillon_end2(&tub2->link, create_maillon_tub(tub1));
}

void	get(t_lem *env)
{
	int		i;

	i = 0;
	env->lst = NULL;
	while (get_next_line(0, &env->line) > 0)
	{
		i = parser(env, env->line);
		if (i == 0 && env->line[0] != '#')
			break ;
		if (i == 2)
			add_maillon_end(&env->lst, create_maillon_li(env));
		if (i == 4)
		{
			env->flag_t = 1;
			add_link(env);
			ft_strdel(&env->tab2[0]);
			ft_strdel(&env->tab2[1]);
			free(env->tab2);
		}
		ft_putendl(env->line);
		ft_strdel(&env->line);
	}
}

int		main(void)
{
	t_lem	*env;

	if (!(env = (t_lem*)ft_memalloc(sizeof(t_lem))))
		return (0);
	get(env);
	get2(env);
	if (!solver(env))
		error();
	return (0);
}
