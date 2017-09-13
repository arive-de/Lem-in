/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:21:52 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 16:21:58 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_sized(uintmax_t n, int base)
{
	uintmax_t size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

char		*ft_conved(uintmax_t nb, int base, int size, int i)
{
	char	*tab;
	char	*str;

	str = ft_strnew(size);
	tab = ft_strdup("0123456789abcdef");
	size = size - 1;
	while (size >= i)
	{
		str[size] = tab[nb % base];
		nb = nb / base;
		size--;
	}
	return (str);
}

char		*ft_u_itoa_base(uintmax_t value, int base)
{
	int					i;
	char				*str;
	uintmax_t			size;

	i = 0;
	if (base <= 1 || base >= 17)
		return (NULL);
	size = ft_sized(value, base);
	str = ft_strnew(size);
	str = ft_conved(value, base, size, i);
	return (str);
}
