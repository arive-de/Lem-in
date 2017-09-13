/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:46:57 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/05 15:54:22 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*multi_fd(const int fd, t_list **alst)
{
	t_list		*lst;
	t_list		*tmp;
	t_gnl		elem;

	lst = *alst;
	tmp = lst;
	while (lst)
	{
		if (fd == ((t_gnl*)(lst->content))->fd)
			return ((t_gnl*)(lst->content));
		tmp = lst;
		lst = lst->next;
	}
	elem.fd = fd;
	elem.str = NULL;
	if (!tmp)
	{
		if (!(*alst = ft_lstnew(&elem, sizeof(t_gnl))))
			return (NULL);
		return ((t_gnl*)(*alst)->content);
	}
	if (!(tmp->next = ft_lstnew(&elem, sizeof(t_gnl))))
		return (NULL);
	return ((t_gnl*)tmp->next->content);
}

size_t	ft_str_backn(char *line)
{
	size_t i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

char	*ft_stock_end(char *line)
{
	size_t		i;
	size_t		len;
	char		*dest;

	i = ft_str_backn(line);
	len = ft_strlen(line);
	if (!len || (len == 1 && i == 0))
		return (ft_strnew(0));
	dest = ft_strdup(line + ((i == len) ? i : i + 1));
	return (dest);
}

int		ft_read_line(int fd, char **tmp)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		flag;
	char	*erase;

	ret = 1;
	flag = 0;
	while (flag == 0 && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		erase = *tmp;
		*tmp = (!*tmp ? ft_strdup(buf) : ft_strjoin(*tmp, buf));
		free(erase);
		if (ft_strchr(*tmp, '\n') != NULL)
			flag++;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_gnl			*tmp;
	char			*rase;
	int				ret;

	ret = 0;
	if (fd < 0 || !(tmp = multi_fd(fd, &lst)))
		return (-1);
	if (tmp->str && (ft_strchr(tmp->str, '\n') != NULL))
		ret = 1;
	if ((tmp->str && ft_strchr(tmp->str, '\n') == NULL) || !tmp->str)
		ret = ft_read_line(tmp->fd, &tmp->str);
	if (ret == -1)
		return (-1);
	if (!tmp->str)
		return (0);
	*line = ft_strsub(tmp->str, 0, ft_str_backn(tmp->str));
	rase = tmp->str;
	tmp->str = ft_stock_end(tmp->str);
	free(rase);
	return (ft_strlen(*line) == 0 && ret == 0 ? 0 : 1);
}
