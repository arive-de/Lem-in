/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:48:52 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/05 16:13:27 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_word(char *src, char c, int j)
{
	int len;

	len = 0;
	while (src[j] == c)
		j++;
	while (src[j] && src[j] != c)
	{
		len++;
		j++;
	}
	return (len);
}

static int		ft_word(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	int		nb_word;
	char	**tab;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	nb_word = ft_word((char*)s, c);
	tab = (char**)malloc(sizeof(char*) * (nb_word + 1));
	if (!tab)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i] && nb_word-- > 0)
	{
		if (s[i] != c)
			tab[k++] = ft_strsub(s, i, (len_word((char*)s, c, i)));
		i = i + (len_word((char*)s, c, i));
		while (s[i] == c)
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
