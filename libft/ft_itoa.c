/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:25:47 by arive-de          #+#    #+#             */
/*   Updated: 2017/02/27 19:58:37 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_pow(int pow)
{
	int res;

	res = 1;
	while (pow > 0)
	{
		res = 10 * res;
		pow--;
	}
	return (res);
}

static int		ft_size(unsigned int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int				i;
	int				res;
	int				size;
	unsigned int	nb;
	char			*tab;

	res = 0;
	nb = (n < 0 ? -n : n);
	i = (n < 0 ? 1 : 0);
	size = ft_size(nb) - 1;
	tab = (char*)malloc(sizeof(char) * (size + (n < 0 ? 3 : 2)));
	if (!tab)
		return (NULL);
	while (size >= 0)
	{
		tab[i++] = (nb / (ft_pow(size)) + '0');
		res = nb / (ft_pow(size));
		res = res * (ft_pow(size));
		nb = nb - res;
		size--;
	}
	if (n < 0)
		tab[0] = '-';
	tab[i] = '\0';
	return (tab);
}
