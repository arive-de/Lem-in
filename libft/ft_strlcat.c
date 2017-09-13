/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:13:43 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/15 13:17:10 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t id;
	size_t is;

	id = 0;
	while (dst[id] && id < size)
		id++;
	if (id == size)
		return (size + ft_strlen((char*)src));
	is = 0;
	while ((id + is) < size - 1 && src[is])
	{
		dst[id + is] = src[is];
		is++;
	}
	dst[id + is] = '\0';
	return (id + ft_strlen((char*)src));
}
