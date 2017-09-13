/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:04:33 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/10 18:08:37 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	char	*s3;
	char	*s4;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s3 = (char*)s1;
	s4 = (char*)s2;
	while (s3[i] && s4[i] && (s3[i] == s4[i]))
		i++;
	if ((s3[i] - s4[i]) == 0)
		return (1);
	else
		return (0);
}
