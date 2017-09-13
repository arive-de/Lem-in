/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:27:52 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:12:51 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tronc;

	i = 0;
	if (!s)
		return (NULL);
	tronc = ft_strnew(len);
	if (!tronc)
		return (NULL);
	while (i < len)
	{
		tronc[i] = ((char*)s)[start];
		i++;
		start++;
	}
	return (tronc);
}
