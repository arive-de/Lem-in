/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:35:39 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 16:02:02 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char*)s);
	tmp = ft_strnew(len);
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = (*f)(s[i]);
		i++;
	}
	return (tmp);
}
