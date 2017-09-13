/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:19:26 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 13:23:40 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char *new;

	if (!s1 || !s2)
	{
		if (s1)
			ft_strdel((char**)&s1);
		if (s2)
			ft_strdel((char**)&s2);
		return (NULL);
	}
	new = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (!new)
		return (NULL);
	ft_strcpy(new, (char*)s1);
	ft_strcat(new, s2);
	ft_strdel((char**)&s1);
	ft_strdel((char**)&s2);
	return (new);
}
