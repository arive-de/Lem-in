/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:07:25 by arive-de          #+#    #+#             */
/*   Updated: 2016/11/14 11:15:31 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		only_white(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t k;
	size_t i;
	size_t len;

	i = 0;
	if (!s)
		return (NULL);
	if (only_white((char*)s) == 1)
		return (ft_strdup(""));
	len = ft_strlen((char*)s);
	k = len - 1;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
	{
		k--;
		len--;
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		len--;
	}
	return (ft_strsub(s, i, len));
}
