/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:18:59 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 13:19:19 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	while (((char*)s1)[i])
	{
		new[i] = ((char*)s1)[i];
		i++;
	}
	while (((char*)s2)[j])
	{
		new[i] = ((char*)s2)[j];
		i++;
		j++;
	}
	return (new);
}
