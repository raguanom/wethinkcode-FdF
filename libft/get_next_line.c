/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:47:18 by raguanom          #+#    #+#             */
/*   Updated: 2017/09/05 14:43:58 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cbuf(char **str, char *buf, char **line)
{
	if ((*str = ft_strchr(buf, '\n')) != NULL)
	{
		*str = ft_strsub(buf, ft_strlen(buf)
				- ft_strlen(*str), ft_strlen(*str)) + 1;
		if (*line)
			*line = ft_strjoin(*line, ft_strsub(buf, 0, ft_strlen(buf)
						- ft_strlen(*str) - 1));
		else
			*line = ft_strdup(ft_strsub(buf, 0, ft_strlen(buf)
						- ft_strlen(*str) - 1));
		return (1);
	}
	if (*line)
		*line = ft_strjoin(*line, buf);
	else
		*line = ft_strdup(buf);
	return (0);
}

char	*remain(char **line, char *str)
{
	char	*tmp;
	int		size;

	tmp = str;
	if ((tmp = ft_strchr(str, '\n')) != NULL)
	{
		*tmp = '\0';
		size = ft_strlen(str);
		*tmp = '\n';
		*line = ft_strsub(str, 0, size);
		return (str + size);
	}
	*line = ft_strdup(str);
	return (str + ft_strlen(str));
}

int		get_next_line(int const fd, char **line)
{
	static char		*str;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (str)
	{
		str = remain(line, str);
		if (*str == '\n')
		{
			str++;
			return (1);
		}
	}
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if ((cbuf(&str, buff, line)) == 1)
			return (1);
	}
	return (0);
}