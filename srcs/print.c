/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:48:29 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 11:06:36 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	aff(t_lem *env, int ant, t_output *tmp, int a)
{
	if (a == 1)
	{
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putchar('-');
		ft_putstr(tmp->name);
		env->aff--;
	}
	else if (a == 2)
	{
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putchar('-');
		ft_putstr(tmp->orig->name);
		env->aff--;
	}
}

void	print_mid(t_lem *env, int ant, t_output *tmp)
{
	aff(env, ant, tmp, 2);
	if (ant == env->nb_line || ant == env->nb_fmi)
		ft_putchar('\n');
	else
		ft_putchar(' ');
	if (ant < env->nb_fmi && ant < env->nb_line)
	{
		tmp = tmp->orig;
		print_mid(env, ant + 1, tmp);
	}
}

void	print_end(t_lem *env, int ant, t_output *tmp)
{
	if (tmp->orig)
		aff(env, ant, tmp, 2);
	if ((ant == env->nb_fmi || ft_strcmp(tmp->name, env->out->name) == 0)
			&& env->nb_room != 1)
		ft_putchar('\n');
	else if (env->nb_room != 1)
		ft_putchar(' ');
	if (ant < env->nb_fmi && tmp->orig)
	{
		tmp = tmp->orig;
		print_end(env, ant + 1, tmp);
	}
}

void	printer_end(t_lem *env, int ant)
{
	env->nb_line = 0;
	while (env->aff > 0)
	{
		ant++;
		aff(env, ant, last(env->out), 1);
		if (env->aff == 1 || env->aff == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		if (env->aff > 0)
			print_end(env, ant + 1, last(env->out));
	}
}

void	printer(t_lem *env, t_output *tmp)
{
	int ant;

	ant = 1;
	add_orig(env);
	while (tmp)
	{
		if (env->nb_line == 1 || env->nb_fmi == 1)
		{
			aff(env, ant, tmp, 1);
			ft_putchar('\n');
		}
		else
		{
			aff(env, ant, tmp, 1);
			ft_putchar(' ');
		}
		if (env->nb_line != 1 && env->nb_fmi != 1)
			print_mid(env, ant + 1, tmp);
		env->nb_line++;
		tmp = tmp->next;
	}
	printer_end(env, ant);
}
