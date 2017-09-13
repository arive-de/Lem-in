/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:04:52 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:06:35 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]))
		i++;
	if (i == n)
		return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
