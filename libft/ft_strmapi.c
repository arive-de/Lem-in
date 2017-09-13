/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:54:36 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:09:26 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char*)s);
	tmp = (char*)malloc(sizeof(char*) * len);
	if (!tmp)
		return (NULL);
	tmp = ft_strnew(len);
	while (s[i])
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	return (tmp);
}
