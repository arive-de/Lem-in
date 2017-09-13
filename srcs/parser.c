/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:20:58 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 14:28:08 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		is_fmi(t_lem *env, char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (str[i] == '\0')
	{
		if (!env->nb_fmi)
		{
			if (!pos_atoi(str, &env->nb_fmi))
				return (0);
			if (env->nb_fmi == 0)
				return (0);
			return (1);
		}
	}
	return (0);
}

int		salle(t_lem *env, char *str)
{
	int			flag;
	t_list_li	*tmp;

	tmp = env->lst;
	flag = 0;
	if ((ft_strchr(str, ' ') != NULL && ft_strchr(str, '#') == NULL) || !str)
	{
		env->tab = ft_strsplit(str, ' ');
		env->name = ft_strdup(env->tab[0]);
		if (env->name[0] != '#' && env->name[0] != 'L' &&
				ft_strchr(str, '-') == NULL && pos_atoi(env->tab[1], &env->x)
					&& pos_atoi(env->tab[2], &env->y) && !env->tab[3])
		{
			while (tmp)
			{
				if ((tmp->name && ft_strcmp(env->name, tmp->name) == 0) ||
						(tmp->x && tmp->x == env->x && tmp->y == env->y))
					flag++;
				tmp = tmp->next;
			}
			if (!flag)
				return (1);
		}
	}
	return (0);
}

int		start(t_lem *env)
{
	env->flag = 1;
	env->start++;
	if (env->start > 1)
		error();
	ft_putendl(env->line);
	ft_strdel(&env->line);
	if (get_next_line(0, &env->line) > 0)
	{
		if (!salle(env, env->line))
			error();
		env->sx = env->x;
		env->sy = env->y;
		del(env);
		free(env->tab);
		ft_putendl(env->line);
		env->name_s = ft_strsplit(env->line, ' ');
		env->start_n = ft_strdup(env->name_s[0]);
		ft_strdel(&env->name_s[0]);
		ft_strdel(&env->name_s[1]);
		ft_strdel(&env->name_s[2]);
		free(env->name_s);
		add_maillon_end(&env->lst, create_maillon_li(env));
		ft_strdel(&env->line);
	}
	return (1);
}

int		end(t_lem *env)
{
	env->end++;
	env->flag = 2;
	if (env->end > 1)
		error();
	ft_putendl(env->line);
	ft_strdel(&env->line);
	if (get_next_line(0, &env->line) > 0)
	{
		if (!salle(env, env->line))
			error();
		if (env->x == env->sx && env->y == env->sy)
			error();
		del(env);
		free(env->tab);
		ft_putendl(env->line);
		add_maillon_end(&env->lst, create_maillon_li(env));
		ft_strdel(&env->line);
	}
	return (1);
}

int		comment(t_lem *env, char *str)
{
	if (str[0] == '#' && ft_strchr(str, ' ') == 0)
	{
		if (ft_strcmp(str, "##start") == 0)
		{
			if (!start(env))
				return (0);
		}
		else if (ft_strcmp(str, "##end") == 0)
		{
			if (!end(env))
				return (0);
		}
		return (1);
	}
	return (0);
}
