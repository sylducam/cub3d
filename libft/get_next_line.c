/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:12:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/14 17:46:07 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strjoin_gnl(char **s1, char const *s2, int limit)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = wrmalloc(sizeof(char) * (ft_strlen_gnl(*s1) + ft_strlen_gnl(s2) + 1));
	if (res == 0)
		return (-1);
	while (*s1 != 0 && (*s1)[i])
	{
		res[i] = (*s1)[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 != 0 && s2[i] && i < limit)
		res[j++] = s2[i++];
	res[j] = '\0';
	wrfree(*s1);
	*s1 = res;
	return (1);
}

static int	ft_substr_gnl(char **s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	sub = NULL;
	if (*s == NULL)
		return (-1);
	if (ft_strlen_gnl(*s) < len)
		len = ft_strlen_gnl(*s);
	sub = wrmalloc(sizeof(char) * (len + 1));
	if (sub == 0)
		return (-1);
	while ((*s)[i + start] && i < len)
	{
		sub[i] = (*s)[i + start];
		i++;
	}
	sub[i] = 0;
	wrfree(*s);
	*s = sub;
	return (1);
}

int	transfer_line(char **current, char **line)
{
	int	i_nl;
	int	len_rest;
	int	len_current;

	len_current = ft_strlen_gnl(*current);
	i_nl = find_nl(*current);
	if (i_nl == -1)
		i_nl = len_current;
	*line = wrmalloc(sizeof(char) * (i_nl + 1));
	if (*line == 0)
		return (-1);
	if (current == 0 || len_current == 0)
	{
		**line = 0;
		return (0);
	}
	ft_strlcpy_gnl(*line, *current, (i_nl + 1));
	len_rest = len_current - i_nl;
	if (len_rest <= 0)
		return (0);
	return (ft_substr_gnl(current, (i_nl + 1), len_rest));
}

int	read_fd(int fd, char **current, char **line)
{
	int		status;
	char	buffer[BUFFER_SIZE + 1];

	status = 1;
	while (find_nl(*current) == -1 && status > 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status > 0)
		{
			buffer[status] = '\0';
			status = ft_strjoin_gnl(current, buffer, (status + 1));
			if (status == -1)
				return (-1);
		}
	}
	if (status == -1)
		return (-1);
	status = transfer_line(current, line);
	return (status);
}

int	get_next_line(int fd, char **line)
{
	static char	*current;
	int			status;

	if (line == NULL)
		return (-1);
	if (check_args(fd) == 0)
	{
		*line = NULL;
		return (-1);
	}
	status = read_fd(fd, &current, line);
	if (status < 1 && current != NULL)
	{
		wrfree(current);
		current = NULL;
	}
	return (status);
}
