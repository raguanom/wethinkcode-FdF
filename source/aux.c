/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:30:51 by raguanom          #+#    #+#             */
/*   Updated: 2017/11/20 10:27:07 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				get_num_lines(char *file_name)
{
	int		num_lines;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	num_lines = 0;
	while ((get_next_line(fd, &line)) > 0)
		num_lines++;
	close(fd);
	return (num_lines);
}

int				get_num_points(char *file_name, char **str, char *line)
{
	int		fd;
	int		num_points;
	int		i;

	fd = open(file_name, O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		num_points = 0;
		str = ft_strsplit(line, ' ');
		i = -1;
		while (str[++i] != 0)
			num_points++;
	}
	i = -1;
	while (str[++i] != 0)
		ft_memdel(((void *)&str[i]));
	free(str);
	return (num_points);
}

void			store_data(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->points[i][j].col = ((((j + 1) * map->scale) +
						(2.5 * i / map->bend))) + map->deltax;
			map->points[i][j].row = (((i + 1) * map->scale) -
					(map->scale * j)) + map->deltay - (0.5 *
						(map->points[i][j].z * 10));
			j++;
		}
		i++;
	}
}

t_map			*get_points_array(size_t rows, size_t cols, t_map *map)
{
	int			i;

	if (!(map->points = (t_points**)malloc(sizeof(t_points*) * rows)))
		return (NULL);
	i = 0;
	while ((size_t)i < rows)
	{
		if (!(map->points[i] = (t_points*)malloc(sizeof(t_points) * cols)))
			return (NULL);
		i++;
	}
	return (map);
}

void			get_points(t_map *map)
{
	char		**str;
	char		*line;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (get_next_line(map->fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		k = -1;
		j = -1;
		while (str[++k] != 0)
			map->points[i][++j].z = ft_atoi(str[k]);
		k = -1;
		store_data(map);
		while (str[++k] != 0)
			ft_strdel(&str[k]);
		free(str);
		i++;
	}
}
