/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:30:50 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 13:46:42 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		count_c(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		tube(t_lem *env, char *str)
{
	int			flag;
	t_list_li	*tmp;

	flag = 0;
	tmp = env->lst;
	if (!tmp)
		return (0);
	if (ft_strchr(str, '-') != NULL && ft_strchr(str, ' ') == NULL &&
			count_c(str, '-') == 1)
	{
		env->tab2 = ft_strsplit(str, '-');
		while (tmp)
		{
			if ((tmp->name && ft_strcmp(env->tab2[0], tmp->name) == 0) ||
					(tmp->name && ft_strcmp(env->tab2[1], tmp->name) == 0))
				flag++;
			tmp = tmp->next;
		}
		if (ft_strcmp(env->tab2[0], env->tab2[1]) == 0)
			return (0);
		if (flag == 2 && !env->tab2[2])
			return (1);
	}
	return (0);
}
