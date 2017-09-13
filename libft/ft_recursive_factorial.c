/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:44:34 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 17:27:41 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	int res;
	int fact;

	res = 1;
	fact = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (fact > 1)
	{
		res = nb * (ft_recursive_factorial(nb - 1));
		fact--;
	}
	return (res);
}
