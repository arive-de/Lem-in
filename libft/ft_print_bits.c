/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:08:03 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/18 10:51:58 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int		i;
	char	c;

	i = 128;
	while (i > 0)
	{
		if (octet < i)
		{
			c = '0';
			i = i / 2;
			ft_putchar(c);
		}
		else
		{
			c = '1';
			ft_putchar(c);
			octet = octet - i;
			i = i / 2;
		}
	}
}
