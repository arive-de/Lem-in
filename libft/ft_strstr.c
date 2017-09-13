/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:20:59 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/20 16:58:46 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen((char*)to_find);
	if (!to_find[i])
		return ((char*)str);
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j == len - 1)
				return ((char*)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
