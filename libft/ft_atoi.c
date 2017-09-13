/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:48:45 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:01:04 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int stock;

	i = 0;
	neg = 0;
	stock = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	if (str[i] == '+' && neg != 1)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		stock = stock * 10;
		stock = stock + ((int)str[i] - 48);
		i++;
	}
	return (neg == 1 ? -stock : stock);
}
