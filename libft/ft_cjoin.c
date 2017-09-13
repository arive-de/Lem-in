/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:02:44 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 10:50:42 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cjoin(char *str, char c2)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = ft_strnew(len + 256);
	new = ft_strcpy(new, str);
	new[len] = c2;
	free(str);
	return (new);
}
