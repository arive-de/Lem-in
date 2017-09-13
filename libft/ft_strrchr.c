/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:10:16 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:10:30 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	d;

	len = ft_strlen((char*)s) + 1;
	d = (unsigned char)c;
	if (d == '\0')
		return ((char*)s + len - 1);
	while (len > 0)
	{
		len--;
		if (s[len] == d)
			return ((char*)s + len);
	}
	return (NULL);
}
