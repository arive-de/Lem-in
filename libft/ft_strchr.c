/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:50:02 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 16:06:14 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	d;

	i = 0;
	len = ft_strlen((char*)s + 1);
	d = (unsigned char)c;
	while (i <= len)
	{
		if (s[i] == d)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == '\0' && d == '\0')
		return ((char*)s + len + 1);
	return (NULL);
}
