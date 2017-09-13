/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:53:30 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:06:16 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*str;

	i = 0;
	d = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}
