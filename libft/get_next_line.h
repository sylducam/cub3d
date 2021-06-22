/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:13:06 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/11 13:08:32 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 64

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

size_t		ft_strlen_gnl(const char *s);
int			find_nl(const char *s);
size_t		ft_strlcpy_gnl(char *dest, const char *src, size_t dstsize);
int			check_args(int fd);
int			transfer_line(char **current, char **line);
int			read_fd(int fd, char **current, char **line);
int			get_next_line(int fd, char **line);

#endif
