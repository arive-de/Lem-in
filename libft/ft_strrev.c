/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:20:12 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/18 10:44:41 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	size--;
	while (i < size)
	{
		tmp = str[size];
		str[size] = str[i];
		str[i] = tmp;
		i++;
		size--;
	}
	return (str);
}
