/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:10:58 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/15 13:18:18 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
						size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*str;
	unsigned char	*dest;

	i = 0;
	d = (unsigned char)c;
	str = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while (i < n)
	{
		dest[i] = str[i];
		if (str[i] == d)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
