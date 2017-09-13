/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:14:44 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 10:18:40 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*s3;
	char	*s4;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s3 = (char*)s1;
	s4 = (char*)s2;
	while (s3[i] && s4[i] && i < n)
	{
		if (s3[i] == s4[i])
			i++;
		else
			return (0);
	}
	return (1);
}
