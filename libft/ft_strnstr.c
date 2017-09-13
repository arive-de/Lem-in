/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:58:44 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:10:21 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char*)big);
	while (big[i] && i + j < len)
	{
		while (little[j] == big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char*)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
