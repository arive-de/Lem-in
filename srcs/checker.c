/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:23:03 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 12:56:14 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		checker(t_lem *env)
{
	int			a;
	int			b;
	int			c;
	t_list_li	*tmp;

	a = 0;
	b = 0;
	c = 0;
	tmp = env->lst;
	if (!tmp || !env->flag_t)
		return (0);
	while (tmp)
	{
		if (tmp->start || tmp->end)
			a++;
		tmp = tmp->next;
	}
	if (a != 2)
		return (0);
	return (1);
}

void	del(t_lem *env)
{
	ft_strdel(&env->tab[0]);
	ft_strdel(&env->tab[1]);
	ft_strdel(&env->tab[2]);
}

void	error(void)
{
	ft_putendl("ERROR");
	exit(0);
}
